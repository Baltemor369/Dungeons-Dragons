#include "../headers/Weapon.h"

Weapon::Weapon(const Weapon &other):Object(other.getName(), other.getType()) {
    damage_ = other.getDamage();
}
Weapon::~Weapon(){}

std::string Weapon::info() const {
    std::string text;
    text += "Weapon: " + getName();
    text += ", Damage=" + std::to_string(getDamage());
    text += ", lethality=" + std::to_string(getLethality());
    text += ", Vampirism=" + std::to_string(getVampirism());
    text += "\n";
    return text;
}
