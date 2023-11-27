#include "Armor.h"

#include <iostream>
#include <string>

void Armor::info()
{
    std::string text = "Armor => " + p_name + ": Physical Resistance("+ std::to_string(p_physical_resistance) +")\n";
    printf("%s", text.c_str());
}