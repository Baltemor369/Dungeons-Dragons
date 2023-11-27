#include "Character.h"
#include <iostream>

Character::~Character()
{
}

void Character::info()
{
    std::string text;
    text = p_name + "(" + std::to_string(p_x) + "," + std::to_string(p_y) + ")" + " : Hp=" + std::to_string(p_hp) + ", velocity=" +std::to_string(p_velocity)+"\n";
    printf("%s", text.c_str());
    p_weapon.info();
    p_armor.info();
    printf("\n");
}

void Character::deal_damage(Weapon* weapon)
{    
    p_hp -= weapon->get_lethality();
    int overdamage = (weapon->get_damage()-weapon->get_lethality()) - p_armor.get_resist_phys();
    if (overdamage > 0)
    {
        p_hp -= overdamage;
        if (p_hp < 0)
        {
            p_hp = 0;
        }
    }
}

void Character::attack(Character* c2)
{   
    if (p_x == c2->p_x && p_y == c2->p_y);
    {
        c2->deal_damage(&p_weapon);
    }
}

void Character::move(std::string dir)
{
    if (dir == "up")
    {
        p_y -= p_velocity;
    }
    else if (dir == "down")
    {
        p_y += p_velocity;
    }
    else if (dir == "right")
    {
        p_x += p_velocity;
    }
    else if (dir == "left")
    {
        p_x -= p_velocity;
    }
    
}