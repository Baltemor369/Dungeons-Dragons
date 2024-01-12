#pragma once

#include "Object.h"

class Weapon : public Object {
private:
    int damage_;

public:
    Weapon(std::string name=Const::DEFAULT_WEAPON_NAME, int damage = Const::DEFAULT_WEAPON_DAMAGE): Object(name, Const::WEAPON), damage_(damage){}
    Weapon(const Weapon& weapon);
    ~Weapon();

    std::string info() const override;
    
    int getDamage() const;

    void setDamage(int damage);
};