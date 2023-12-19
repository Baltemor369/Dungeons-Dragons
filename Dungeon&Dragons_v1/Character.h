#pragma once

#include "Coord.h"
#include "Object.h"
#include "Inventory.h"

#include <string>
#include <cmath>

class Character
{
private:
    std::string name_;
    Coord location_;
    int hp_, velocity_;
    Inventory inventory_;
public:
    Character(std::string name, int x=0, int y=0, int hp=100, int velocity=1);
    ~Character();

    std::string info()const;

    // getters
    int getHp()const{return hp_;}
    int getVelocity()const{return velocity_;}
    Coord getLocation()const{return location_;}
    std::string getName()const{return name_;}
    int getX()const {return location_.getX();}
    int getY()const {return location_.getY();}

    //setters
    void setName(const std::string& name);
    void setLocation(const Coord& location);
    void setHP(int hp);
    void setVelocity(int velocity);

    // movement methods
    std::string move(int deltaX, int deltaY);
    std::string approachCharacter(const Character& target);
    std::string fleeCharacter(const Character& target);

    // inventory methods
    void addToInventory(Object* item);
    void removeFromInventory(Object* item);
    std::string infoInventory() const;
};