#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include"Armor.h"
#include "Ressources.h"
#include "Random.h"
#include "Utils.h"

#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <thread>

class Character
{
private:
    Random generator;
    std::string p_name;
    Weapon p_weapon_equipped;
    Armor p_armor_equipped;
    Ressources p_ressources;
    int p_hp, p_velocity;
    int p_x, p_y;
public:
    Character(std::string name, int x=0, int y=0, int hp=100, Weapon weapon=Weapon(), Armor armor=Armor(), Ressources ressource=Ressources(), int velocity=1);
    Character():p_name("None"), p_hp(-1), p_weapon_equipped(Weapon()), p_armor_equipped(Armor()), p_x(0), p_y(0), p_velocity(-1), generator(0,4){}
    ~Character();

    void info();

    std::string get_name() { return p_name;}
    Weapon get_weapon() { return p_weapon_equipped;}
    Armor get_armor() { return p_armor_equipped;}
    Ressources get_ressources() { return p_ressources;}
    int get_hp() { return p_hp; }
    int get_velocity() { return p_velocity; }
    int get_x() { return p_x; }
    int get_y() { return p_y; }

    void deal_damage(Weapon* weapon);
    void attack(Character* target);
    void move(std::string dir);
    void random_move();
    bool reachable(Character* other);
    void approach(Character* target);
    void move_away(Character* target);
    bool is_alive(){return p_hp > 0;}
    void looting(Character* other);
};

double distance(Character* obj1, Character* obj2);

#endif
