#include "../headers/Weapon.h"

Weapon::Weapon(std::string name, int damage)  {}

Weapon::Weapon(const Weapon &other):Object(other.getName(), other.getType()) {
    damage_ = other.getDamage();
}
Weapon::~Weapon(){}

std::string Weapon::info() const {
    return "Weapon: " + this->getName() + ", Damage= " + std::to_string(damage_) + "\n";
}

int Weapon::getDamage() const {
    return damage_;
}

void Weapon::setDamage(int damage) {
    damage_ = damage;
}
