#include "../headers/Game.h"

Game::Game(std::string playerName):player_(playerName), running_(true), canFight_(false), canLoot_(false), nbEntities_(0), nbObjects_(0), playerChoice_("")
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
        if (lower(playerChoice_) == "")
        {
            text = "\nAction : Info - Move - Stuff";
            if (!currentTile->isAlone())
            {
                canFight_ = true;
                text += " - Fight";
            }else{
                canFight_ = false;
            }
            if (currentTile->getStorage()->size() > 0)
            {
                canLoot_ = true;
                text += " - Loot";
            }else{
                canLoot_ = false;
            }
            text += " - Create";
            text += " - Exit\n->";
            
            std::cout << text;
            playerChoice_ = input();
            playerChoice_ = lower(playerChoice_);
        }

        // info
        if (isIn(lower(playerChoice_), {"i", "info"}))
        {
            text = "\nInfo : Tile - Player - Inventory - equiped Weapon - equiped Armor - Back\n->";
            std::cout << text;
            std::string infoChoice = input();
            infoChoice = lower(infoChoice);

            if (isIn(lower(infoChoice), {"p", "player"}))
            {
                std::cout << player_.info();
            }
            else if (isIn(lower(infoChoice),{"i", "inventory"}))
            {
                std::cout << player_.getInventory()->info();
            }
            else if (isIn(lower(infoChoice),{"w", "weapon"}))
            {
                std::cout << player_.getWeapon()->info();
            }
            else if (isIn(lower(infoChoice),{"a","armor"}))
            {
                std::cout << player_.getArmor()->info();
            }
            else if (isIn(lower(infoChoice),{"t", "tile"}))
            {
                std::cout << currentTile->info();
            }
            else
            {
                playerChoice_ = "";
            }
        }
        // movement
        else if (isIn(lower(playerChoice_), {"m","move"}))
        {
            text = "\nMove to: Up - Down - Left - Right - Back\n->";
            std::cout << text;
            std::string moveChoice = input();
            moveChoice = lower(moveChoice);
            
            if (isIn(moveChoice, Key::FR::KEYS))
            {
                map_.movement(moveChoice);
            }else
            {
                playerChoice_ = "";
            }
        }
        // stuffing
        else if(isIn(lower(playerChoice_), {"s","stuff"})){
            Inventory* invent = player_.getInventory();
            std::cout << player_.getWeapon()->info();
            std::cout << player_.getArmor()->info();
            std::cout << invent->info();
            
            std::string text("Action : ");
            if (invent->nbWeapons() > 0 or invent->nbArmors() > 0)
            {
                text += " Equip";
            }
            if (player_.hasWeaponEquipped() || player_.hasArmorEquipped())
            {
                text += " - Unequip";
            }

            text += " - Exit\n->";
            std::cout << text;

            std::string stuffChoice = input();

            if (isIn(lower(stuffChoice),{"e","equipp"}))
            {

                std::cout << "What do you want to equip ?\nEnter the weapon/armor name.\n" << player_.getInventory()->info() << "=>";
                std::string itemChoice = input();

                auto item = player_.getInventory()->getItem(itemChoice);
                
                Weapon* w = dynamic_cast<Weapon*>(item);
                if (w)
                {
                    player_.equipWeapon(w);
                    std::cout << "Item equipped\n";
                }else{
                    Armor* a = dynamic_cast<Armor*>(item);
                    if (a)
                    {
                        player_.equipArmor(a);
                        std::cout << "Item equipped\n";
                    }else{
                        std::cout << "This item is not equipable\n";
                    }
                }
            }
            else if (isIn(lower(stuffChoice), {"u","unequipp"}))
            {
                std::string text = "Unequip : ";
                if (player_.hasWeaponEquipped())
                {
                    text += "Weapon";
                }
                if (player_.hasArmorEquipped())
                {
                    if (player_.hasWeaponEquipped())
                    {
                        text += " - ";
                    }
                    
                    text += "Armor";
                }
                text += " - Back\n";

                std::cout << text;
                std::string tmp = input();

                if (isIn(lower(tmp), {"w","weapon"}))
                {
                    player_.unequipWeapon();
                }
                else if (isIn(lower(tmp), {"a","armor"}))
                {
                    player_.unequipArmor();
                }                
            }
            
            playerChoice_ = "s";
            
        }
        // fighting
        else if (canFight_ && isIn(lower(playerChoice_), {"f","fight"}))
        {
            text = "\nFight : Attack";
            text += " - Escape\n->";
            std::cout << text;

            std::string fightChoice = input();

            Entity* target;
            if (isIn(lower(fightChoice), {"a", "attack"}))
            {
                // get all enemy on the tile
                auto ennemies = currentTile->getGroup()->getEnemies();
                if (ennemies.size() != 0)
                {
                    if (ennemies.size() == 1)
                    {
                        target = ennemies.at(0);
                    }else{
                        // display ennemies name/id
                        std::string text("Enter the name of the enemy you want to attack :\n");
                        for(auto elt : ennemies){
                            text += elt->getName() + "\n";
                        }
                        std::cout << text;

                        // get player choice
                        std::string ennemyChoice = input();
                        ennemyChoice = lower(ennemyChoice);

                        //get the target
                        target = currentTile->getGroup()->getEnemy(ennemyChoice);
                    }
                    
                    // attack the choosen enemy
                    std::cout << player_.attack(*target);
                    
                    // if enemy is dead
                    if (!target->isAlive())
                    {
                        
                        if (target->getWeapon()->getName() != Const::Default::WEAPON_NAME)
                        {
                            currentTile->getStorage()->addItem(target->getWeapon());
                        }
                        if (target->getArmor()->getName() != Const::Default::ARMOR_NAME)
                        {
                            currentTile->getStorage()->addItem(target->getArmor());
                        }
                        
                        for(auto item : target->getInventory()->getItems()){
                            currentTile->getStorage()->addItem(item);
                        }
                        
                        currentTile->getGroup()->removeEnemy(target->getName());

                        playerChoice_ = "";
                    }
                }else{
                    std::cout << "There is no enemy on this tile\n";
                }
            }
            else if (isIn(lower(fightChoice), {"e", "escape"}))
            {
                playerChoice_ = "";
            }
            else
            {
                playerChoice_ = "";
            }            
        }
        // looting
        else if (canLoot_ && isIn(lower(playerChoice_),{"l","loot"}))
        {
            std::cout << "What do you want to pick up ?\nEnter the item's name.\n\n";
            std::cout << map_.getCurrentTile()->getStorage()->info();
            std::cout << "=>";
            std::string lootChoice = input();

            auto item = map_.getCurrentTile()->getStorage()->getItem(lootChoice);
            
            if (item != nullptr)
            {
                std::cout << "Looting done\n";
                player_.getInventory()->addItem(item);
                map_.getCurrentTile()->getStorage()->removeItem(item->getName());

                playerChoice_ = (map_.getCurrentTile()->getStorage()->isEmpty()) ? "" : "l";
            }else{
                std::cout << "Looting failed\n\n";
                playerChoice_ = "l";
            }
            
        }
        else if (isIn(lower(playerChoice_),{"crafting"}))
        {
            
        }
        // creation
        else if (isIn(lower(playerChoice_), {"c", "create"}))
        {
            std::cout << "Create : Weapon - Armor - Object - Enemy - Back\n";

            std::string createChoice = input();

            if (isIn(lower(createChoice),{"w","weapon"}))
            {
                
                handleCreateWeapon(currentTile->getStorage());
                
            }else if (isIn(lower(createChoice),{"a","armor"}))
            {
                
                handleCreateArmor(currentTile->getStorage());
                
            }else if (isIn(lower(createChoice),{"o","object"}))
            {
                
                handleCreateObject(currentTile->getStorage());

            }else if (isIn(lower(createChoice),{"e","enemy"}))
            {
                handleCreateEntity(currentTile->getGroup());
            }else{
                playerChoice_ = "";
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
    } while (!isIn(weaponName, itemNames_) && weaponName.size() > 1);

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

    std::cout << "Weapon created \n";
    invent->addItem(new Weapon(weaponName, damage, penetration, vampirism));
    ++nbObjects_;

    itemNames_.push_back(weaponName);
    
    playerChoice_ = "c";
}

