#pragma once

#include "Coord.h"
#include "Group.h"
#include "constants.h"

class Tile {
private:
    bool visited_;
    Coord location_;
    Group* group_;
    Inventory* storages_;

public:
    Tile(int x, int y, bool visited = false);
    ~Tile();

    std::string recap()const;
    std::string info() const;

    bool isVisited() const;
    bool isAlone() const;
    
    Coord getLocation() const;
    int getX() const{return location_.getX();}
    int getY() const{return location_.getY();}
    Group* getGroup();    
    Inventory* getStorage() const{return storages_;}
    Object* getItem(std::string id);
    
    void setVisited(bool visited);

    void addItem(Object& item);
    void removeItem(std::string id);

    void addEntity(std::string key, Entity* entity);
    void removeEntity(std::string key, std::string id);
};