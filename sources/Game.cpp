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
                
                handleCreateWeapon(currentTile);
                
            }else if (isIn(lower(createChoice),{"a","armor"}))
            {
                
                handleCreateArmor(currentTile);
                
            }else if (isIn(lower(createChoice),{"o","object"}))
            {
                
                handleCreateObject(currentTile);

            }else if (isIn(lower(createChoice),{"e","enemy"}))
            {
                handleCreateEntity(currentTile);
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

void Game::handleCreateWeapon(Tile* currentTile){
    std::cout << "Enter name :\n";
    std::string weaponName = input();

    // don't create a new weapon if default weapon
    if (!isIn(weaponName, itemNames_) && weaponName.size() > 1)
    {
        std::cout << "Enter damage value :\n";
        int damage = inputInt(Const::Default::WEAPON_DAMAGE);

        std::cout << "Enter penetration value :\n";
        int penetration = inputInt(Const::Default::WEAPON_LETHALITY);
        
        std::cout << "Enter vampirism value :\n";
        int vampirism = inputInt(Const::Default::WEAPON_VAMPIRISM);
        
        std::cout << "Weapon created \n";
        currentTile->getStorage()->addItem(new Weapon(weaponName, damage, penetration, vampirism));
        ++nbObjects_;
        std::cout << currentTile->info();

        itemNames_.push_back(weaponName);
    }
    playerChoice_ = "c";
}

void Game::handleCreateArmor(Tile* currentTile){
    std::cout << "Enter name :\n";
    std::string armornName = input();

    if (armornName.size() < 2)
    {
        armornName = Const::Default::ARMOR_NAME;
    }

    // don't create a new armor if default name
    if (!isIn(armornName, itemNames_) && armornName.size() > 1)
    {
        std::cout << "Enter protection value :\n";
        int defense = inputInt(Const::Default::ARMOR_DEFENSE);
        
        std::cout << "Enter Thorns value :\n";
        int thorns = inputInt(Const::Default::ARMOR_THORN);
        
        std::cout << "Enter Regeneration value :\n";
        int regeneration = inputInt(Const::Default::ARMOR_REGENERATION);
        
        std::cout << "Armor created \n";
        currentTile->getStorage()->addItem(new Armor(armornName, defense, thorns, regeneration));
        ++nbObjects_;
        std::cout << currentTile->info();

        itemNames_.push_back(armornName);
    }
    playerChoice_ = "c";
}

void Game::handleCreateObject(Tile* currentTile){
    std::cout << "Enter name :\n";
    std::string name = input();

    if (!isIn(name, itemNames_) && name.size() > 1)
    {
        std::cout << "Object created \n";
        currentTile->getStorage()->addItem(new Object(name));
        ++nbObjects_;
        std::cout << currentTile->info();

        itemNames_.push_back(name);
    }
    
    playerChoice_ = "c";
}

void Game::handleCreateEntity(Tile* currentTile){
    std::string entityName;
    std::cout << "Enter the name :\n";
    while (isIn(entityName, entityNames_) || entityName.size() < 2)
    {
        entityName = input();
    }

    // pre create variables 
    std::string weaponName, armorName;
    int damage, penetration, vampirism;
    int defense, thorns, regeneration;
    
    std::cout << "Add a weapon (y/n) ?";
    std::string weaponChoice = input();

    if (isIn(lower(weaponChoice), {"y","yes"}))
    {
        handleCreateWeapon(currentTile);
    }

    std::cout << "Add an armor (y/n) ?";
    std::string armorChoice = input();

    if (isIn(lower(armorChoice), {"y","yes"}))
    {
        handleCreateArmor(currentTile);
    }
    
    currentTile->getGroup()->addEnemy(new Entity(entityName, weaponName, damage, penetration, vampirism, armorName, defense, thorns, regeneration));
    ++nbEntities_;
    entityNames_.push_back(entityName);
    std::cout << currentTile->info();
}