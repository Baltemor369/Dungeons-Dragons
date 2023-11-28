#include "Weapon.h"

void Weapon::info()
{
    std::cout <<  "Weapon => "<< p_name << ": damage(" << std::to_string(p_damage) <<"), lethality("<< std::to_string(p_lethality) <<")\n";
}