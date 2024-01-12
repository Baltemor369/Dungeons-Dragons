#include "../headers/Game.h"

Game::Game(std::string playerName):player_(playerName), running_(true), canFight_(false), canLoot_(false), turn_(0), nbEntities_(0), nbObjects_(0), playerChoice_("")
{
    Tile* t = new Tile(0,0, true);
    map_.addTile(t);
    map_.setCurrentTile(t);
    map_.getCurrentTile()->getGroup()->addPlayer(player_);
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
            text += "- Create";
            text += " - Exit\n->";
            
            std::cout << text;
            getline(std::cin, playerChoice_);
            playerChoice_ = lower(playerChoice_);
        }

        // menu player info
        if (isIn(lower(playerChoice_), {"i", "info"}))
        {
            text = "\nInfo : Tile - Player - Inventory - equiped Weapon - equiped Armor - Back\n->";
            std::cout << text;
            std::string infoChoice;
            getline(std::cin, infoChoice);
            infoChoice = lower(infoChoice);

            if (isIn(lower(infoChoice), {"p", "player"}))
            {
                std::cout << player_.info();
            }
            else if (isIn(lower(infoChoice),{"rp", "recap player"}))
            {
                std::cout << player_.recap();
            }
            else if (isIn(lower(infoChoice),{"i", "inventory"}))
            {
                std::cout << player_.getInventory()->info();
            }
            else if (isIn(lower(infoChoice),{"ri", "recap inventory"}))
            {
                std::cout << player_.getInventory()->recap();
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
            else if (isIn(lower(infoChoice),{"rt", "recap tile"}))
            {
                std::cout << currentTile->recap();
            }            
            else
            {
                playerChoice_ = "";
            }
        }
        // menu player movement
        else if (isIn(lower(playerChoice_), {"m","move"}))
        {
            text = "\nMove to: Up - Down - Left - Right - Back\n->";
            std::cout << text;
            std::string moveChoice;
            getline(std::cin,  moveChoice);
            moveChoice = lower(moveChoice);
            
            if (isIn(moveChoice, Key::FR_KEYS))
            {
                map_.movement(moveChoice);
                
                ++turn_;
            }else
            {
                playerChoice_ = "";
            }
        }
        // stuff management
        else if(isIn(lower(playerChoice_), {"s","stuff"})){
            Inventory* invent = player_.getInventory();
            std::cout << player_.getWeapon()->info();
            std::cout << player_.getArmor()->info();
            std::cout << invent->info();
            
            std::string text("Action : ");
            if (invent->nbWeapons() > 0 or invent->nbArmors() > 0)
            {
                text += "- Equip";
            }
            if (player_.getArmor()->getName().find(Const::DEFAULT_ARMOR_NAME) != std::string::npos)
            {
                text += " - Unequip Armor";
            }
            if (player_.getWeapon()->getName().find(Const::DEFAULT_WEAPON_NAME) != std::string::npos)
            {
                text += " - Unequip Weapon";
            }

            text += " - Exit\n->";
            std::cout << text;

            std::string stuffChoice;
            getline(std::cin, stuffChoice);

            if (isIn(lower(stuffChoice),{"e","equip"}))
            {
                
            }
            playerChoice_ = "";
            
        }
        // menu player fight
        else if (canFight_ && isIn(lower(playerChoice_), {"f","fight"}))
        {
            text = "\nFight : Attack";
            text += " - Flee\n->";
            std::cout << text;

            std::string fightChoice;
            getline(std::cin, fightChoice);

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
                        std::string ennemyChoice;
                        getline(std::cin, ennemyChoice);
                        ennemyChoice = lower(ennemyChoice);

                        //get the target
                        target = currentTile->getGroup()->getEnemy(ennemyChoice);
                    }
                    
                    // attack the choosen enemy
                    std::cout << player_.attack(*target);
                    
                    // if enemy is dead
                    if (!target->isAlive())
                    {
                        
                        if (target->getWeapon()->getName() != Const::DEFAULT_WEAPON_NAME)
                        {
                            currentTile->getStorage()->addItem(target->getWeapon());
                        }
                        if (target->getArmor()->getName() != Const::DEFAULT_ARMOR_NAME)
                        {
                            currentTile->getStorage()->addItem(target->getArmor());
                        }
                        
                        for(auto item : target->getInventory()->getItems()){
                            currentTile->getStorage()->addItem(item);
                        }
                        
                        currentTile->getGroup()->removeEnemy(target->getName());

                        playerChoice_ = "";
                    }
                    
                    ++turn_;
                }else{
                    std::cout << "There is no enemy on this tile\n";
                }
            }
            else if (isIn(lower(fightChoice), {"f", "flee"}))
            {
                playerChoice_ = "";
                ++turn_;
            }
            else
            {
                playerChoice_ = "";
            }            
        }
        // looting
        else if (canLoot_ && isIn(lower(playerChoice_),{"l","loot"}))
        {
            std::cout << "What do you want to pick up ?\nEnter the item's id.\n";
            std::cout << map_.getCurrentTile()->getStorage()->info();
            std::string lootChoice;
            getline(std::cin, lootChoice);
            auto item = map_.getCurrentTile()->getStorage()->getItem(lootChoice);
            if (item != nullptr)
            {
                player_.getInventory()->addItem(item);
                map_.getCurrentTile()->getStorage()->removeItem(item->getName());
            }
            playerChoice_ = "l";
        }
        
        // create something
        else if (isIn(lower(playerChoice_), {"c", "create"}))
        {
            std::cout << "Create : Weapon - Armor - Object - Enemy\n";

            std::string createChoice;
            getline(std::cin, createChoice);

            if (isIn(lower(createChoice),{"w","weapon"}))
            {
                std::cout << "Enter name :\n";
                
                std::string weaponName;
                getline(std::cin, weaponName);
                // don't create a new weapon if default weapon
                if (weaponName != Const::DEFAULT_WEAPON_NAME)
                {
                    std::cout << "Enter damage :\n";
                    
                    std::string weaponDamage;
                    getline(std::cin, weaponDamage);

                    int value(0);
                    
                    try
                    {
                        value = std::stoi(weaponDamage);
                    }
                    catch(const std::invalid_argument& e)
                    {
                        value = 0;
                    }
                    
                    value = (value < 0) ? 0 : value;
                    
                    currentTile->getStorage()->addItem(new Weapon(weaponName + std::to_string(nbObjects_), value));
                    ++nbObjects_;
                    std::cout << currentTile->info();
                }else{
                    playerChoice_ = "c";
                }
            }else if (isIn(lower(createChoice),{"a","armor"}))
            {
                std::cout << "Enter name :\n";
                
                std::string armornName;
                getline(std::cin, armornName);

                // don't create a new armor if default name
                if (armornName != Const::DEFAULT_ARMOR_NAME)
                {
                    std::cout << "Enter protection :\n";
                    
                    std::string armorProtection;
                    getline(std::cin, armorProtection);

                    int value(0);
                    
                    try
                    {
                        value = std::stoi(armorProtection);
                    }
                    catch(const std::invalid_argument& e)
                    {
                        value = 0;
                    }
                    
                    value = (value < 0) ? 0 : value;
                    
                    currentTile->getStorage()->addItem(new Armor(armornName + std::to_string(nbObjects_), value));
                    ++nbObjects_;
                    std::cout << currentTile->info();
                }else{
                    playerChoice_ = "c";
                }
            }else if (isIn(lower(createChoice),{"o","object"}))
            {
                std::cout << "Enter name :\n";
                
                std::string name;
                getline(std::cin, name);

                
                
                currentTile->getStorage()->addItem(new Object(std::to_string(nbObjects_), name));
                ++nbObjects_;
                std::cout << currentTile->info();
                playerChoice_ = "c";

            }else if (isIn(lower(createChoice),{"e","enemy"}))
            {
                std::cout << "Enter the name :\n";
                
                std::string entityName;
                getline(std::cin, entityName);

                if (entityName.empty())
                {
                    entityName = "enemy";
                }
                
                std::string weaponName(Const::DEFAULT_WEAPON_NAME), armorName(Const::DEFAULT_ARMOR_NAME);
                int damage(Const::DEFAULT_WEAPON_DAMAGE), protection(Const::DEFAULT_ARMOR_PROTECTION);

                std::cout << "Add a weapon (y/n) ?";
                std::string weaponChoice;
                getline(std::cin, weaponChoice);

                if (isIn(lower(weaponChoice), {"y","yes"}))
                {
                    std::cout << "Name :"; 
                    getline(std::cin, weaponName);
                    weaponName += std::to_string(nbObjects_);
                    ++nbObjects_;
                    weaponName += std::to_string(nbObjects_);
                    ++nbObjects_;
                    std::cout << "Damage :";
                    std::string damageStr;
                    getline(std::cin, damageStr);
                                    
                    try
                    {
                        damage = std::stoi(damageStr);
                    }
                    catch(const std::exception& e)
                    {
                        damage = Const::DEFAULT_WEAPON_DAMAGE;
                    }
                }

                std::cout << "Add a armor (y/n) ?";
                std::string armorChoice;
                getline(std::cin, armorChoice);

                if (isIn(lower(armorChoice), {"y","yes"}))
                {
                    std::cout << "Name :";
                    getline(std::cin, armorName);
                    armorName += std::to_string(nbObjects_);
                    ++nbObjects_;
                    std::cout << "Protection :";
                    std::string protectionStr;
                    getline(std::cin, protectionStr);
                    
                    int protection(0);                    
                    try
                    {
                        protection = std::stoi(protectionStr);
                    }
                    catch(const std::exception& e)
                    {
                        protection = 0;
                    }
                }
                
                currentTile->getGroup()->addEnemy(new Entity(entityName+std::to_string(nbEntities_), weaponName, damage, armorName, protection));
                ++nbEntities_;
                std::cout << currentTile->info();
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