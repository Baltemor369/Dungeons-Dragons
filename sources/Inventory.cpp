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
            text += " - " + item->info();
            ++i;
        }
    }
    
    return text;
}

void Inventory::addItem(Object* item){
    items_.push_back(item);
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
    auto it = std::remove_if(items_.begin(), items_.end(),
        [name](const Object* item) {
            return item->getName() == name;
        });

    if (it != items_.end()) {
        items_.erase(it, items_.end());
    }
}

Object* Inventory::getItem(std::string name){
    for (auto item : items_) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

void Inventory::craft(){

}