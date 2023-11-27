#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
private:
    bool p_running;
    sf::Event p_evt; // event handler
    sf::Clock p_clock; // Clock handler
public:
    Game(/* args */);
    ~Game();

    bool loop();
    void handle_evt(int* evt);
    void update_data();
    void refresh_grapĥic();
};



#endif