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
    bool canInventory;
    int turn_;
    int nbEntities_, nbObjects_;
    Random rd_;
    std::string playerChoice_;
    Entity player_;
    Map map_;
public:
    Game(std::string playerName);
    ~Game();

    std::string input();
    int inputInt(int defaultValue);
    void loop();
};