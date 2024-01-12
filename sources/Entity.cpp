#include "../headers/Entity.h"

Entity::Entity(std::string name):name_(name), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon();
    equipedArmor_ = new Armor();
}

Entity::Entity(std::string name, int x, int y):name_(name), hp_(100), velocity_(1), location_(x,y)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon();
    equipedArmor_ = new Armor();
}

Entity::Entity(std::string name, std::string weaponName, int weaponDamage):name_(name), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(weaponName, weaponDamage);
    equipedArmor_ = new Armor();
}

Entity::Entity(std::string name, int armorDef, std::string armorName):name_(name), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon();
    equipedArmor_ = new Armor(armorName, armorDef);
}

Entity::Entity(std::string name, std::string weaponName, int weaponDamage, std::string armorName, int armorDef):name_(name), hp_(100), velocity_(1), location_(0,0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(weaponName, weaponDamage);
    equipedArmor_ = new Armor(armorName, armorDef);
}

Entity::Entity(std::string name, int x, int y, std::string weaponName, int weaponDamage, std::string armorName, int armorDef):name_(name), hp_(100), velocity_(1), location_(x,y)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(weaponName, weaponDamage);
    equipedArmor_ = new Armor(armorName, armorDef);
}

Entity::~Entity()
{
    delete equipedWeapon_;
    delete equipedArmor_;
    delete inventory_;
}

std::string Entity::recap()const{
    std::string text;
    text += "Name: " + name_ + "\n";
    return text;
}

std::string Entity::info()const
{
    std::string text("");
    text = name_ + " " + getLocation().info() + ": hp(" + std::to_string(hp_) + "), velocity(" + std::to_string(velocity_) + ")\n" + equipedWeapon_->info() + equipedArmor_->info() + inventory_->info();
    return text;
}

void Entity::setName(const std::string name){
    if (name.size() > 0)
    {
        name_ = name;
    }
    
}

std::string Entity::move(std::string direction) {
    Coord currentLocation = getLocation();
    int deltaX(0);
    int deltaY(0);

    if (isIn(direction, Key::FR_KEY_UP))
    {
        deltaY = velocity_;
    }else if (isIn(direction, Key::FR_KEY_RIGHT))
    {
        deltaX = velocity_;
    }else if (isIn(direction, Key::FR_KEY_LEFT))
    {
        deltaX = -velocity_;
    }else if (isIn(direction, Key::FR_KEY_DOWN))
    {
        deltaY = -velocity_;
    }

    Coord newLocation = currentLocation + Coord(deltaX, deltaY);
    
    setLocation(newLocation);

    return getName() + " move to " + newLocation.info();
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

void Entity::equipWeapon(Weapon* w){ 
    unequipWeapon();
    if(w != nullptr){
        equipedWeapon_ = w ;
    }
}

void Entity::equipArmor(Armor* a){ 
    unequipArmor();
    if(a != nullptr){
        equipedArmor_ = a ;
    } 
}

void Entity::unequipWeapon(){
    if (equipedWeapon_->getName() != Const::DEFAULT_WEAPON_NAME)
    {
        inventory_->addItem(equipedWeapon_);
    }
    equipedWeapon_ = nullptr;
}

void Entity::unequipArmor(){
    if (equipedArmor_->getName() != Const::DEFAULT_ARMOR_NAME)
    {
        inventory_->addItem(equipedArmor_);
    }
    equipedArmor_ = nullptr;
}

void Entity::dealDamage(int damage){
    hp_ -= damage - equipedArmor_->getProtection();
    if (hp_<0)
    {
        hp_ = 0;
    }
}

std::string Entity::attack(Entity& target){
    if (this->isAlive())
    {
        if(location_ == target.getLocation()){
            int hp_mem(target.getHp());
            target.dealDamage(equipedWeapon_->getDamage());
            std::string text = getName() + " is attacking " + target.getName() + "\nDamage : " + std::to_string(hp_mem-target.getHp()) + ", " +  std::to_string(target.getHp()) + "HP remaining)\n";
            if(!target.isAlive()){
                text += target.getName() + " is dead.\n";

            }
            return text;
        }else{
            return target.getName() + " is too far away.\n";
        }
    }else{
        return "target is already dead.\n";
    }
    return "";
}