#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include "Random.h"

class Weapon
{
private:
    std::string p_name;
    int p_damage, p_lethality, p_reach;
public:
    Weapon(std::string name="Hand", int damage=1, int lethality=0, int reach=1):p_name(name), p_damage(damage), p_lethality(lethality),p_reach(reach){};
    Weapon(const Weapon &other);
    ~Weapon(){};
    std::string get_name(){return p_name;}
    int get_damage(){return p_damage;}
    int get_lethality(){return p_lethality;}
    int get_reach(){return p_reach;}

    Weapon generator();
    void info();
};


#endif