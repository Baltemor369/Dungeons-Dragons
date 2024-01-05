#pragma once

#include "Coord.h"
#include "Inventory.h"
#include "Weapon.h"
#include "strFct.h"
#include "constants.h"

#include <string>
#include <cmath>
#include <iostream>

class Entity
{
private:
    std::string name_, id_;
    int hp_, velocity_;
    Coord location_;
    Inventory* inventory_;
    Weapon* equipedWeapon_;
    Armor* equipedArmor_;
public:
    Entity(std::string id, std::string name);
    Entity(std::string id, std::string name, int x, int y);
    Entity(std::string id, std::string name, std::string weaponName, int weaponDamage);
    ~Entity();

    std::string recap()const;
    std::string info()const;

    // getters
    std::string getId()const{return id_;}
    std::string getName()const{return name_;}
    int getHp()const{return hp_;}
    int getVelocity()const{return velocity_;}
    Coord getLocation()const{return location_;}
    int getX()const {return location_.getX();}
    int getY()const {return location_.getY();}
    std::string getItemNewID()const;

    //setters
    void setName(const std::string& name);
    void setHP(int hp);
    void setVelocity(int velocity);
    void setLocation(const Coord& location);

    // movement
    std::string move(std::string direction);
    std::string approachCharacter(const Entity& target);
    std::string fleeCharacter(const Entity& target);

    // inventory
    Inventory* getInventory()const{return inventory_;}
    void addToInventory(Object& item);
    Object* getItem(std::string id){return inventory_->getItem(id);}
    void removeFromInventory(std::string id);
    std::string infoInventory() const{return inventory_->info();}

    // weapon 
    Weapon* getWeapon(){ return equipedWeapon_ ; }
    void equipWeapon(Weapon& w){ equipedWeapon_ = &w ; }
    std::string infoWeapon()const{return equipedWeapon_->info();}
    
    // armor
    Armor* getArmor(){ return equipedArmor_ ; }
    void equipArmor(Armor& a){ equipedArmor_ = &a ; }
    std::string infoArmor()const{return equipedArmor_->info();}

    // attack
    bool isAlive()const{return (hp_>0);}
    std::string attack(Entity& target);
    void dealDamage(int damage);
};