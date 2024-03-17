#include "../headers/Game.h"

Game::Game(std::string playerName):player_(playerName), running_(true), canFight_(false), canLoot_(false), nbEntities_(0), nbObjects_(0), playerChoice_(Action::HOME)
{
    Tile* t = new Tile(0,0, true);
    map_.addTile(t);
    map_.setCurrentTile(t);
    map_.getCurrentTile()->getGroup()->addPlayer(player_);
    itemNames_.push_back(Const::Default::ARMOR_NAME);
    itemNames_.push_back(Const::Default::WEAPON_NAME);
    entityNames_.push_back(playerName);
}

Game::~Game()
{
}

void Game::loop(){
    while (running_)
    {
        // main menu
        std::string text;
        map_.setCurrentTile(map_.getTile(player_.getX(), player_.getY()));
        auto currentTile = map_.getCurrentTile();
        if (Str::capitalize(playerChoice_) == Action::HOME)
        {
            text = "\nAction :\n- Info \n- Move \n- Stuff \n- Crafting";
            if (!currentTile->isAlone())
            {
                canFight_ = true;
                text += "\n- Fight";
            }else{
                canFight_ = false;
            }
            if (currentTile->getStorage()->size() > 0)
            {
                canLoot_ = true;
                text += "\n- Loot";
            }else{
                canLoot_ = false;
            }
            text += "\n- Create";
            text += "\n- Exit\n->";
            
            std::cout << text;
            playerChoice_ = input();
        }
        playerChoice_ = Str::autocomplete({Action::ALL}, playerChoice_);
        // informations
        if (playerChoice_ == Action::Info::SELF)
        {
            text = "\nInfo :\n- Tile\n- Player \n- Inventory \n- Weapon equiped \n- equiped Armor \n- Back\n->";
            std::cout << text;
            std::string infoChoice = input();
            infoChoice = Str::autocomplete(Action::Info::KEY_WORDS, Str::capitalize(infoChoice));

            if (infoChoice == Action::Info::PLAYER)
            {
                std::cout << player_.info();
            }
            else if (infoChoice == Action::Info::INVENTORY)
            {
                std::cout << player_.getInventory()->info();
            }
            else if (infoChoice == Action::Info::WEAPON)
            {
                std::cout << player_.getWeapon()->info();
            }
            else if (infoChoice == Action::Info::ARMOR)
            {
                std::cout << player_.getArmor()->info();
            }
            else if (infoChoice == Action::Info::TILE)
            {
                std::cout << currentTile->info();
            }
            else
            {
                playerChoice_ = Action::HOME;
            }
        }
        // movement
        else if (playerChoice_ == Action::Move::SELF)
        {
            text = "\nMove to: Up - Down - Left - Right - Back\n->";
            std::cout << text;
            std::string moveChoice = input();
            moveChoice = Str::capitalize(moveChoice);
            
            if (Str::isIn(moveChoice, Key::FR::KEY_WORDS))
            {
                map_.movement(moveChoice);
                std::cout << map_.getCurrentTile()->info();
            }else
            {
                playerChoice_ = Action::HOME;
            }
        }
        // stuffing
        else if(playerChoice_ == Action::Stuff::SELF){
            Inventory* invent = player_.getInventory();

            bool thereIsWeapon = (invent->nbWeapons() > 0) ? true : false;
            bool thereIsArmor = (invent->nbArmors() > 0) ? true : false;
            bool weaponEquiped = player_.hasWeaponEquipped();
            bool armorEquiped = player_.hasArmorEquipped(); 
            
            std::cout << player_.getWeapon()->info();
            std::cout << player_.getArmor()->info();
            std::cout << invent->info();
            
            std::string text("Action : ");
            
            if (thereIsWeapon)
            {
                text += "\n- Equip Weapon";
            }
            if (thereIsArmor)
            {
                text += "\n- Equip Armor";
            }
            if (weaponEquiped)
            {
                text += "\n- Unequip Weapon";
            }
            if (armorEquiped)
            {
                text += "\n- Unequip Armor";
            }
            text += "\n- Exit\n->";
            std::cout << text;

            std::string stuffChoice = Str::autocomplete(Action::Stuff::KEY_WORDS, input());

            if (thereIsWeapon && stuffChoice == Action::Stuff::EQUIP_WEAPON)
            {

                std::cout << "What do you want to equip ?\nEnter the weapon's name.\n";
                for (auto it : invent->getWeapons())
                {
                    std::cout << it->info();
                }
                std::cout << "=>";
                std::string itemChoice = input();

                Object* item = player_.getInventory()->getItemByName(itemChoice);
                
                Weapon* it = dynamic_cast<Weapon*>(item);
                if (it)
                {
                    player_.equipWeapon(it);
                    std::cout << "Weapon equipped\n";
                }
            }else if (thereIsArmor && stuffChoice == Action::Stuff::EQUIP_ARMOR)
            {

                std::cout << "What do you want to equip ?\nEnter the armor's name.\n";
                for (auto it : invent->getArmors())
                {
                    std::cout << it->info();
                }
                std::cout << "=>";
                std::string itemChoice = input();

                Object* item = player_.getInventory()->getItemByName(itemChoice);
                
                Armor* it = dynamic_cast<Armor*>(item);
                if (it)
                {
                    player_.equipArmor(it);
                    std::cout << "Armor equipped\n";
                }
            }else if (weaponEquiped && stuffChoice == Action::Stuff::UNEQUIP_WEAPON)
            {
                player_.unequipWeapon();
            }else if (armorEquiped && stuffChoice == Action::Stuff::UNEQUIP_ARMOR)
            {
                player_.unequipArmor();
            }else{
                playerChoice_ = Action::HOME;
            }
        }
        // crafting
        else if (playerChoice_ == Action::Crafting::SELF)
        {
            
            
        }
        
        // fighting
        else if (canFight_ && playerChoice_ == Action::Fight::SELF)
        {
            /* steps :
             turn by turn
             player attack first
             then each monster on the tile
             player can do  :
            - normal attack 
            - strong attack
            - swap weapon or armor
            - escape fight
            */
            std::cout << "Action : Attack - Strong Attack - Swap Weapon - Swap Armor - Escape\n=> ";
            std::string actionChoice = Str::autocomplete(Action::Fight::KEY_WORDS, input());

            if (actionChoice == Action::Fight::ATTACK)
            {
                auto targets = map_.getCurrentTile()->getGroup();
                if (targets->size() == 1)
                {
                    targets->getPlayer()->attack(*std::get<1>(targets->getEnemies().at(0)));
                }else
                {
                    std::cout << targets->info() << "Which enemy to attack ?\n=> ";
                    std::vector<std::string> names;
                    for (auto elt : targets->getEnemies())
                    {
                        names.push_back(std::get<1>(elt)->getName());
                    }
                    std::string enemyChoice = Str::autocomplete(names, input());

                    targets->getPlayer()->attack(*std::get<1>(*targets->getElt(enemyChoice)));
                }
            }else if (actionChoice == Action::Fight::SWAP_WEAPON)
            {
                // get all weapons in the inventory
                auto weaponsList = player_.getInventory()->getWeapons();
                // if only one weapon
                if (weaponsList.size() == 1)
                {
                    // switch with this unique weapon
                    player_.equipWeapon(weaponsList[0]);
                }
                // if more than 1 possibilities
                else if (weaponsList.size() > 1)
                {
                    std::vector<std::string> weaponNames;
                    for (auto weapon : weaponsList)
                    {
                        // get a list with weapon names
                        weaponNames.push_back(weapon->getName());
                        // display all names
                        std::cout << weapon->getName() << std::endl;
                    }
                    std::cout << "Enter the weapon name which switch with : ";
                    // ask the weapon name targeted
                    std::string weaponName = Str::autocomplete(weaponNames, input());
                    if (weaponName != "")
                    {
                        Weapon* buffer = dynamic_cast<Weapon*>(player_.getInventory()->getItemByName(weaponName));
                        if (buffer)
                        {
                            player_.equipWeapon(buffer);
                        }
                    }
                }
            }else if (actionChoice == Action::Fight::SWAP_ARMOR)
            {
                // get all armors in the inventory
                auto armorsList = player_.getInventory()->getArmors();
                // if only one armor
                if (armorsList.size() == 1)
                {
                    // switch with this unique armor
                    player_.equipArmor(armorsList[0]);
                }
                // if more than 1 possibilities
                else if (armorsList.size() > 1)
                {
                    std::vector<std::string> armorNames;
                    for (auto armor : armorsList)
                    {
                        // get a list with armor names
                        armorNames.push_back(armor->getName());
                        // display all names
                        std::cout << armor->getName() << std::endl;
                    }
                    std::cout << "Enter the armor name which switch with : ";
                    // ask the armor name targeted
                    std::string armorName = Str::autocomplete(armorNames, input());
                    if (armorName != "")
                    {
                        Armor* buffer = dynamic_cast<Armor*>(player_.getInventory()->getItemByName(armorName));
                        if (buffer)
                        {
                            player_.equipArmor(buffer);
                        }
                    }
                }
            }else{
                playerChoice_ = Action::HOME;
            }
        }
        // looting
        else if (canLoot_ && playerChoice_ == Action::Loot::SELF)
        {
            std::cout << map_.getCurrentTile()->getStorage()->info();
            std::cout << "What do you want to pick up ?\nEnter the item's name.\n=>";
            std::string lootChoice = input();
            
            if (Str::isIn(Str::capitalize(lootChoice), {"","Back"}))
            {
                playerChoice_ = Action::HOME; 
            }else{
                // get the elt
                auto item = map_.getCurrentTile()->getStorage()->getItemByName(lootChoice);
                
                // if found
                if (item != nullptr)
                {
                    std::cout << "how many ?\n=>";
                    int stackChoice = inputInt(1);
                    // regulize the stack
                    int maxStack = map_.getCurrentTile()->getStorage()->getStackItem(lootChoice);
                    // if number ask is over number of items stacked : get max, else get the wished number
                    int pickStack = stackChoice >= maxStack ? maxStack : stackChoice;
                    // add to player's stuff
                    player_.getInventory()->addItem(item, pickStack);
                    //  remove from the tile's stuff
                    map_.getCurrentTile()->getStorage()->removeItem(item->getName(), stackChoice);
                    // map_.getCurrentTile()->getStorage()->removeItem(item->getName(), stackChoice);
                    std::cout << "Looting done\n";

                    if (map_.getCurrentTile()->getStorage()->isEmpty())
                    {
                        playerChoice_ = Action::HOME;
                        canLoot_ = false;
                    }else {
                        playerChoice_ = Action::Loot::SELF;
                    }
                }else{
                    std::cout << "Looting failed\n";
                    playerChoice_ = Action::Loot::SELF;
                }
            }
        }
        // creation
        else if (playerChoice_ == Action::Create::SELF)
        {
            std::cout << "Create : Weapon - Armor - Object - Enemy - Back\n";

            std::string createChoice = Str::autocomplete(Action::Create::KEY_WORDS, input());

            if (createChoice == Action::Create::WEAPON)
            {
                
                handleCreateWeapon(currentTile->getStorage());
                
            }else if (createChoice == Action::Create::ARMOR)
            {
                
                handleCreateArmor(currentTile->getStorage());
                
            }else if (createChoice == Action::Create::OBJECT)
            {
                
                handleCreateObject(currentTile->getStorage());

            }else if (createChoice == Action::Create::ENEMY)
            {
                handleCreateEntity(currentTile->getGroup());
            }else{
                playerChoice_ = Action::HOME;
            }
        }
        // exit game
        else
        {
            running_ = false;
        }
    }
}
std::string Game::input(){
    std::string buff;
    getline(std::cin, buff);
    return buff;
}

