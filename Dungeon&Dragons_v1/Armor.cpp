#include "Armor.h"

Armor::Armor(const Armor &other)
{
    p_name = other.p_name;
    p_physical_resistance = other.p_physical_resistance;
}

void Armor::info()
{
    std::cout << "Armor => " << p_name << ": Physical Resistance("<< std::to_string(p_physical_resistance) <<")\n";
}