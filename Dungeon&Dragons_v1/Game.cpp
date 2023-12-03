#include "Game.h"

#define MAX_WIDTH 10
#define MIN_WIDTH -10
#define MAX_HEIGHT 10
#define MIN_HEIGHT -10

Game::~Game()
{
}

void Game::init()
{
    // create the player caractere;
    std::string pseudo;
    std::cout << "enter your name :";
    std::cin >> pseudo;
    // default weapon
    // default armor
    // empty ressources
    // default hp and velocity
    // position (0,0)

    Character player(pseudo,0,0);
    add_character("player", player);
};

bool Game::loop()
{
    p_start_time = std::chrono::steady_clock::now();
    int test;
    while(p_running)
    {
        update_data();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    return true;
}

void Game::handle_evt(int* evt)
{

}

void Game::update_data()
{
    // get characters
    Character* player = &p_characters["player"];

    auto current_time = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - p_start_time).count();
    
    std::cout << elapsed_time << std::endl;
    
    if (elapsed_time >= 10)
    {
        //generer un monstre sur la carte
    }
    

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