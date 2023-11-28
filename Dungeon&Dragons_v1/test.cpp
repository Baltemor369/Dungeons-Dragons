#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <vector>

#include "Character.h"

using namespace std;

/*
g++ Character.cpp Weapon.cpp Armor.cpp test.cpp -o test
*/

int main(int argc, char const *argv[])
{
    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<std::string> directions = {"up","down","left","right"};
    std::uniform_int_distribution<int> distribution(0, directions.size()-1);

    Character villain("Joker", 120, Weapon("Massue",4,1), Armor(),5,5,1);
    Character hero("Batman", 60, Weapon("Dag",9,4), Armor("Ebenite",15),5,0,1);

    
    while (hero.get_hp() != 0 && villain.get_hp() != 0)
    {
        villain.info();
        hero.info();

        villain.attack(&hero);
        hero.attack(&villain);

        int randomNumber = distribution(generator);
        if (directions[randomNumber] == "up" && hero.get_y() < 5) {
            hero.move("down");
        } else if (directions[randomNumber] == "down" && hero.get_y() > 0) {
            hero.move("up");
        } else if (directions[randomNumber] == "left" && hero.get_x() > 0) {
            hero.move("left");
        } else if (directions[randomNumber] == "right" && hero.get_x() < 5) {
            hero.move("right");
        }

        int randomIndex = distribution(generator);
        if (directions[randomIndex] == "up" && villain.get_y() < 5) {
            villain.move("down");
        } else if (directions[randomIndex] == "down" && villain.get_y() > 0) {
            villain.move("up");
        } else if (directions[randomIndex] == "left" && villain.get_x() > 0) {
            villain.move("left");
        } else if (directions[randomIndex] == "right" && villain.get_x() < 5) {
            villain.move("right");
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    villain.info();
    hero.info();

    return 0;
}