#include "../headers/Map.h"

Map::Map()
{
}

Map::~Map()
{
}

Tile* Map::getTile(int x, int y){
    for (int i = 0; i < tiles_.size(); i++){
        if (tiles_.at(i)->getX() == x && tiles_.at(i)->getY() == y){
            return tiles_.at(i);
        }
    }
    return nullptr;
}

void Map::addTile(Tile* tile){
    tiles_.push_back(tile);
}

void Map::playerMove(Character* player, std::string direction){
    Tile* oldTile = getTile(player->getX(), player->getY());
    oldTile->exitPerson(player);
    
    std::cout << player->move(direction);
    Tile* newTile;
    if (getTile(player->getX(), player->getY()) == nullptr)
    {
        newTile = new Tile(player->getX(), player->getY());
        newTile->setAsVisited();
    }else
    {
        newTile = getTile(player->getX(), player->getY());
    }
    
    addTile(newTile);
    newTile->enterPerson(player);
}