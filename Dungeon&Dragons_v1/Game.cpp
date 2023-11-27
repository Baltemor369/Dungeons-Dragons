#include "Game.h"

Game::Game(/* args */)
{
}

Game::~Game()
{
}

bool Game::loop()
{
    p_clock.restart();

    while(p_running)
    {
        //handle_event(&p_evt);
        //update_data();
        //refresh_graphic();
    }
    
    return true;
}

void Game::handle_evt(int* evt)
{

}

void Game::update_data()
{

}

void Game::refresh_grapĥic()
{
    
}