#include "../headers/Entity.h"

Entity::Entity(std::string id, std::string name):name_(name), id_(id), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(getItemNewID());
    equipedArmor_ = new Armor(getItemNewID());
}

Entity::Entity(std::string id, std::string name, int x, int y):name_(name), id_(id), hp_(100), velocity_(1), location_(x,y)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(getItemNewID());
    equipedArmor_ = new Armor(getItemNewID());
}

Entity::Entity(std::string id, std::string name, std::string weaponName, int weaponDamage):name_(name), id_(id), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(getItemNewID(), weaponName, weaponDamage);
    equipedArmor_ = new Armor(getItemNewID());
}

Entity::~Entity()
{
    delete equipedWeapon_;
    delete equipedArmor_;
    delete inventory_;
}

std::string Entity::recap()const{
    std::string text;
    text += "Name: " + name_ + " " + location_.info();
    text += "Hp = " + std::to_string(hp_) + "\n";
    text += "Weapon Name: " + equipedWeapon_->getName() + "\n";
    text += "Armor Name: " + equipedArmor_->getName() + "\n";
    return text;
}

std::string Entity::info()const
{
    std::string text("");
    text = name_ + "#" + getId() + " " + getLocation().info() + ": hp(" + std::to_string(hp_) + "), velocity(" + std::to_string(velocity_) + ")\n" + equipedWeapon_->info() + equipedArmor_->info() + inventory_->info();
    return text;
}

std::string Entity::getItemNewID()const{
    return std::to_string(inventory_->size());
}

void Entity::setName(const std::string& name) {
    name_ = name;
}

void Entity::setLocation(const Coord& location) {
    location_ = location;
}

void Entity::setHP(int hp) {
    hp_ = hp;
}

void Entity::setVelocity(int velocity) {
    velocity_ = velocity;
}

std::string Entity::move(std::string direction) {
    Coord currentLocation = getLocation();
    int deltaX(0);
    int deltaY(0);

    if (isIn(direction, KeyFR::KEY_UP))
    {
        deltaY = velocity_;
    }else if (isIn(direction, KeyFR::KEY_RIGHT))
    {
        deltaX = velocity_;
    }else if (isIn(direction, KeyFR::KEY_LEFT))
    {
        deltaX = -velocity_;
    }else if (isIn(direction, KeyFR::KEY_DOWN))
    {
        deltaY = -velocity_;
    }

    Coord newLocation = currentLocation + Coord(deltaX, deltaY);
    
    setLocation(newLocation);

    return getName() + " move to " + newLocation.info();
}

void Entity::addToInventory(Object& item) {
    inventory_->addItem(item);
}

void Entity::removeFromInventory(std::string id) {
    inventory_->removeItem(id);
}

std::string Entity::approachCharacter(const Entity& target) {
    std::string text;
    text = name_ + location_.info() + " is approaching " + target.getName() + target.getLocation().info() + "\n";

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

std::string Entity::fleeCharacter(const Entity& target) {
    std::string text;
    text = name_ + location_.info() + " is moving away from " + target.getName() + target.getLocation().info() + "\n";

    Coord currentLocation = getLocation();

    Coord targetLocation = target.getLocation();

    int deltaX = currentLocation.getX() - targetLocation.getX();
    int deltaY = currentLocation.getY() - targetLocation.getY();

    std::string direction;
    direction = (std::abs(deltaX) < std::abs(deltaY)) ? ((deltaX > 0) ? "right" : "left") : ((deltaY > 0)? "up" : "down");
    
    return text + move(direction);
}

std::string Entity::attack(Entity& target){
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

void Entity::dealDamage(int damage){
    hp_ -= damage - equipedArmor_->getProtection();
    if (hp_<0)
    {
        hp_ = 0;
    }
}