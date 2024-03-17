#include "../headers/Tile.h"

Tile::Tile(int x, int y, bool visited) : visited_(visited), location_(x, y) {
    group_ = new Group();
    storages_.push_back(new Inventory("Default"));
}

Tile::~Tile() {
    delete group_;
    for(auto elt : storages_){
        delete elt;
    }
}

std::string Tile::recap()const{
    std::string text;
    text += "Tile " + location_.info() + group_->recap(); 
    text += "Storage : " + storages_.size();
    return text;
}

std::string Tile::info() const {
    std::string text;
    text += "Tile " + location_.info(); 
    for (auto elt : storages_)
    {
        text += elt->info();
    }
    
    group_->recap();
    return text;
}

Inventory* Tile::getInventory(std::string name){
    for (auto elt : storages_)
    {
        if (elt->getName() == name)
        {
            return elt;
        }
    }
    return Const::ERROR::POINTER;    
}