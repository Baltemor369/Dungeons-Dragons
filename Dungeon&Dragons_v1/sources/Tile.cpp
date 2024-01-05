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
    text += "Storage : " + (storages_->size()==0)? "Empty" : storages_->recap();
    return text;
}

std::string Tile::info() const {
    std::string text;
    text += "Tile " + location_.info() + storages_->info() + group_->info();
    return text;
}

void Tile::setVisited(bool visited) {
    visited_ = visited;
}

bool Tile::isVisited() const {
    return visited_;
}

bool Tile::isAlone() const {
    return group_->size() == 0;
}


Coord Tile::getLocation() const {
    return location_;
}

Group* Tile::getGroup() {
    return group_;
}

void Tile::addItem(Object& item){
    storages_->addItem(item);
}

Object* Tile::getItem(std::string id){
    return storages_->getItem(id);
}

void Tile::removeItem(std::string id){
    storages_->removeItem(id);
}

void Tile::addEntity(std::string key, Entity* entity){
    if (key == Const::PLAYER)
    {
        group_->addPlayer(*entity);
    }
    else if (key == Const::ENEMY)
    {
        group_->addEnemy(*entity);
    }
}

void Tile::removeEntity(std::string key, std::string id){
    if (key == Const::PLAYER)
    {
        group_->removePlayer();
    }
    else if (key == Const::ENEMY)
    {
        group_->removeEnemy(id);
    }
}