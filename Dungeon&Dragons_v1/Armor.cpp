#include "../headers/Armor.h"

Armor::Armor(std::string name, int protection) : Object(name, "Armor"), protection_(protection) {}

int Armor::getProtection() const {
    return protection_;
}

void Armor::setProtection(int protection) {
    protection_ = protection;
}

std::string Armor::info() const {
    return "Armor: " + getName() + ", Type: " + getType() + ", Protection: " + std::to_string(protection_);
}