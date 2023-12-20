#include "../headers/Random.h"

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

void Random::setMin(int min)
{
    p_distribution = std::uniform_int_distribution<int>(min, p_distribution.max());
}

void Random::setMax(int max)
{
    p_distribution = std::uniform_int_distribution<int>(p_distribution.min(), max);
}

void Random::setBorder(int min, int max)
{
    this->setMin(min);
    this->setMax(max);
}