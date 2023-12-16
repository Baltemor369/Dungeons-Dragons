#include "Coord.h"

Coord::Coord(int x, int y):p_x(x), p_y(y)
{
}

Coord::~Coord()
{
}

Coord Coord::operator+(const Coord& other) const {
    return Coord(p_x + other.p_x, p_y + other.p_y);
}

Coord Coord::operator-(const Coord& other) const {
    return Coord(p_x - other.p_x, p_y - other.p_y);
}

Coord Coord::operator<<(const Coord& other) const {
    return Coord(p_x << other.p_x, p_y << other.p_y);
}

Coord Coord::operator>>(const Coord& other) const {
    return Coord(p_x >> other.p_x, p_y >> other.p_y);
}