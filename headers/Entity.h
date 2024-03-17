#pragma once

#include "Coord.h"
#include "Inventory.h"
#include "strFct.h"
#include "Random.h"

#include <cmath>
#include <iostream>

class Entity
{
private:
    std::string name_;
    int hp_, velocity_, strengh_;
    int exp_, lvl_;

    Coord location_;
    Inventory* inventory_;
    Weapon* equipedWeapon_;
    Armor* equipedArmor_;
public:
    Entity(std::string name); // default constructor 
    Entity(std::string name, int x, int y); // specific location
    Entity(std::string name, std::string weaponName, int weaponDamage, int weaponPenetration, int weaponVampirism, std::string armorName, int armorDef, int armorThorn, int armorRegeneration); // sepcific armor and weapon
    Entity(std::string name, int x, int y, std::string weaponName, int weaponDamage, int weaponPenetration, int weaponVampirism, std::string armorName, int armorDef, int armorThorn, int armorRegeneration); // sepcific all
    ~Entity();

    std::string recap()const;
    std::string info()const;

    // getters
    std::string getName()const{return name_;}
    int getHp()const{return hp_;}
    int getVelocity()const{return velocity_;}
    int getX()const {return location_.getX();}
    int getY()const {return location_.getY();}
    Coord getLocation()const{return location_;}

    //setters
    void setName(const std::string name);
    void setHP(int hp){hp_ = hp;}
    void setVelocity(int velocity){velocity_ = velocity;}
    void setLocation(const Coord location){location_ = location;}

    // movement
    std::string move(std::string direction);
    std::string approachCharacter(const Entity& target); // reduce distance with the target
    std::string fleeCharacter(const Entity& target); // increase the distance with the target

    // inventory
    Inventory* getInventory()const{return inventory_;} // return the object Inventory

    // weapon 
    Weapon* getWeapon(){ return equipedWeapon_ ; } // return the object Weapon
    void equipWeapon(Weapon* w); // change the weapon's address saved with the new one
    void unequipWeapon(); // delete the weapon's address saved
    bool hasWeaponEquipped()const{return equipedWeapon_->getName() != Const::Default::WEAPON_NAME;}
    
    // armor
    Armor* getArmor(){ return equipedArmor_ ; } // return the object Armor
    void equipArmor(Armor* a); // change the armor's address saved with the new one
    void unequipArmor(); // delete the armor's address saved
    bool hasArmorEquipped()const{return equipedArmor_->getName() != Const::Default::ARMOR_NAME;}

    // attack
    bool isAlive()const{return (hp_>0);} // return true if entity is alive else not
    bool attack(Entity& target); // attack the target by giving our weapon's damage
    void dealDamage(int damage); // calculate the damage receive with reduce by protection

    // other
    void updateXp();
};