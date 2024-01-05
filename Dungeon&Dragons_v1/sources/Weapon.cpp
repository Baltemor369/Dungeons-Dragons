#include "../headers/Weapon.h"

Weapon::Weapon(std::string id, std::string name, int damage) : Object(id, name), damage_(damage) {}

Weapon::Weapon(const Weapon &other):Object(other.getId(), other.getName(), other.getType()) {
    damage_ = other.getDamage();
}
Weapon::~Weapon(){}

std::string Weapon::recap()const{
    return "Weapon damage : " + std::to_string(damage_) + "\n";
}

std::string Weapon::info() const {
    return "Weapon: " + getName() + "#ID:" + getId() + ", Type: " + getType() + ", Damage: " + std::to_string(damage_) + "\n";
}

int Weapon::getDamage() const {
    return damage_;
}

void Weapon::setDamage(int damage) {
    damage_ = damage;
}
