#include "../headers/Weapon.h"

Weapon::Weapon(std::string name, int damage) : Object(name, "Weapon"), damage_(damage) {}

int Weapon::getDamage() const {
    return damage_;
}

void Weapon::setDamage(int damage) {
    damage_ = damage;
}

std::string Weapon::info() const {
    return "Weapon: " + getName() + ", Type: " + getType() + ", Damage: " + std::to_string(damage_);
}
