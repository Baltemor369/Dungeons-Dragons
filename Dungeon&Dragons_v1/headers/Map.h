#pragma once

#include "Tile.h"

class Map {
private:
    int width_;
    Tile* currentTile_;
    std::vector<Tile*> tiles_;
public:
    Map();
    ~Map();
    
    std::string recap()const;
    std::string info()const;

    Tile* getTile(int x, int y);
    Tile* getCurrentTile();

    void setCurrentTile(Tile* tile);
    
    void addTile(Tile* tile);
    void movement(std::string direction);
};