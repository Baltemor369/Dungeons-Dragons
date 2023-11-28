#include "Armor.h"

void Armor::info()
{
    std::cout << "Armor => " << p_name << ": Physical Resistance("<< std::to_string(p_physical_resistance) <<")\n";
}