void Game::handleCreateArmor(Inventory* invent){
    std::string armorName;
    do
    {
        std::cout << "Enter name : ";
        armorName = input();
    } while (!isIn(armorName, itemNames_) && armorName.size() > 1);

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

    std::cout << "Armor created \n";
    invent->addItem(new Armor(armorName, defense, thorns, regeneration));
    ++nbObjects_;

    itemNames_.push_back(armorName);
    
    playerChoice_ = "c";
}

void Game::handleCreateObject(Inventory* invent){
    std::string name;
    do
    {
        std::cout << "Enter name : ";
        name = input();
    } while (name.size() > 2 && !isIn(name, Const::Reserved::NAMES));

    std::cout << "Object created \n";
    invent->addItem(new Object(name));
    ++nbObjects_;

    itemNames_.push_back(name);
    
    playerChoice_ = "c";
}

void Game::handleCreateEntity(Group* team){
    std::string entityName;
    do
    {
        std::cout << "Enter the name : ";
        entityName = input();
    } while (entityName.size() > 2 && !isIn(entityName, Const::Reserved::NAMES));
    

    Entity* newEntity = new Entity(entityName, map_.getCurrentTile()->getX(), map_.getCurrentTile()->getY());

    std::string weaponName, armorName;
    int damage, penetration, vampirism;
    int defense, thorns, regeneration;
    
    std::cout << "Add a weapon to the inventory (y/n) ?";
    std::string weaponChoice = input();

    if (isIn(lower(weaponChoice),{"y","yes"}))
    {
        do
        {
            handleCreateWeapon(newEntity->getInventory());

            std::cout << "equip this weapon ?(y/n)";
            if (isIn(lower(input()),{"y","yes"}))
            {
                newEntity->equipWeapon(new Weapon(weaponName, damage, penetration, vampirism));
            }else{
                newEntity->getInventory()->addItem(new Weapon(weaponName, damage, penetration, vampirism));
            }

            std::cout << "Create another weapon ?(y/n)";
            weaponChoice = input();
        } while (isIn(lower(weaponChoice),{"y","yes"}));
    }

    std::cout << "Add a armor to the inventory (y/n) ?";
    std::string armorChoice = input();
    if (isIn(lower(armorChoice),{"y","yes"})){
        do
        {
            handleCreateArmor(newEntity->getInventory());

            std::cout << "equip this armor ?(y/n)";
            if (isIn(lower(input()),{"y","yes"}))
            {
                newEntity->equipArmor(new Armor(armorName, defense, thorns, regeneration));
            }else{
                newEntity->getInventory()->addItem(new Armor(armorName, defense, thorns, regeneration));
            }
            
            std::cout << "Create another armor ?(y/n)";
            armorChoice = input();
        } while (isIn(lower(armorChoice), {"y","yes"}));
    }

    team->addEnemy(newEntity);
    ++nbEntities_;
    entityNames_.push_back(entityName);
}