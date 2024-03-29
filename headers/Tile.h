#pragma once

#include "Coord.h"
#include "Group.h"

class Tile {
private:
    bool visited_;
    Coord location_;
    Group* group_;
    std::vector<Inventory*> storages_;

public:
    Tile(int x, int y, bool visited = false);
    ~Tile();

    std::string recap()const;
    std::string info() const;

    bool isVisited() const{return visited_;}
    bool isAlone() const{return group_->size()==0;}
    
    Coord getLocation() const{return location_;}
    int getX() const{return location_.getX();}
    int getY() const{return location_.getY();}
    Group* getGroup(){return group_;}
    Inventory* getInventory(std::string name);
    std::vector<Inventory*> getStorages() const{return storages_;}
    
    void setVisited(bool visited){visited_ = visited;}
};