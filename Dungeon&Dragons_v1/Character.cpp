#include "Character.h"
#include <iostream>

Character::~Character()
{
}

void Character::set_move_up(bool val)
{
    p_move_up = val;
}
void Character::set_move_down(bool val)
{
    p_move_down = val;
}
void Character::set_move_right(bool val)
{
    p_move_right = val;
}
void Character::set_move_left(bool val)
{
    p_move_left = val;
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
    c2->deal_damage(&p_weapon);
}

void Character::move()
{
    if (p_move_up)
    {
        p_y -= p_velocity;
    }
    else if (p_move_down)
    {
        p_y += p_velocity;
    }
    else if (p_move_right)
    {
        p_x += p_velocity;
    }
    else if (p_move_left)
    {
        p_x -= p_velocity;
    }
    
}