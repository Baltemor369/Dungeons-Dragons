#ifndef GAME_H
#define GAME_H

#include <map>
#include <string>
#include "Character.h"

class Game
{
private:
    bool p_running;
    std::map<std::string, Character> p_characters;
    
public:
    Game();
    ~Game();

    void init();
    bool loop();
    void update_data();
    bool add_character(std::string name, Character object);
};



#endif