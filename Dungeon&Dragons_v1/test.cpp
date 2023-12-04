#include <iostream>
#include <random>
#include <vector>

#include "Character.h"
#include "Clock.h"
#include <cmath>

using namespace std;

/*
g++ Character.cpp Weapon.cpp Armor.cpp Ressources.cpp Random.cpp test.cpp -o test
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
            cout << "test_approach : Failed" << endl;
        }else{
            last_dist = buff;
        }
    }
    if (test_approach)
    {
        cout << "test_approach : Succeeded" << endl;
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
            cout << "test_moveaway : Failed"<< endl;
        }else{
            last_dist = buff;
        }
    }
    if (test_moveaway)
    {
        cout << "test_moveaway : Succeed"<< endl;
    }
    
    

    // random test
    bool test_random(true);
    Random rd(0,5);
    
    for (int i = 0; i < 10; i++)
    {
        if (!(0 <= rd.getRandomNumber() <= 5))
        {
            test_random = false;
            cout << "test_random : Failed" << endl;
        }
    }
    if (test_random)
    {
        cout << "test_random : Succeeded" << endl;
    }
    
    // random move test
    int x = bob.get_x();
    int y = bob.get_y();
    bob.random_move();
    int x2 = bob.get_x();
    int y2 = bob.get_y();

    if (x != x2 or y != y2)
    {
        cout << "test_random_move : Succeeded " << endl;
    }else{
        cout << "test_random_move : Failed " << endl;
    }

    // clock test
    Clock myClock;
    myClock.start_clock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (myClock.elapsed_time() > 2)
    {
        cout << "test_start : Succeeded" <<  endl;
    }else{
        cout << "test_start : Failed" <<  endl;
    }
    myClock.restart_clock();
    if (myClock.elapsed_time() < 1)
    {
        cout << "test_restart : Succeeded" <<  endl;
    }else{
        cout << "test_restart : Failed" <<  endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (myClock.elapsed_time() > 1)
    {
        cout << "test_elapsed_time : Succeeded" <<  endl;
    }else{
        cout << "test_elapsed_time : Failed" <<  endl;
    }

    return 0;
}

