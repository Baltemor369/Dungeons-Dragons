#include "../headers/Inventory.h"

Inventory::Inventory()
{}

Inventory::~Inventory()
{
    clearInventory();
}

void Inventory::addItem(Object* item) {
    items_.push_back(item);
}

std::string Inventory::info() const {
    std::string text("Inventory Contents:\n");
    int i(0);
    for (const auto& item : items_) {
        text += std::to_string(i) + " " + item->info() + "\n";
        ++i;
    }
    return text;
}

void Inventory::removeItem(Object* item) {
    auto it = std::find(items_.begin(), items_.end(), item);
    if (it != items_.end()) {
        delete *it;
        items_.erase(it);
    }
}
void Inventory::removeItem(int index) {
    if (index < items_.size()) {
        delete items_[index];
        items_.erase(items_.begin()+index);
    }
}

Object* Inventory::getItem(int index) const {
    if (index >= 0 && index < items_.size()) {
        return items_[index];
    }
    return nullptr;
}

void Inventory::clearInventory() {
    for (auto& item : items_) {
        delete item;
    }
    items_.clear();
}