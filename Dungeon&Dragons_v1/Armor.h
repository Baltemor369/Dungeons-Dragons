#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <string>

class Armor
{
private:
    std::string p_name;
    int p_physical_resistance;
public:
    Armor(std::string name="Clothes", int resistance=1):p_name(name), p_physical_resistance(resistance){};
    ~Armor(){};
    void info();

    std::string get_name(){return p_name;}
    int get_resist_phys(){return p_physical_resistance;}
};


#endif