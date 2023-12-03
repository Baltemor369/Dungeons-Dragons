#include "Ressources.h"

Ressources::~Ressources()
{
}

void Ressources::info()
{
    std::cout << "Gold=" <<p_gold <<std::endl;
}

void Ressources::add_loot(Ressources ressources)
{
    p_gold += ressources.get_gold();
}