int Game::inputInt(int defaultValue){
    std::string buff;
    int buffInt;
    getline(std::cin, buff);

    try
    {
        buffInt = std::stoi(buff);
    }
    catch(const std::exception& e)
    {
        buffInt = defaultValue;
    }

    return buffInt;
}

void Game::handleCreateWeapon(Inventory* invent){
    std::string weaponName;
    do
    {
        std::cout << "Enter name : ";
        weaponName = input();
    } while (weaponName.size() < 2);

    int damage;
    do
    {
        std::cout << "Enter damage value(>0) : ";
        damage = inputInt(Const::Default::WEAPON_DAMAGE);
    } while (damage < 1);
    
    
    int penetration;
    do
    {
        std::cout << "Enter penetration value(0-damage) : ";
        penetration = inputInt(Const::Default::WEAPON_LETHALITY);
    } while (penetration > damage && penetration < 0);
    
        
    
    int vampirism;
    do
    {
        std::cout << "Enter vampirism value(0-100) : ";
        vampirism = inputInt(Const::Default::WEAPON_VAMPIRISM);
    } while (vampirism < 0 && vampirism > 100);

    int stack;
    do
    {
        std::cout << "Enter stack value( >=1) : ";
        stack = inputInt(1);
    } while (stack < 1);
    

    std::cout << "Weapon created \n";
    invent->addItem(new Weapon(weaponName, damage, penetration, vampirism), stack);
    ++nbObjects_;
    
    playerChoice_ = Action::Create::SELF;
}

