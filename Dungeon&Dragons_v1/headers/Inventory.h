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
    std::vector<Object*> items_;
public:
    Inventory(std::string name="Backpack");
    Inventory(const Inventory& other);
    ~Inventory();

    std::string recap()const;
    std::string info() const;

    std::string getName()const{return name_;}
    int size()const{return items_.size();}

    void setName(std::string newName){name_ = newName;}

    void addItem(Object& item);
    void removeItem(std::string id);
    Object* getItem(std::string id);
    std::vector<Object*> getItems()const{return items_;}
};