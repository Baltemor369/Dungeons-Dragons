#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include"Armor.h"
#include "Inventory.h"
#include "Random.h"
#include "Coord.h"
#include "Const.h"

#include <iostream>
#include <string>
#include <vector>

class Character
{
private:
    std::string p_name; // pseudo
    Weapon p_weapon_equipped; // current equiped weapon
    Armor p_armor_equipped; // current equiped armor
    Inventory p_inventory; // inventory handler
    Coord p_pos; // character position
    int p_hp, p_velocity; // others stats
public:
    Character(std::string name,
                int x=0,
                int y=0,
                int hp=100,
                std::string weapon_name="Hand",
                int damage=1,
                int lethality=0,
                int reach=1,
                std::string armor_name="Clothes",
                int resistance=1,
                int p_gold,
                std::vector<int> ores,
                std::vector<int> ingots,
                std::vector<int> shards,
                std::vector<Weapon> p_weapons,
                std::vector<Armor> p_armors,
                int velocity=1);

    Character(const Character &other);
    Character& operator=(const Character &other);
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
