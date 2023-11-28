#include "Character.h"

Character::~Character()
{
}

void Character::info()
{
    std::cout << p_name << "(" << std::to_string(p_x) << "," << std::to_string(p_y) << ")" << " : Hp=" << std::to_string(p_hp) << ", velocity=" <<std::to_string(p_velocity)<<std::endl;
    p_weapon.info();
    p_armor.info();
    std::cout << std::endl;
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
    if (reachable(c2))
    {
        std::cout << this->p_name << " attack " << c2->get_name()<< " " << c2->get_hp() <<"Hp -> ";
        c2->deal_damage(&p_weapon);
        std::cout << c2->get_hp()<<"Hp"<< std::endl;

        if (!c2->is_alive())
        {
            std::cout << c2->get_name() << " is dead." << std::endl;
        }
        
    }
}

void Character::move(std::string dir)
{
    if (dir == "up")
    {
        std::cout << this->p_name << " moves upwards " << "(" << p_x << "," << p_y << ") -> (";
        p_y -= p_velocity;
        std::cout << p_x << "," << p_y << ")" << std::endl;
    }
    else if (dir == "down")
    {
        std::cout << this->p_name << " moves " << dir << "(" << p_x << "," << p_y << ") -> (";
        p_y += p_velocity;
        std::cout << p_x << "," << p_y << ")" << std::endl;
    }
    else if (dir == "right")
    {
        std::cout << this->p_name << " moves to the " << dir << "(" << p_x << "," << p_y << ") -> (";
        p_x += p_velocity;
        std::cout << p_x << "," << p_y << ")" << std::endl;
    }
    else if (dir == "left")
    {
        std::cout << this->p_name << " moves to the " << dir << "(" << p_x << "," << p_y << ") -> (";
        p_x -= p_velocity;
        std::cout << p_x << "," << p_y << ")" << std::endl;
    }
    
}

bool Character::reachable(Character* other)
{
    return distance(this, other) <= p_weapon.get_reach();
}

void Character::approach(Character* target) {
    // Calculer la différence entre les coordonnées actuelles et celles de la cible
    int dx = target->get_x() - p_x;
    int dy = target->get_y() - p_y;

    // Choisir la direction principale (priorité à l'axe le plus éloigné)
    if (std::abs(dx) > std::abs(dy)) {
        // Déplacement horizontal
        if ((dx > 0))
        {
            move("right");
        }else{
            move("left");
        }
    } else {
        // Déplacement vertical
        if ((dx > 0))
        {
            move("down");
        }else{
            move("up");
        }
    }
}

void Character::move_away(Character* target) {
    // Calculer la différence entre les coordonnées actuelles et celles de la cible
    int dx = target->get_x() - p_x;
    int dy = target->get_y() - p_y;

    // Choisir la direction principale (priorité à l'axe le plus éloigné)
    if (std::abs(dx) > std::abs(dy)) {
        // Déplacement horizontal
        p_x -= (dx > 0) ? p_velocity : (dx < 0) ? -p_velocity : 0;
    } else {
        // Déplacement vertical
        p_y -= (dy > 0) ? p_velocity : (dy < 0) ? -p_velocity : 0;
    }
}

//----------------------------------------------------------//

double distance(Character* obj1, Character* obj2) {
    return std::sqrt(std::pow(obj2->get_x() - obj1->get_x(), 2) + std::pow(obj2->get_y() - obj1->get_y(), 2));
}