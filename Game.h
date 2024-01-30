#pragma once

// #include <iostream>
// #include <vector>

#include "Map.h"
// #include "Entity.h"
// #include "Random.h"
// #include "strFct.h"

class Game
{
private:
    bool running_;
    bool canFight_;
    bool canLoot_;
    bool canInventory;
    int nbEntities_, nbObjects_;
    std::vector<std::string> entityNames_, itemNames_;
    Random rd_;
    std::string playerChoice_;
    Entity player_;
    Map map_;
public:
    Game(std::string playerName);
    ~Game();

    void loop();
    std::string input();
    int inputInt(int defaultValue);
    void handleCreateWeapon(Inventory* invent);
    void handleCreateArmor(Inventory* invent);
    void handleCreateObject(Inventory* invent);
    void handleCreateEntity(Group* team);
};