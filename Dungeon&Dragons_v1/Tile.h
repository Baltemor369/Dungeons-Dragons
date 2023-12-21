#pragma once

#include <vector>

#include "Coord.h"
#include "Character.h"

class Tile
{
private:
    bool visited_;
    Coord location_;
    std::vector<Character*> people_;
public:
    Tile(int x, int y, bool visited=false);
    ~Tile();
    bool isVisited()const{return visited_;}
    const Coord& getLocation()const {return location_;}
    void setAsVisited(){visited_ = true;}
    // Add a character to the tile's list of characters
    void addPerson(Character *person);
    // Remove a character from the tile's list of characters
    void removePerson(Character *person);
    // Get all the characters on this tile
    std::vector<Character*> getPeopleOnThisTile()const { return people_;}
};
