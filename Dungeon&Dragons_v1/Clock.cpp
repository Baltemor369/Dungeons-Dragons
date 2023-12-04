#include "Clock.h"

Clock::Clock()
{

}

Clock::~Clock()
{
}

void Clock::start_clock()
{
    p_start_time = std::chrono::steady_clock::now();
}

void Clock::restart_clock()
{
    p_start_time = std::chrono::steady_clock::now();
}

long long Clock::elapsed_time()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - p_start_time);
    return duration.count();
}