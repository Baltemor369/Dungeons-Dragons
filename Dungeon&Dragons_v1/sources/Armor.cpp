#include "../headers/Armor.h"

Armor::Armor(std::string id, std::string name, int protection) : Object(id, name), protection_(protection) {}
Armor::Armor(const Armor &other):Object(other.getId(), other.getName(), other.getType()) {
    protection_ = other.getProtection();
}
Armor::~Armor() {}

std::string Armor::recap()const{
    return "Armor resistance : " + std::to_string(protection_) + "\n";
}

std::string Armor::info() const {
    return "Armor: " + getName() + "#ID:" + getId() + ", Type: " + getType() + ", Protection: " + std::to_string(protection_) + "\n";
}

int Armor::getProtection() const {
    return protection_;
}

void Armor::setProtection(int protection) {
    protection_ = protection;
}