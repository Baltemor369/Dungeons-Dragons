#include "../headers/Character.h"

Character::Character(std::string name, int x, int y, int hp, int velocity):name_(name), location_(x,y), hp_(hp), velocity_(velocity)
{}

Character::~Character()
{}

std::string Character::info()const
{
    std::string text;
    text = name_ + "(" + std::to_string(location_.getX()) + "," + std::to_string(location_.getY()) + "): hp(" + std::to_string(hp_) + "), velocity(" + std::to_string(velocity_) + ")\n";
    return text;
}

void Character::setName(const std::string& name) {
    name_ = name;
}

void Character::setLocation(const Coord& location) {
    location_ = location;
}

void Character::setHP(int hp) {
    hp_ = hp;
}

void Character::setVelocity(int velocity) {
    velocity_ = velocity;
}

std::string Character::move(int deltaX, int deltaY) {
    Coord currentLocation = getLocation();

    Coord newLocation = currentLocation + Coord(deltaX, deltaY);

    setLocation(newLocation);

    return getName() + " move to (" + std::to_string(newLocation.getX()) + ", " + std::to_string(newLocation.getY()) + ")\n";
}

void Character::addToInventory(Object* item) {
    inventory_.addItem(item);
}

void Character::removeFromInventory(Object* item) {
    inventory_.removeItem(item);
}

std::string Character::infoInventory() const {
    return inventory_.info();
}

std::string Character::approachCharacter(const Character& target) {
    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = targetLocation.getX() - currentLocation.getX();
    int deltaY = targetLocation.getY() - currentLocation.getY();

    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > getVelocity()) {
        int moveX = static_cast<int>(std::round((deltaX / distance) * getVelocity()));
        int moveY = static_cast<int>(std::round((deltaY / distance) * getVelocity()));

        return move(moveX, moveY);
    }
    return "";
}

std::string Character::fleeCharacter(const Character& target) {
    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = currentLocation.getX() - targetLocation.getX();
    int deltaY = currentLocation.getY() - targetLocation.getY();

    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    
    int moveX = static_cast<int>(std::round((deltaX / distance) * getVelocity()));
    int moveY = static_cast<int>(std::round((deltaY / distance) * getVelocity()));

    return move(-moveX, -moveY);
}