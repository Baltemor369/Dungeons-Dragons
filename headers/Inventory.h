#pragma once

#include <algorithm>
#include <tuple>
#include <iostream>

#include "Weapon.h"
#include "Armor.h"
#include "strFct.h"

class Inventory
{
private:
    std::string name_;
    std::vector<std::tuple<int, Object*>> items_;
public:
    Inventory(std::string name="Backpack");
    Inventory(const Inventory& other);
    ~Inventory(){items_.clear();}
    
    // information
    std::string recap(); // return a little resume of the inventory
    std::string info() ; // return all informations of the inventory
    
    // getters
    std::string getName()const{return name_;} // name of the inventory
    int size()const; // number of items in the inventory (weapon armor and other)
    bool isEmpty()const{return items_.size() == 0;} // inventory empty or not
    int nbWeapons()const{return getWeapons().size();} // number of weapons in the inventory
    int nbArmors()const{return getArmors().size();} // number of armor in the inventory
    int nbObjects()const{return getObjects().size();} // number of objects in the inventory
    std::tuple<int, Object*> getEltByIndex(int index){return items_[index];} // get the elt by its index
    Object* getItemByName(std::string name); // get the elt by its name
    int getStackItem(std::string name); // get the stack number of an elt by its name
    int getIndexByName(std::string name) const ; // get the index in the list of an elt by its name
    std::vector<Weapon*> getWeapons()const; // get the list of weapons
    std::vector<Armor*> getArmors()const;// get the list of armors
    std::vector<Object*> getObjects()const; // get the list of objects
    std::vector<std::tuple<int, Object*>> getAll()const{return items_;} // get all items in the inventory
    
    // setters
    void setName(std::string newName){name_ = newName;}
    void addItem(Object* item, int stack=1); 
    void removeItem(std::string name, int stack=1);

};