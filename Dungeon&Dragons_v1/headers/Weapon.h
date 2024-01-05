#pragma once

#include "Object.h"

class Weapon : public Object {
private:
    int damage_;

public:
    Weapon(std::string id, std::string name = Const::DEFAULT_WEAPON, int damage = 1);
    Weapon(const Weapon& weapon);
    ~Weapon();

    std::string recap()const;
    std::string info() const override;

    int getDamage() const;

    void setDamage(int damage);
};