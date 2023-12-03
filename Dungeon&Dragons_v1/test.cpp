#include <iostream>
#include <random>
#include <vector>

#include "Character.h"
#include <cmath>

using namespace std;

/*
g++ Character.cpp Weapon.cpp Armor.cpp Ressources.cpp test.cpp -o test
*/

int main(int argc, char const *argv[])
{
    Character bob("Bob", 5, 5);
    Character jack("Jack", 0, 0);

    // test approach
    bool test_approach(true);
    double last_dist = 100;
    for (int i = 0; i < 10; i++)
    {
        bob.approach(&jack);
        double buff = distance(&bob, &jack);
        if (buff > last_dist)
        {
            test_approach = false;
        }else{
            last_dist = buff;
        }
    }
    // test move_away
    bool test_moveaway(true);
    last_dist = 0;
    for (int i = 0; i < 10; i++)
    {
        bob.move_away(&jack);
        double buff = distance(&bob, &jack);
        if (buff < last_dist)
        {
            test_moveaway = false;
        }else{
            last_dist = buff;
        }
    }

    // random test
    bool test_random(true);
    Random rd(0,5);
    
    for (int i = 0; i < 10; i++)
    {
        std::cout << rd.getRandomNumber() << std::endl;
        if (!(0 <= rd.getRandomNumber() <= 5))
        {
            test_random = false;
        }
    }
    
    // random move test
    bool test_random_move(false);
    int x = bob.get_x();
    int y = bob.get_y();
    bob.random_move();
    int x2 = bob.get_x();
    int y2 = bob.get_y();

    if (x != x2 or y != y2)
    {
        test_random_move = true;
    }
    
    
    cout << "test_approach : "<< test_approach << endl;
    cout << "test_moveaway : "<< test_moveaway << endl;
    cout << "test_random : "<< test_random << endl;
    cout << "test_random_move : "<< test_random_move << endl;

    return 0;
}

