#include "../headers/Weapon.h"

Weapon::Weapon(const Weapon &other):Object(other.getName(), other.getType()) {
    damage_ = other.getDamage();
}
Weapon::~Weapon(){}

std::string Weapon::info() const {
    return "Weapon: " + this->getName() + ", Damage= " + std::to_string(damage_) + "\n";
}

void Weapon::setDamage(int damage) {
    damage_ = damage;
}
