#pragma once

#include "Object.h"

class Weapon : public Object {
private:
    int damage_;
    int lethality_; // => % of damage
    int vampirism_; // => % of damage

public:
    Weapon():
        Object(Const::DEFAULT_WEAPON_NAME, Const::WEAPON), damage_(Const::DEFAULT_WEAPON_DAMAGE), lethality_(Const::DEFAULT_WEAPON_LETHALITY), vampirism_(Const::DEFAULT_WEAPON_VAMPIRISM){}
    Weapon(std::string name, int damage , int lethality, int vampirism):
        Object(name, Const::WEAPON), damage_(damage), lethality_(lethality), vampirism_(vampirism){}
    Weapon(const Weapon& weapon);
    ~Weapon();

    std::string info() const override;
    
    int getDamage() const{return damage_;}
    int getLethality() const{return lethality_;}
    int getVampirism() const{return vampirism_;}

    void setDamage(int value){damage_ = value;}
    void setLethality(int value){lethality_ = value;}
    void setVampirism(int value){vampirism_ = value;}
};