#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <thread>
        
class Random
{
private:
    std::random_device p_rd;
    std::mt19937 p_generator;
    std::uniform_int_distribution<int> p_distribution;
public:
    Random(int min=0, int max=1);
    ~Random();
    
    int getRandomNumber();

    void setMin(int min);
    void setMax(int max);
    void setBorder(int min, int max);
};

#endif