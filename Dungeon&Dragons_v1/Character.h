#pragma once

#include "Coord.h"
#include "Object.h"
#include "Inventory.h"
#include "Weapon.h"

#include <string>
#include <cmath>

class Character
{
private:
    std::string name_;
    int hp_, velocity_;
    Coord location_;
    Inventory inventory_;
    Weapon* equipedWeapon_;
    Armor* equipedArmor_;
public:
    Character(std::string name, int x=0, int y=0, int hp=100, int velocity=1,Weapon* weapon=new Weapon(), Armor* armor=new Armor());
    Character(std::string name, std::string armorName, int armorProtection, std::string weaponName, int weaponDamage);
    Character(std::string name, Weapon* weapon, Armor* armor);
    Character(std::string name, Weapon* weapon);
    Character(std::string name, Armor* armor);
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

    // movement
    std::string move(std::string direction);
    std::string approachCharacter(const Character& target);
    std::string fleeCharacter(const Character& target);

    // inventory
    void addToInventory(Object* item);
    void removeFromInventory(Object* item);
    std::string infoInventory() const{return inventory_.info();}

    // weapon 
    Weapon* getWeapon(){ return equipedWeapon_ ; }
    void setWeapon(Weapon* w){ equipedWeapon_ = w ; }
    std::string infoWeapon()const{return equipedWeapon_->info();}
    
    // armor
    Armor* getArmor(){ return equipedArmor_ ; }
    void setArmor(Armor* a){ equipedArmor_ = a ; }
    std::string infoArmor()const{return equipedArmor_->info();}

    // attack
    bool isAlive()const{return (hp_>0);}
    std::string attack(Character& target);
    void dealDamage(int damage);
};