void Game::handleCreateArmor(Inventory* invent){
    std::string armorName;
    do
    {
        std::cout << "Enter name : ";
        armorName = input();
    } while (armorName.size() < 2);

    int defense;
    do
    {
        std::cout << "Enter defense value(>0) : ";
        defense = inputInt(Const::Default::ARMOR_DEFENSE);
    } while (defense < 1);
    
    
    int thorns;
    do
    {
        std::cout << "Enter thorns value(0-100) : ";
        thorns = inputInt(Const::Default::WEAPON_LETHALITY);
    } while (thorns > 100 && thorns < 0);
    
        
    
    int regeneration;
    do
    {
        std::cout << "Enter regeneration value(0-100) : ";
        regeneration = inputInt(Const::Default::ARMOR_REGENERATION);
    } while (regeneration < 0 && regeneration > 100);

    int stack;
    do
    {
        std::cout << "Enter stack value( >=1) : ";
        stack = inputInt(1);
    } while (stack < 1);

    std::cout << "Armor created \n";
    invent->addItem(new Armor(armorName, defense, thorns, regeneration), stack);
    ++nbObjects_;

    itemNames_.push_back(armorName);
    
    playerChoice_ = Action::Create::SELF;
}

void Game::handleCreateObject(Inventory* invent){
    std::string name;
    do
    {
        std::cout << "Enter name : ";
        name = input();
    } while (name.size() < 2);

    int stack;
    do
    {
        std::cout << "Enter stack value( >=1) : ";
        stack = inputInt(1);
    } while (stack < 1);

    std::cout << "Object created \n";
    invent->addItem(new Object(name), stack);
    ++nbObjects_;

    itemNames_.push_back(name);
    
    playerChoice_ = Action::Create::SELF;
}

