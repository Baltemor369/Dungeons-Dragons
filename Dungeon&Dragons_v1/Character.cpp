#include "Character.h"

Character::Character(std::string name, int x, int y, int hp, Weapon weapon, Armor armor, Ressources ressources, int velocity)
{
    p_name = name;
    p_hp = hp; 
    p_weapon_equipped = weapon; 
    p_armor_equipped = armor; 
    p_x = x; 
    p_y = y; 
    p_velocity = velocity;
}

Character::Character(const Character &other)
{
    p_name = other.p_name;
    p_weapon_equipped = other.p_weapon_equipped;
    p_armor_equipped = other.p_armor_equipped;
    p_ressources = other.p_ressources;
    p_hp = other.p_hp;
    p_velocity = other.p_velocity;
    p_x = other.p_x;
    p_y = other.p_y;
}

Character& Character::operator=(const Character &other)
{
    p_name = other.p_name;
    p_weapon_equipped = other.p_weapon_equipped;
    p_armor_equipped = other.p_armor_equipped;
    p_ressources = other.p_ressources;
    p_hp = other.p_hp;
    p_velocity = other.p_velocity;
    p_x = other.p_x;
    p_y = other.p_y;
    return *this;
}

Character::~Character()
{
}

void Character::info()
{
    std::cout << p_name << "(" << std::to_string(p_x) << "," << std::to_string(p_y) << ")" << " : \nHp=" << std::to_string(p_hp) << ", \nvelocity=" <<std::to_string(p_velocity)<<std::endl;
    p_ressources.info();
    p_weapon_equipped.info();
    p_armor_equipped.info();
    std::cout << std::endl;
}

void Character::deal_damage(Weapon* weapon)
{    
    p_hp -= weapon->get_lethality();
    int overdamage = (weapon->get_damage()-weapon->get_lethality()) - p_armor_equipped.get_resist_phys();
    if (overdamage > 0)
    {
        p_hp -= overdamage;
        if (p_hp < 0)
        {
            p_hp = 0;
        }
    }
}

void Character::attack(Character* target)
{   
    if (this->is_alive() && this->reachable(target))
    {
        std::cout << this->p_name << " attack " << target->get_name()<< " " << target->get_hp() <<"Hp -> ";
        target->deal_damage(&p_weapon_equipped);
        std::cout << target->get_hp()<<"Hp"<< std::endl;

        if (!target->is_alive())
        {
            looting(target);
            std::cout << target->get_name() << " is dead." << std::endl;
            std::cout << "Ressources earned : " << std::endl;
            target->get_ressources().info();
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

void Character::random_move()
{
    Random generator(0,4);
    this->move(Const::DIRECTIONS[generator.getRandomNumber()]);
}

bool Character::reachable(Character* other)
{
    return distance(this, other) <= p_weapon_equipped.get_reach();
}

void Character::approach(Character* target) {
    int dx = target->get_x() - p_x;
    int dy = target->get_y() - p_y;

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
        if ((dy > 0))
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
        if ((dx > 0))
        {
            move("left");
        }else{
            move("right");
        }
    } else {
        // Déplacement vertical
        if ((dy > 0))
        {
            move("up");
        }else{
            move("down");
        }
    }
}

void Character::looting(Character* other)
{
    p_ressources.add_loot(other->get_ressources());
}

//----------------------------------------------------------//

double distance(Character* obj1, Character* obj2) {
    return std::sqrt(std::pow(obj2->get_x() - obj1->get_x(), 2) + std::pow(obj2->get_y() - obj1->get_y(), 2));
}