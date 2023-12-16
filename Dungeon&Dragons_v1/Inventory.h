#ifndef INVENTORY_H
#define INVENTORY_H

#include "Object.h"
#include <vector>

class Inventory
{
private:
    std::vector<Object> p_inventory;
public:
    Inventory();
    ~Inventory();

    void add_item(const Object& item);
    void remove_item(const std::string& name);
    void modify_item_count(const std::string& name, int newCount);
    void modify_item_value(const std::string& name, int newValue);
    void modify_item_damage(const std::string& name, int newValue);
    void modify_item_lethality(const std::string& name, int newValue);
    void modify_item_reach(const std::string& name, int newValue);
    void modify_item_resistance(const std::string& name, int newValue);
};

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::add_item(const Object& obj) {
    p_inventory.push_back(obj);
}

void Inventory::remove_item(const std::string& name) {
    p_inventory.erase(std::remove_if(p_inventory.begin(), p_inventory.end(),
                    [name](const Object& obj) { return obj.getName() == name; }),
                    p_inventory.end());
}

void Inventory::modify_item_count(const std::string& name, int newCount) {
    for (Object& obj : p_) {
        if (obj.get_name() == name) {
            obj.set_count(newCount);
            break;
        }
    }
}

void Inventory::modify_item_value(const std::string& name, int newValue) {
    for (Object& obj : p_inventory) {
        if (obj.getName() == name) {
            obj.set_value(newValue);
            break;
        }
    }
}

void Inventory::modify_item_damage(const std::string& name, int newValue) {
    for (Object& obj : p_inventory) {
        if (obj.get_name() == name) {
            obj.set_damage(newValue);
            break;
        }
    }
}

void Inventory::modify_item_lethality(const std::string& name, int newValue) {
    for (Object& obj : p_inventory) {
        if (obj.getName() == name) {
            obj.set_lethality(newValue);
            break;
        }
    }
}

void Inventory::modify_item_reach(const std::string& name, int newValue) {
    for (Object& obj : p_inventory) {
        if (obj.getName() == name) {
            obj.set_reach(newValue);
            break;
        }
    }
}

void Inventory::modify_item_resistance(const std::string& name, int newValue) {
    for (Object& obj : p_inventory) {
        if (obj.getName() == name) {
            obj.set_resistance(newValue);
            break;
        }
    }
}

#endif