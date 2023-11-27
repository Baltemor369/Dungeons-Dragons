#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string p_name;
    int p_damage, p_lethality;
public:
    Weapon(std::string name="Hand", int damage=1, int lethality=0):p_name(name), p_damage(damage), p_lethality(lethality){};
    ~Weapon(){};
    std::string get_name(){return p_name;}
    int get_damage(){return p_damage;}
    int get_lethality(){return p_lethality;}
    void info();
};


#endif