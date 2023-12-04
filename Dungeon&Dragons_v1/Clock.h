#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
#include <thread>

class Clock
{
private:
    std::chrono::steady_clock::time_point p_start_time;
public:
    Clock();
    ~Clock();

    void start_clock();
    void restart_clock();
    long long elapsed_time();
};



#endif