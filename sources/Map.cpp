#include "../headers/Map.h"

Map::Map():width_(0){
    currentTile_ = nullptr;
}

Map::~Map(){
    for (Tile* tile : tiles_) {
        delete tile;
    }
    currentTile_ = nullptr;

    tiles_.clear();
}

std::string Map::recap()const{
    std::string text;
    text += "Map size: " + std::to_string(width_) + "\n";
    if (currentTile_ != nullptr)
    {
        text += "Current Tile: " + currentTile_->recap();
    }
    return text;
}

std::string Map::info()const{
    std::string text;
    text += "Map size: " + std::to_string(width_) + "\n";
    if (currentTile_ != nullptr)
    {
        text += "Current Tile: " + currentTile_->info();
    }
    return text;
}

Tile* Map::getTile(int x, int y){
    for(auto& tile : tiles_){
        if(tile->getX() == x && tile->getY() == y){
            return tile;
        }
    }
    return nullptr;
}

Tile* Map::getCurrentTile(){
    return currentTile_;
}

void Map::addTile(Tile* tile){
    bool found(false);
    for(auto& t : tiles_){
        if(t->getX() == tile->getX() && t->getY() == tile->getY()){
            found = true;
            break;
        }
    }
    if(!found){
        tiles_.push_back(tile);
    }
}

void Map::movement(std::string direction){
    Entity* player = currentTile_->getGroup()->getPlayer();

    // remove from the old tile
    currentTile_->getGroup()->removePlayer();
    
    // move the player
    std::cout << player->move(direction);
    
    // get the new tile if already created
    Tile* tile = getTile(player->getX(), player->getY());
    if(tile == nullptr){
    
        // if not, create a new one
        tile = new Tile(player->getX(), player->getY(), true);
    
        // add it to the map
        addTile(tile);
    }
    // update the current tile
    setCurrentTile(tile);
    // add the player to the new tile
    currentTile_->getGroup()->addPlayer(*player);

    std::cout << currentTile_->info();
}