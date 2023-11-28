#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <vector>

#include "Character.h"

using namespace std;

/*
g++ Character.cpp Weapon.cpp Armor.cpp Utils.cpp test.cpp -o test
*/

int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<std::string> directions = {"up","down","left","right"};
    std::uniform_int_distribution<int> distribution(0, directions.size()-1);

    Character villain("Joker", 120, Weapon("Massue",4,1), Armor(),5,3,1);
    Character hero("Batman", 60, Weapon("Dag",9,4), Armor("Ebenite",15),0,3,1);

    while (hero.get_hp() != 0 && villain.get_hp() != 0)
    {
        villain.attack(&hero);
        hero.attack(&villain);

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
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    

    return 0;
}