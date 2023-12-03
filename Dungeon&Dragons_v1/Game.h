#ifndef GAME_H
#define GAME_H

#include <random>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include "Character.h"
#include "Utils.h"

class Game
{
private:
    bool p_running;
    std::map<std::string, Character> p_characters;
    
    
    std::chrono::steady_clock::time_point p_start_time;
public:
    Game(/* args */):{};
    ~Game();

    void init();
    bool loop();
    void handle_evt(int* evt);
    void update_data();
    bool add_character(std::string name, Character object);
};



#endif