#pragma once

#include <iostream>
#include <vector>

#include "Entity.h"
#include "Random.h"
#include "Map.h"
#include "strFct.h"

class Game
{
private:
    bool running_;
    bool canFight_;
    bool canLoot_;
    int turn_;
    int nbEnnemies_;
    Random rd_;
    std::string playerChoice_;
    Entity player_;
    std::vector<Entity*> enemies_;
    Map map_;
public:
    Game(std::string playerName);
    ~Game();

    std::string getNewEnnemyId()const;
    void loop();
};