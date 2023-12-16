#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <string>

class Object
{
private:
    std::string p_name;
    std::string p_type;
    int p_count, p_value;
    int p_damage, p_lethality, p_reach, p_resistance;
public:
    Object(std::string name, std::string type, 
            int count, int value, int damage, 
            int lethality, int reach, int resistance);
    ~Object();

    std::string get_name(){return p_name;}
    std::string get_type(){return p_type;}
    int get_count(){return p_count;}
    int get_value(){return p_value;}
    int get_damage(){return p_damage;}
    int get_lethality(){return p_lethality;}
    int get_reach(){return p_reach;}
    int get_resistance(){return p_resistance;}

    void set_count(int newValue);
    void set_value(int newValue);
    void set_damage(int newValue);
    void set_lethality(int newValue);
    void set_reach(int newValue);
    void set_resistance(int newValue);

    std::string info() const;
};

Object::Object(std::string name, std::string type, 
                int count, int value, int damage, 
                int lethality, int reach, int resistance)
                :p_name(name), p_type(type), p_count(count), p_value(value), 
                p_damage(damage), p_lethality(lethality), p_reach(reach), p_resistance(resistance)
{
}

Object::~Object()
{
}

std::string Object::info()const
{
    std::string text;
    if (p_type=="Weapon")
    {
        text = p_name + " : " + p_type + ", count("+ p_count +"), value("+ p_value;
        text += "), damage("+ p_damage +"), lethality("+ p_lethality +"), reach("+ p_reach +")";
    }else if (p_type=="Armor")
    {
        text = p_name + " : " + p_type + ", count("+ p_count +"), value("+ p_value;
        text += "), resistance("+ p_resistance +")";
    }else if (p_type=="Other")
    {
        text = p_name + " : " + p_type + ", count("+ p_count +"), value("+ p_value+")";
    }
    
    return text;
}

#endif
/*
gold;
copper_ore, iron_ore, steel_ore, ruby_ore, ebonite_ore, vulcanite_ore; // ores getable in mines or similar place (pickaxe)
copper_ingot, iron_ingot, steel_ingot, ruby_ingot, ebonite_ingot, vulcanite_ingot; // result of meltering fom ores
dragon_bone, ice_shard, hell_shard, shadow_shard, light_shard; // only getable on monster
weapons;
armors;
*/