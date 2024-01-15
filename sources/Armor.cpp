#include "../headers/Armor.h"

Armor::Armor(std::string name, int protection) : Object(name, Const::ARMOR), defense_(protection) {}

Armor::Armor(const Armor &other):Object(other.getName(), other.getType()) {
    defense_ = other.getDefense();
}
Armor::~Armor() {}

std::string Armor::info() const {
    return "Armor: " + getName() + ", Protection= " + std::to_string(defense_) + "\n";
}

void Armor::setProtection(int protection) {
    defense_ = protection;
}