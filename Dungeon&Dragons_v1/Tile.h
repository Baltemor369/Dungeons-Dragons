#pragma once

#include <vector>

#include "Group.h"

class Tile
{
private:
    bool visited_;
    Coord location_;
    Group people_;
public:
    Tile(int x, int y, bool visited=false);
    ~Tile();
    // Get all the characters on this tile
    Group getPeople()const { return people_;}
    int getX()const { return location_.getX();}
    int getY()const { return location_.getY();}
    const Coord& getLocation()const {return location_;}
    bool isVisited()const{return visited_;}

    void setAsVisited(){visited_ = true;}
    // Add a character to the tile's list of characters
    void enterPerson(Character *person);
    // Remove a character from the tile's list of characters
    void exitPerson(Character *person);
    // Remove all characters from the tile
    void clearPeople();
};