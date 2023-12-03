#include "Random.h"

Random::Random(int min, int max):p_distribution(min,max), p_generator(p_rd())
{
}

Random::~Random()
{
}

int Random::getRandomNumber()
{
    return p_distribution(p_generator);
}

void Random::set_min(int min)
{
    p_distribution = std::uniform_int_distribution<int>(min, p_distribution.max());
}

void Random::set_max(int max)
{
    p_distribution = std::uniform_int_distribution<int>(p_distribution.min(), max);
}

void Random::set_border(int min, int max)
{
    this->set_min(min);
    this->set_max(max);
}