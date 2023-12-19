#include "../headers/Character.h"

Character::Character(std::string name, int x, int y, int hp, int velocity, std::string weaponName, int weaponDamage):name_(name), location_(x,y), hp_(hp), velocity_(velocity), equipedWeapon_(0)
{
    equipedWeapon_ = new Weapon(weaponName, weaponDamage);
}

Character::~Character()
{
    inventory_.clearInventory();
    delete equipedWeapon_;
}

std::string Character::info()const
{
    std::string text;
    text = name_ + getLocation().get() + ": hp(" + std::to_string(hp_) + "), velocity(" + std::to_string(velocity_) + ")\n" + equipedWeapon_->info() + inventory_.info();
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

std::string Character::move(std::string direction) {
    Coord currentLocation = getLocation();
    int deltaX(0);
    int deltaY(0);

    if (direction == "up")
    {
        deltaY = velocity_;
    }else if (direction == "right")
    {
        deltaX = velocity_;
    }else if (direction == "left")
    {
        deltaX = -velocity_;
    }else if (direction == "down")
    {
        deltaY = -velocity_;
    }

    Coord newLocation = currentLocation + Coord(deltaX, deltaY);
    
    setLocation(newLocation);

    return getName() + " move to " + newLocation.get() + "\n";
}

void Character::addToInventory(Object* item) {
    inventory_.addItem(item);
}

void Character::removeFromInventory(Object* item) {
    inventory_.removeItem(item);
}

std::string Character::approachCharacter(const Character& target) {
    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = targetLocation.getX() - currentLocation.getX();
    int deltaY = targetLocation.getY() - currentLocation.getY();
    
    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance >= getVelocity()) {
        std::string direction;
        if (deltaX != 0 && std::abs(deltaX) > std::abs(deltaY))
        {
            direction = (deltaX > 0) ? "right" : "left";            
        }
        if(deltaY !=0 && std::abs(deltaX) < std::abs(deltaY)){
            direction = (deltaY > 0) ? "up" : "down";
        }
        
        return name_ + " is approaching " + target.getName() + "\n" + move(direction);
    }
    return name_ + " can reach " + target.getName() + "\n";
}

std::string Character::fleeCharacter(const Character& target) {
    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = currentLocation.getX() - targetLocation.getX();
    int deltaY = currentLocation.getY() - targetLocation.getY();

    std::string direction;
    if (std::abs(deltaX) < std::abs(deltaY))
    {
        direction = (deltaX > 0) ? "right" : "left";
    }else{
        direction = (deltaY > 0) ? "up" : "down";
    }
    

    return name_ + " is moving away from " + target.getName() + "\n" + move(direction);
}