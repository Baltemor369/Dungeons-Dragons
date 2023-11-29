#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <random>
#include <map>
#include <string>
#include "Character.h"

class Game
{
private:
    bool p_running;
    std::map<std::string, Character> p_characters;
public:
    Game(/* args */);
    ~Game();

    void init();
    bool loop();
    void handle_evt(int* evt);
    void update_data();
    void refresh_grapĥic();
    bool add_character(std::string name, Character object);
};



#endif