void Game::handleCreateEntity(Group* team){
    std::string entityName;
    do
    {
        std::cout << "Enter the name : ";
        entityName = input();
    } while (entityName.size() <= 2 );
    

    Entity* newEntity = new Entity(entityName, map_.getCurrentTile()->getX(), map_.getCurrentTile()->getY());

    std::string weaponName, armorName;
    int damage, penetration, vampirism;
    int defense, thorns, regeneration;
    
    std::cout << "Add a weapon to the inventory (y/n) ?";
    std::string weaponChoice = input();

    if (Str::autocomplete(Const::Response::ALL, weaponChoice) == Const::Response::YES)
    {
        do
        {
            handleCreateWeapon(newEntity->getInventory());

            std::cout << "equip this weapon ?(y/n)";
            if (Str::autocomplete(Const::Response::ALL, input()) == Const::Response::YES)
            {
                newEntity->equipWeapon(new Weapon(weaponName, damage, penetration, vampirism));
            }

            std::cout << "Create another weapon ?(y/n)";
            weaponChoice = input();
        } while (Str::isIn(Str::capitalize(weaponChoice),{"y","yes"}));
    }
    
    std::cout << "Add a armor to the inventory (y/n) ?";
    std::string armorChoice = input();
    if (Str::autocomplete(Const::Response::ALL, armorChoice) == Const::Response::YES){
        do
        {
            handleCreateArmor(newEntity->getInventory());

            std::cout << "equip this armor ?(y/n)";
            if (Str::isIn(Str::capitalize(input()),{"y","yes"}))
            {
                newEntity->equipArmor(new Armor(armorName, defense, thorns, regeneration));
            }else{
                newEntity->getInventory()->addItem(new Armor(armorName, defense, thorns, regeneration));
            }
            
            std::cout << "Create another armor ?(y/n)";
            armorChoice = input();
        } while (Str::autocomplete(Const::Response::ALL, armorChoice) == Const::Response::YES);
    }
    rd_.setBorder(1,50);
    newEntity->getInventory()->addItem(new Object("Gold"), rd_.getRandomNumber());

    team->addEnemy(newEntity);
    ++nbEntities_;
    entityNames_.push_back(entityName);

    std::cout << "Entity created.\n";
}

void generateRandomItem(Inventory* chest){
    Random rd(0,2);
    int buff = rd.getRandomNumber();
    // add a weapon
    if (buff == 0)
    {
        rd.setBorder(1,50);
        int damage = rd.getRandomNumber();
        rd.setBorder(1,damage);
        int letha = rd.getRandomNumber();
        rd.setBorder(0,letha);
        int vamp = rd.getRandomNumber();
        chest->addItem(new Weapon("Sword", damage, letha, vamp));
    }
    // add a armor
    else if (buff == 1)
    {
        rd.setBorder(1,50);
        int def = rd.getRandomNumber();
        rd.setBorder(1,def);
        int thorns = rd.getRandomNumber();
        rd.setBorder(0,thorns);
        int regen = rd.getRandomNumber();
        chest->addItem(new Armor("Orix", def, thorns, regen));
    }
    // add a object
    else if (rd.getRandomNumber() == 2)
    {
        rd.setBorder(1,20);
        chest->addItem(new Object("Gold"), rd.getRandomNumber());
    }
}