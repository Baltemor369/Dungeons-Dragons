#include "../headers/Armor.h"

Armor::Armor(std::string name, int protection) : Object(name, Const::ARMOR), protection_(protection) {}

Armor::Armor(const Armor &other):Object(other.getName(), other.getType()) {
    protection_ = other.getProtection();
}
Armor::~Armor() {}

std::string Armor::info() const {
    return "Armor: " + getName() + ", Protection= " + std::to_string(protection_) + "\n";
}

int Armor::getProtection() const {
    return protection_;
}

void Armor::setProtection(int protection) {
    protection_ = protection;
}