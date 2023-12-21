#include "../headers/Tile.h"

Tile::Tile(int x, int y, bool visited):visited_(visited), location_(x,y)
{
}

Tile::~Tile()
{
}

void Tile::addPerson(Character *person){
    people_.push_back(person);
}

void Tile::removePerson(Character *person){
    for (auto it = people_.begin(); it != people_.end(); ++it){
        if (*it == person){
            people_.erase(it);
        }
    }
}