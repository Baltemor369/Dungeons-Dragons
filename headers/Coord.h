#pragma once

#include <string>

class Coord
{
private:
    int x_, y_;
public:
    Coord(int x, int y);
    ~Coord();
    Coord operator+(const Coord& other) const{return Coord(x_ + other.getX(), y_ + other.getY());};
    friend bool operator==(const Coord& c1, const Coord& c2){return (c1.getX() == c2.getX()) && (c1.getY() == c2.getY());}
    std::string info()const;

    int getX()const{return x_;}
    int getY()const{return y_;}
    
    void setX(int newX){x_ = newX;}
    void setY(int newY){y_ = newY;}
};