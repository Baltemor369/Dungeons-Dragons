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
    ~Inventory();
    std::string info() const;

    std::string getName()const{return name_;}

    void setName(std::string newName){name_ = newName;}

    void addItem(Object* item);
    void removeItem(Object* item);
    void removeItem(int index);
    Object* getItem(int index) const;
    void clearInventory();
};