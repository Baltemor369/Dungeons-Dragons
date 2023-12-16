#ifndef COORD_H
#define COORD_H

class Coord
{
private:
    int p_x,p_y;
public:
    Coord(int x, int y);
    ~Coord();
    Coord operator+(const Coord& other) const;
    Coord operator-(const Coord& other) const;
    Coord operator<<(const Coord& other) const;
    Coord operator>>(const Coord& other) const;
};

#endif