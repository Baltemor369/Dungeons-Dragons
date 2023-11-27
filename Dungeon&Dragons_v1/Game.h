#ifndef GAME_H
#define GAME_H


class Game
{
private:
    bool p_running;
public:
    Game(/* args */);
    ~Game();

    bool loop();
    void handle_evt(int* evt);
    void update_data();
    void refresh_graphic();
};



#endif