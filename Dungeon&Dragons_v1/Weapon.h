#pragma once

#include "Object.h"

class Weapon : public Object {
private:
    int damage_;

public:
    Weapon(std::string name = "Hands", int damage = 1);

    std::string info() const override;

    int getDamage() const;

    void setDamage(int damage);
};