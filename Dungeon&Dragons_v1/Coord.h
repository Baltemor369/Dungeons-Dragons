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
    std::string get(){return "(" +std::to_string(x_)+","+std::to_string(y_)+")";}

    int getX()const{return x_;}
    int getY()const{return y_;}
    
    void setX(int newX){x_ = newX;}
    void setY(int newY){y_ = newY;}
};