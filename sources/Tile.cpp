#include "../headers/Tile.h"

Tile::Tile(int x, int y, bool visited) : visited_(visited), location_(x, y) {
    group_ = new Group();
    storages_ = new Inventory("storage");
}

Tile::~Tile() {
    delete group_;
    delete storages_;
}

std::string Tile::recap()const{
    std::string text;
    text += "Tile " + location_.info() + group_->recap(); 
    text += "Storage : " + storages_->recap();
    return text;
}

std::string Tile::info() const {
    std::string text;
    text += "Tile " + location_.info() + storages_->info() + group_->recap();
    return text;
}