#include "../headers/Character.h"

Character::Character(std::string name, int x, int y, int hp, int velocity,Weapon* weapon, Armor* armor):name_(name), location_(x,y), hp_(hp), velocity_(velocity), equipedWeapon_(weapon), equipedArmor_(armor){}

Character::Character(std::string name, std::string armorName, int armorProtection, std::string weaponName, int weaponDamage):name_(name), location_(0,0), hp_(100), velocity_(1)
{
    equipedWeapon_ = new Weapon(weaponName, weaponDamage);
    equipedArmor_ = new Armor( armorName, armorProtection);
}
Character::Character(std::string name, Weapon* weapon, Armor* armor):name_(name), location_(0,0), hp_(100), velocity_(1), equipedWeapon_(weapon), equipedArmor_(armor){}

Character::Character(std::string name, Weapon* weapon):name_(name), location_(0,0), hp_(100), velocity_(1), equipedWeapon_(weapon)
{
    equipedArmor_ = new Armor();
}
Character::Character(std::string name, Armor* armor):name_(name), location_(0,0), hp_(100), velocity_(1), equipedArmor_(armor)
{
    equipedWeapon_ = new Weapon();
}

Character::~Character()
{
    inventory_.clearInventory();
    delete equipedWeapon_;
    delete equipedArmor_;
}

std::string Character::info()const
{
    std::string text;
    text = name_ + getLocation().get() + ": hp(" + std::to_string(hp_) + "), velocity(" + std::to_string(velocity_) + ")\n" + equipedWeapon_->info() + equipedArmor_->info() + inventory_.info();
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
    std::string text;
    text = name_ + location_.get() + " is approaching " + target.getName() + target.getLocation().get() + "\n";

    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = targetLocation.getX() - currentLocation.getX();
    int deltaY = targetLocation.getY() - currentLocation.getY();
    
    double distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance >= getVelocity()) {
        std::string direction;
        if (deltaX != 0 or deltaY !=0)
        {
            if (std::abs(deltaX) > std::abs(deltaY))
            {
                direction = (deltaX > 0) ? "right" : "left";            
            }else{
                direction = (deltaY > 0) ? "up" : "down";
            }
        }
        
        
        
        return text + move(direction);
    }
    return name_ + " can reach " + target.getName() + "\n";
}

std::string Character::fleeCharacter(const Character& target) {
    std::string text;
    text = name_ + location_.get() + " is moving away from " + target.getName() + target.getLocation().get() + "\n";

    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = currentLocation.getX() - targetLocation.getX();
    int deltaY = currentLocation.getY() - targetLocation.getY();

    std::string direction;
    direction = (std::abs(deltaX) < std::abs(deltaY)) ? ((deltaX > 0) ? "right" : "left") : ((deltaY > 0)? "up" : "down");
    
    return text + move(direction);
}

std::string Character::attack(Character& target){
    if (this->isAlive())
    {
        if(location_ == target.getLocation()){
            target.dealDamage(equipedWeapon_->getDamage());
            std::string text = getName() + " is attacking " + target.getName() + "(" +  std::to_string(target.getHp()) + "HP remaining)\n";
            if(!target.isAlive()){
                text += target.getName() + " is dead.\n";
            }
            return text;
        }else{
            return target.getName() + " is too far away.\n";
        }
    }
    return "";
}

void Character::dealDamage(int damage){
    hp_ -= damage - equipedArmor_->getProtection();
    if (hp_<0)
    {
        hp_ = 0;
    }
}