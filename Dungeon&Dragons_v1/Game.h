#ifndef GAME_H
#define GAME_H

#include <random>
#include <map>
#include <string>
#include "Character.h"
#include "Clock.h"
#include "Random.h"

class Game
{
private:
    bool p_running;
    std::map<std::string, Character> p_characters;
    Clock p_ennemy_spawn_timer;
    Random p_generator;
    
public:
    Game(/* args */);
    ~Game();

    void init();
    bool loop();
    void handle_evt(int* evt);
    void update_data();
    bool add_character(std::string name, Character object);
    Character generate_monster();
};



#endif