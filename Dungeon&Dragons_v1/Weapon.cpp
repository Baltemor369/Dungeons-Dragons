#include "Weapon.h"
#include <iostream>
#include <string>

void Weapon::info()
{
    std::string text = "Weapon => "+ p_name + ": damage(" + std::to_string(p_damage) +"), lethality("+ std::to_string(p_lethality) +")\n";
    printf("%s", text.c_str());
}