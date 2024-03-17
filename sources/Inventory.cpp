#include "../headers/Inventory.h"

Inventory::Inventory(std::string name):name_(name)
{}

Inventory::Inventory(const Inventory& other){
    name_ = other.name_;
    for(auto& item:other.items_){
        items_.push_back(item);
    }
}

std::string Inventory::recap() {
    std::string text(name_ + "Recap :\n");
    if (items_.size()==0)
    {
        text += "Empty\n";
    }else{
        text += "Nb Armors: " + std::to_string(nbArmors()) + "\n";
        text += "Nb Weapons: " + std::to_string(nbWeapons()) + "\n";
        text += "Nb Items: " + std::to_string(nbObjects()) + "\n";
        text += "Nb Total: " + std::to_string(size()) + "\n";
    }
    
    return text;
}

std::string Inventory::info() {
    std::string text;
    text += name_ + "\n";
    text += "Contents :\n";
    if (items_.size()==0)
    {
        text += "Empty\n";
    }else{
        for (const auto& item : items_) {
            text += "count : " + std::to_string(std::get<0>(item)) + " || " + std::get<1>(item)->info();
        }
    }
    
    return text;
}

Object* Inventory::getItemByName(std::string name){
    for (auto item : items_) {
        if (Str::capitalize(std::get<1>(item)->getName()) == Str::capitalize(name)) {
            return std::get<1>(item);
        }
    }
    return Const::ERROR::POINTER;
}

int Inventory::getStackItem(std::string name){
    for (auto item : items_) {
        if (Str::capitalize(std::get<1>(item)->getName()) == Str::capitalize(name)) {
            return std::get<0>(item);
        }
    }
    return Const::ERROR::INT;
}

int Inventory::getIndexByName(std::string name) const {
    int index = 0;
    for (auto& item : items_)
    {
        if (std::get<1>(item)->getName() == name)
        {
            return index;
        }
        
        ++index;
    }
    return Const::ERROR::INT;
}

void Inventory::addItem(Object* item, int stack){
    int it = getIndexByName(item->getName());
    if (it == Const::ERROR::INT)
    {
        items_.push_back({stack, item});
    }else{
        std::get<0>(items_[it]) += stack;
    }
}

void Inventory::removeItem(std::string name, int stack){
    int index = getIndexByName(name);
    // verify if item name is registered
    if (index != Const::ERROR::INT)
    {
        if (std::get<0>(items_[index]) > stack)
        {
            std::get<0>(items_[index]) -= stack;
        }else{
            items_.erase(items_.begin()+index);
        }
    }

}

int Inventory::size()const{
    return nbObjects() + nbArmors() + nbWeapons();
}

std::vector<Weapon*> Inventory::getWeapons()const{
    std::vector<Weapon*> weapons;

    for (const auto& item : items_) {
        Object* obj = std::get<1>(item); // Get the object pointer from the tuple
        Weapon* weaponPtr = dynamic_cast<Weapon*>(obj); // Try to cast it to Weapon*

        if (weaponPtr) {
            weapons.push_back(weaponPtr); // If successful, add to weapons vector
        }
    }

    return weapons;
}

std::vector<Armor*> Inventory::getArmors()const{
    std::vector<Armor*> armors;

    for (const auto& item : items_) {
        Object* obj = std::get<1>(item); // Get the object pointer from the tuple
        Armor* weaponPtr = dynamic_cast<Armor*>(obj); // Try to cast it to Weapon*

        if (weaponPtr) {
            armors.push_back(weaponPtr); // If successful, add to weapons vector
        }
    }

    return armors;

}

std::vector<Object*> Inventory::getObjects()const{
    std::vector<Object*> items;

    for (const auto& item : items_) {
        Object* obj = std::get<1>(item);

        if (obj->getType() == Const::OBJECT) {
            items.push_back(obj);
        }
    }

    return items;
}