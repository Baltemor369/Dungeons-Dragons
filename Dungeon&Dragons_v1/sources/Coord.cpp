#include "../headers/Coord.h"

Coord::Coord(int x, int y):x_(x), y_(y)
{
}

Coord::~Coord()
{
}

std::string Coord::info() const {
    std::string text;
    text += "(" + std::to_string(x_) + "," + std::to_string(y_) + ")\n";
    return text;
}