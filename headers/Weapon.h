#pragma once

#include "Object.h"

class Weapon : public Object {
private:
    int damage_, penetringArmor_;

public:
    Weapon(std::string name=Const::DEFAULT_WEAPON_NAME, int damage = Const::DEFAULT_WEAPON_DAMAGE, int penetringArmor=Const::DEFAULT_WEAPON_PENETRING): Object(name, Const::WEAPON), damage_(damage), penetringArmor_(penetringArmor){}
    Weapon(const Weapon& weapon);
    ~Weapon();

    std::string info() const override;
    
    int getDamage() const{return damage_;}
    int gePenetringArmor() const{return penetringArmor_;}

    void setDamage(int damage);
};