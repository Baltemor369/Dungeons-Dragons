#pragma once

#include <algorithm>
#include <tuple>

#include "Weapon.h"
#include "Armor.h"

class Inventory
{
private:
    std::string name_;
    int nbObject_, nbWeapon_, nbArmor_;
    std::vector<std::tuple<int, Object*>> items_;
public:
    Inventory(std::string name="Backpack");
    Inventory(const Inventory& other);
    ~Inventory(){items_.clear();}

    std::string recap()const; // return a little resume of the inventory
    std::string info() const; // return all informations of the inventory

    std::string getName()const{return name_;}
    int size()const{return items_.size();}
    bool isEmpty()const{return items_.size() == 0;}
    int nbWeapons()const{return nbWeapon_;}
    int nbArmors()const{return nbArmor_;}
    int nbObjects()const{return nbObject_;}
    void setName(std::string newName){name_ = newName;}

    Object* getItemByName(std::string name);  
    std::tuple<int, Object*> getEltByIndex(int index){return items_[index];}
    int getIndexByName(std::string name) const ;
    void addItem(Object* item); 
    void removeItem(std::string name);
    std::vector<std::tuple<int, Object*>> getItems()const{return items_;}
};