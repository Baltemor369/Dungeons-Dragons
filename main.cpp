#include "headers/Game.h"

using namespace std;

/*
g++ sources/* main.cpp -o game

TODO : 
- define skills
- define all items need for the game ( Weapon Armor Other)
- add craft components
- add crafting
- add a map handler for pre-generation of events and ensure that events are not repeated in locations where the player has already been.
- add Events

NEXT MISSION :
1 - refaire looting 
2 - empêcher le doublon de nom -> list des noms existants ?
3 - créer le crafting
4 - créer les objet pour le jeu (minerais - composants)
*/

int main(int argc, char const *argv[])
{
    // Player Creation
    string playerName("");
    cout << "Enter your character name :";
    while (playerName == "")
    {
        getline(cin, playerName);
    }
    
    // data init
    Game game(playerName);
    game.loop();
    
    return 0;
}