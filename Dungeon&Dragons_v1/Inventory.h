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
    std::vector<Object*> items_;
public:
    Inventory();
    ~Inventory();
    std::string info() const;
    void addItem(Object* item);
    void removeItem(Object* item);
    void removeItem(int index);
    Object* getItem(int index) const;
    void clearInventory();
};