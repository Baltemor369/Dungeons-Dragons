#include "../headers/Inventory.h"

Inventory::Inventory(std::string name):name_(name)
{}
Inventory::Inventory(const Inventory& other){
    name_ = other.name_;
    for(auto& item:other.items_){
        items_.push_back(item);
    }
}

Inventory::~Inventory()
{
    items_.clear();
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
            text += std::to_string(i) + " - " + item->info();
            ++i;
        }
    }
    
    return text;
}

void Inventory::addItem(Object& item) {
    items_.push_back(&item);
}

void Inventory::removeItem(std::string id){
    auto it = std::remove_if(items_.begin(), items_.end(),
        [id](const Object* item) {
            return item->getId() == id;
        });

    if (it != items_.end()) {
        items_.erase(it, items_.end());
    }
}

Object* Inventory::getItem(std::string id){
    for (Object* item : items_) {
        if (item->getId() == id) {
            return item;
        }
    }
    return nullptr;
}