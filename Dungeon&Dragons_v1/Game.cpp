#include "Game.h"

#define MAX_WIDTH 10
#define MIN_WIDTH -10
#define MAX_HEIGHT 10
#define MIN_HEIGHT -10

Game::Game()
{

}

Game::~Game()
{
}

void Game::init()
{
    // create the player charactere;
    std::string pseudo;
    std::cout << "enter your name :";
    std::cin >> pseudo;
    std::endl;

    Character player(pseudo,0,0);
    add_character("player", player);
};

bool Game::loop()
{
    p_running = true;
    while(p_running)
    {
        std::string choice;
        // player choices list, selection and execution
        std::cout << "Choose a action : ";
        std::cin >> choice;
        std::endl;
        
        update_data();

    }
    
    return true;
}

void Game::update_data()
{
    // get characters
    Character* player = &p_characters["player"];

    if (player->get_hp() == 0)
    {
        p_running = false;
    }   
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