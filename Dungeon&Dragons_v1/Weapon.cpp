#include "Weapon.h"

Weapon::Weapon(const Weapon &other)
{
    p_name = other.p_name;
    p_damage = other.p_damage;
    p_lethality = other.p_lethality;
    p_reach = other.p_reach;
}

Weapon Weapon::generator()
{
    Random generator(1,15);
    int randomDmg = generator.getRandomNumber();
    generator.set_border(0,8);
    int randomLetha = generator.getRandomNumber();
    while (randomLetha >= randomDmg)
    {
        randomLetha = generator.getRandomNumber();
    }
    
    
}

void Weapon::info()
{
    std::cout <<  "Weapon => "<< p_name << ": damage(" << std::to_string(p_damage) <<"), lethality("<< std::to_string(p_lethality) <<")\n";
}