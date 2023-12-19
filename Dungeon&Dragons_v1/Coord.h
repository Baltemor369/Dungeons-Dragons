#pragma once

class Coord
{
private:
    int p_x, p_y;
public:
    Coord(int x, int y);
    ~Coord();
    Coord operator+(const Coord& other) const;

    int getX()const{return p_x;}
    int getY()const{return p_y;}
    
    void setX(int newX){p_x = newX;}
    void setY(int newY){p_y = newY;}
};