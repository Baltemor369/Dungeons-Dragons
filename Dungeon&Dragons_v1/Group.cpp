#include "../headers/Group.h"

Group::Group()
{
}

Group::~Group()
{
}

std::string Group::info()const
{
    std::string text;
    text += "Group :\n";
    for(auto& elt : people_){
        text += elt->info() + "\n";
    }
    return text;
}

void Group::addCharacter(Character* character)
{
    // Add character to the vector
    people_.push_back(character);
}

void Group::removeCharacter(std::string name)
{
    int i(0);
    for (auto& elt : people_)
    {
        if (elt->getName() == name)
        {
            people_.erase(people_.begin()+i);
            break;
        }
        ++i;
    }
}

Character* Group::getACharacter(std::string name)
{
    for (auto elt : people_)
    {
        if (elt->getName() == name)
        {
            return elt;
        }
    }

    // Character not found, return nullptr
    return nullptr;
}

std::vector<Character*> Group::getAllCharacters()
{
    return people_;
}

void Group::clear(){
    for(auto& elt : people_){
        delete elt;
    }
    people_.clear();
}