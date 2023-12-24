#pragma once

#include <vector>
#include "Character.h"

class Group
{
private:
    std::vector<Character*> people_;
public:
    Group();
    ~Group();

    std::string info()const;

    void addCharacter(Character* character);
    void removeCharacter(std::string name);
    Character* getACharacter(std::string name);
    std::vector<Character*> getAllCharacters();

    void clear();
};