#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "Object.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory
{
private:
    std::string name_;
    int nbObject_, nbWeapon_, nbArmor_;
    std::vector<Object*> items_;
public:
    Inventory(std::string name="Backpack");
    Inventory(const Inventory& other);
    ~Inventory(){items_.clear();}

    std::string recap()const; // return a little resume of the inventory
    std::string info() const; // return all informations of the inventory

    std::string getName()const{return name_;}
    int size()const{return items_.size();}
    int nbWeapons()const{return nbWeapon_;} // return numbers of Weapons
    int nbArmors()const{return nbArmor_;} // return numbers of Armors
    int nbObjects()const{return nbObject_;} // return numbers of Items

    void setName(std::string newName){name_ = newName;}

    void addItem(Object* item); // add the address of a Object to the vector
    void removeItem(std::string name); // remove a item found with its name
    Object* getItem(std::string name); // return the object address 
    std::vector<Object*> getItems()const{return items_;} // return the list of Objects
    void craft();
};