#ifndef RESSOURCES_H
#define RESSOURCES_H

#include "Weapon.h"
#include "Armor.h"
#include "Random.h"

#include <iostream>
#include <vector>

class Ressources
{
private:
    int p_gold; // money
    int p_copper_ore, p_iron_ore, p_steel_ore, p_ruby_ore, p_ebonite_ore, p_vulcanite_ore; // ores getable in mines or similar place (pickaxe)
    int p_copper_ingot, p_iron_ingot, p_steel_ingot, p_ruby_ingot, p_ebonite_ingot, p_vulcanite_ingot; // result of meltering fom ores
    int p_dragon_bone, p_ice_shard, p_hell_shard, p_shadow_shard, p_light_shard; // only getable on monster
    std::vector<Weapon> p_weapons;
    std::vector<Armor> p_armors;
public:
    Ressources(int gold=0):p_gold(gold){};
    ~Ressources();

    void info();
    
    int get_gold(){return p_gold;}

    void add_loot(Ressources ressources);
};


#endif