#include "../headers/Game.h"

Game::Game(std::string playerName):player_(playerName), running_(true), canFight_(false), canLoot_(false), nbEntities_(0), nbObjects_(0), playerChoice_("")
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
        // stuff 
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
            if (player_.getArmor()->getName() == Const::DEFAULT_ARMOR_NAME != std::string::npos)
            {
                text += " - Unequip Armor";
            }
            if (player_.getWeapon()->getName() == Const::DEFAULT_WEAPON_NAME != std::string::npos)
            {
                text += " - Unequip Weapon";
            }

            text += " - Exit\n->";
            std::cout << text;

            std::string stuffChoice = input();

            if (isIn(lower(stuffChoice),{"e","equip"}))
            {
                
            }
            playerChoice_ = "";
            
        }
        // fight
        else if (canFight_ && isIn(lower(playerChoice_), {"f","fight"}))
        {
            text = "\nFight : Attack";
            text += " - Flee\n->";
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
                }else{
                    std::cout << "There is no enemy on this tile\n";
                }
            }
            else if (isIn(lower(fightChoice), {"f", "flee"}))
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
            std::string lootChoice = input();

            auto item = map_.getCurrentTile()->getStorage()->getItem(lootChoice);
            
            if (item != nullptr)
            {
                std::cout << "Looting done\n";
                player_.getInventory()->addItem(item);
                map_.getCurrentTile()->getStorage()->removeItem(item->getName());

                playerChoice_ = (map_.getCurrentTile()->getStorage()->isEmpty()) ? "" : "l";
            }else{
                playerChoice_ = "";
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
    if (weaponName != Const::DEFAULT_WEAPON_NAME && weaponName.size() > 1)
    {
        std::cout << "Enter damage value :\n";
        int damage = inputInt(Const::DEFAULT_WEAPON_DAMAGE);

        std::cout << "Enter penetration value :\n";
        int penetration = inputInt(Const::DEFAULT_WEAPON_PENETRING);
        
        std::cout << "Enter vampirism value :\n";
        int vampirism = inputInt(Const::DEFAULT_WEAPON_VAMPIRISM);
        
        std::cout << "Weapon created \n";
        currentTile->getStorage()->addItem(new Weapon(weaponName + std::to_string(nbObjects_), damage, penetration, vampirism));
        ++nbObjects_;
        std::cout << currentTile->info();
    }
    playerChoice_ = "c";
}

void Game::handleCreateArmor(Tile* currentTile){
    std::cout << "Enter name :\n";
    std::string armornName = input();

    if (armornName.size() < 2)
    {
        armornName = Const::DEFAULT_ARMOR_NAME;
    }

    // don't create a new armor if default name
    if (armornName != Const::DEFAULT_ARMOR_NAME && armornName.size() > 1)
    {
        std::cout << "Enter protection value :\n";
        int defense = inputInt(Const::DEFAULT_ARMOR_DEFENSE);
        
        std::cout << "Enter Thorns value :\n";
        int thorns = inputInt(Const::DEFAULT_ARMOR_THORN);
        
        std::cout << "Enter Regeneration value :\n";
        int regeneration = inputInt(Const::DEFAULT_ARMOR_REGENERATION);
        
        std::cout << "Armor created \n";
        currentTile->getStorage()->addItem(new Armor(armornName, defense, thorns, regeneration));
        ++nbObjects_;
        std::cout << currentTile->info();
    }
    playerChoice_ = "c";
}

void Game::handleCreateObject(Tile* currentTile){
    std::cout << "Enter name :\n";
    std::string name = input();

    if (!isIn(lower(name), {Const::DEFAULT_ARMOR_NAME, Const::DEFAULT_WEAPON_NAME}) && name.size() > 1)
    {
        std::cout << "Object created \n";
        currentTile->getStorage()->addItem(new Object(name));
        ++nbObjects_;
        std::cout << currentTile->info();
    }
    
    playerChoice_ = "c";
}

void Game::handleCreateEntity(Tile* currentTile){
    std::cout << "Enter the name :\n";
    std::string entityName = input();

    if (isIn(entityName, {Const::DEFAULT_ARMOR_NAME, Const::DEFAULT_WEAPON_NAME}) && entityName.size() < 2)
    {
        entityName = "enemy";
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
    std::cout << currentTile->info();
}