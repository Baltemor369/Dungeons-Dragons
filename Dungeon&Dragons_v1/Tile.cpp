#include "../headers/Tile.h"

Tile::Tile(int x, int y, bool visited):visited_(visited), location_(x,y)
{
}

Tile::~Tile()
{
}

void Tile::enterPerson(Character *person){
    people_.addCharacter(person);
}

void Tile::exitPerson(Character *person){
    people_.removeCharacter(person->getName());
}

void Tile::clearPeople(){
    people_.clear();
}