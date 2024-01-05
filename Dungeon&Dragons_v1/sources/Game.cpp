#include "../headers/Game.h"

Game::Game(std::string playerName):running_(true), canFight_(false), canLoot_(false), turn_(0), nbEnnemies_(0), playerChoice_(""), player_("player0", playerName, "Death Dagger", 50)
{
    map_.addTile(new Tile(0,0, true));
    map_.setCurrentTile(map_.getTile(0,0));
    map_.getCurrentTile()->addEntity(Const::PLAYER, &player_);
}

Game::~Game()
{
}

void Game::loop(){
    while (running_)
    {
        // main menu
        std::string text;
        if (lower(playerChoice_) == "")
        {
            text = "\nAction : Info - Move - Stuff";
            if (!map_.getTile(player_.getX(), player_.getY())->isAlone())
            {
                canFight_ = true;
                text += " - Fight";
            }else{
                canFight_ = false;
            }
            if (map_.getCurrentTile()->getStorage()->size() > 0)
            {
                canLoot_ = true;
                text += " - Loot";
            }else{
                canLoot_ = false;
            }
            
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
                std::cout << player_.infoInventory();
            }
            else if (isIn(lower(infoChoice),{"ri", "recap inventory"}))
            {
                std::cout << player_.getInventory()->recap();
            }
            else if (isIn(lower(infoChoice),{"w", "weapon"}))
            {
                std::cout << player_.infoWeapon();
            }
            else if (isIn(lower(infoChoice),{"rw", "recap weapon"}))
            {
                std::cout << player_.getWeapon()->recap();
            }
            else if (isIn(lower(infoChoice),{"a","armor"}))
            {
                std::cout << player_.infoArmor();
            }
            else if (isIn(lower(infoChoice),{"ra","recap armor"}))
            {
                std::cout << player_.getArmor()->recap();
            }
            else if (isIn(lower(infoChoice),{"t", "tile"}))
            {
                std::cout << map_.getCurrentTile()->info();
            }
            else if (isIn(lower(infoChoice),{"rt", "recap tile"}))
            {
                std::cout << map_.getCurrentTile()->recap();
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
            
            if (isIn(moveChoice, KeyFR::KEYS))
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
            auto invent = player_.getInventory();
            std::cout << invent->info();
            std::string text("Action : ");
            if (invent->nbWeapons())
            {
                text += "equip #weaponId ";
            }
            if (invent->nbArmors())
            {
                text += "- equip #armorId";
            }
            text += " - Exit\n->";
            std::cout << text;

            std::string stuffChoice;
            getline(std::cin, stuffChoice);

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

            Tile* currentTile = map_.getCurrentTile();
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
                        std::string text("Enter the id of the enemy you want to attack :\n");
                        for(auto elt : ennemies){
                            text += elt->getName() + " : " + elt->getId() + "\n";
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
                        
                        if (target->getWeapon()->getName() != Const::DEFAULT_WEAPON)
                        {
                            currentTile->addItem(*target->getWeapon());
                        }
                        if (target->getArmor()->getName() != Const::DEFAULT_ARMOR)
                        {
                            currentTile->addItem(*target->getArmor());
                        }
                        

                        for(auto item : target->getInventory()->getItems()){
                            currentTile->addItem(*item);
                        }
                        
                        currentTile->removeEntity(Const::ENEMY, target->getId());

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
        else if (canLoot_ && isIn(lower(playerChoice_),{"l","loot"}))
        {
            std::cout << "What do you want to pick up ?\nEnter the item's id.\n";
            std::cout << map_.getCurrentTile()->getStorage()->info();
            std::string lootChoice;
            getline(std::cin, lootChoice);
            auto item = map_.getCurrentTile()->getItem(lootChoice);
            if (item != nullptr)
            {
                player_.addToInventory(*item);
                map_.getCurrentTile()->removeItem(item->getId());
            }
            playerChoice_ = "";
        }
        
        // create a new monster on the current tile
        else if (isIn(lower(playerChoice_), {"new", "new -w"}))
        {
            // add a new monster to the current tile
            if (playerChoice_.find("-w") != std::string::npos)
            {
                map_.getCurrentTile()->addEntity(Const::ENEMY, new Entity(getNewEnnemyId(), "enemy" + std::to_string(nbEnnemies_), "Sword", 15));
            }else{
                map_.getCurrentTile()->addEntity(Const::ENEMY, new Entity(getNewEnnemyId(), "enemy" + std::to_string(nbEnnemies_) ));
            }
            
            
            ++nbEnnemies_;
            std::cout << map_.getCurrentTile()->info();
            playerChoice_ = "";
        }
        // exit game
        else
        {
            running_ = false;
        }
    }
}

std::string Game::getNewEnnemyId()const{
    return "enemy" + std::to_string(nbEnnemies_);
}