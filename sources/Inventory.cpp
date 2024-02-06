#include "../headers/Inventory.h"

Inventory::Inventory(std::string name):name_(name), nbObject_(0), nbWeapon_(0), nbArmor_(0)
{}

Inventory::Inventory(const Inventory& other){
    name_ = other.name_;
    for(auto& item:other.items_){
        items_.push_back(item);
    }
}

std::string Inventory::recap() const {
    std::string text(name_ + " Contents:\n");
    if (items_.size()==0)
    {
        text += "Empty\n";
    }else{
        text += "Nb Items: " + std::to_string(items_.size()) + "\n";
    }
    
    return text;
}

std::string Inventory::info() const {
    std::string text(name_ + " Contents:\n");
    if (items_.size()==0)
    {
        text += "Empty\n";
    }else{
        int i(0);
        for (const auto& item : items_) {
            text += "count : " + std::to_string(std::get<0>(item)) + " - " + std::get<1>(item)->info();
            ++i;
        }
    }
    
    return text;
}

Object* Inventory::getItemByName(std::string name){
    for (auto item : items_) {
        if (std::get<1>(item)->getName() == name) {
            return std::get<1>(item);
        }
    }
    return Const::ERROR::POINTER;
}

int Inventory::getIndexByName(std::string name) const {
    for (int i = 0; i < items_.size(); i++)
    {
        if (std::get<1>(items_[1])->getName() == name)
        {
            return i;
        }
    }
    return Const::ERROR::INT;
}

void Inventory::addItem(Object* item){
    int it = getIndexByName(item->getName());

    if (it == Const::ERROR::INT)
    {
        items_.push_back({1, item});
    }else{
        ++std::get<0>(items_[it]);
    }
    

    if (item->getType() == Const::WEAPON)
    {
        ++nbWeapon_;
    }else if (item->getType() == Const::ARMOR)
    {
        ++nbArmor_;
    }else{
        ++nbObject_;
    }
}

void Inventory::removeItem(std::string name){
    int index = getIndexByName(name);
    // verify if item name is registered
    if (index != -1)
    {
        if (std::get<0>(items_[index]) > 1)
        {
            --std::get<0>(items_[index]);
        }else{
            items_.erase(items_.begin()+index);
        }
    }
}

bool Inventory::canCraft(Recipe recipe){
    for (int index(0); index < recipe.size(); ++index)
    {
        if (getItemByName(std::get<1>(recipe[index])) != Const::ERROR::POINTER)
        {
            recipe.erase(recipe.begin()+index);
        }
    }
    if (recipe.empty())
    {
        return true;
    }    
    
    return false;
}