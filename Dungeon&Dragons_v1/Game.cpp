#include "Game.h"

Game::Game(/* args */)
{
}

Game::~Game()
{
}

void Game::init()
{
    Character villain("Joker", 120, Weapon("Massue",4,1), Armor(),5,3,1);
    Character hero("Batman", 60, Weapon("Dag",9,4), Armor("Ebenite",15),0,3,1);

}

bool Game::loop()
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<std::string> directions = {"up","down","left","right"};
    std::uniform_int_distribution<int> distribution(0, directions.size()-1);

    

    while(p_running)
    {
        //handle_event(&p_evt);
        update_data();
        //refresh_graphic();
    }
    
    return true;
}

void Game::handle_evt(int* evt)
{

}

void Game::update_data()
{
    if (!hero.reachable(&villain))
        {
            hero.approach(&villain);
        }
        if(!villain.reachable(&hero))
        {
            bool move_done(false);
            while(!move_done)
            {
                int randomIndex = distribution(generator);
                if (directions[randomIndex] == "up" && villain.get_y() < 5) {
                    move_done = true;
                    villain.move("down");
                } else if (directions[randomIndex] == "down" && villain.get_y() > 0) {
                    move_done = true;
                    villain.move("up");
                } else if (directions[randomIndex] == "left" && villain.get_x() > 0) {
                    move_done = true;
                    villain.move("left");
                } else if (directions[randomIndex] == "right" && villain.get_x() < 5) {
                    move_done = true;
                    villain.move("right");
                }
            }
        }
    if (p_characters["hero"].get_hp() != 0 && p_characters["villain"].get_hp() != 0)
    {
        p_running = false;
    }   
}

void Game::refresh_grapĥic()
{
    
}

bool Game::add_character(std::string name, Character object)
{
    if (p_characters.find(name) == p_characters.end())
    {
        p_characters[name] = object;
        return true;
    }
    return false;
    
    
}