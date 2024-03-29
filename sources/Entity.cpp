#include "../headers/Entity.h"

Entity::Entity(std::string name):name_(name), hp_(100), velocity_(1), strengh_(1), location_(0,0), exp_(0), lvl_(0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon();
    equipedArmor_ = new Armor();
}

Entity::Entity(std::string name, int x, int y):name_(name), hp_(100), strengh_(1), velocity_(1), location_(x,y), exp_(0), lvl_(0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon();
    equipedArmor_ = new Armor();
}

Entity::Entity(std::string name, std::string weaponName, int weaponDamage, int weaponPenetration, int weaponVampirism, std::string armorName, int armorDef, int armorThorn, int armorRegeneration):name_(name), hp_(100), strengh_(1), velocity_(1), location_(0,0), exp_(0), lvl_(0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(weaponName, weaponDamage, weaponPenetration, weaponVampirism);
    equipedArmor_ = new Armor(armorName, armorDef, armorThorn, armorRegeneration);
}

Entity::Entity(std::string name, int x, int y, std::string weaponName, int weaponDamage, int weaponPenetration, int weaponVampirism, std::string armorName, int armorDef, int armorThorn, int armorRegeneration):name_(name), hp_(100), strengh_(1), velocity_(1), location_(x,y), exp_(0), lvl_(0)
{
    inventory_ = new Inventory("Backpack");
    equipedWeapon_ = new Weapon(weaponName, weaponDamage, weaponPenetration, weaponVampirism);
    equipedArmor_ = new Armor(armorName, armorDef, armorThorn, armorRegeneration);
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
    text = name_ + " " + getLocation().info() + "\nhp : " + std::to_string(hp_) + "\nexp : "+ std::to_string(exp_) +"\nstrengh : " + std::to_string(strengh_) + "\nvelocity : " + std::to_string(velocity_) + "\n" + equipedWeapon_->info() + equipedArmor_->info() + inventory_->info();
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

    if (Str::isIn(direction, Key::FR::KEY_UP))
    {
        deltaY = velocity_;
    }else if (Str::isIn(direction, Key::FR::KEY_RIGHT))
    {
        deltaX = velocity_;
    }else if (Str::isIn(direction, Key::FR::KEY_LEFT))
    {
        deltaX = -velocity_;
    }else if (Str::isIn(direction, Key::FR::KEY_DOWN))
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
        if (deltaX != 0 || deltaY !=0)
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
    inventory_->removeItem(w->getName());
}

void Entity::equipArmor(Armor* a){ 
    unequipArmor();
    if(a != nullptr){
        equipedArmor_ = a ;
    }
    inventory_->removeItem(a->getName());
}

void Entity::unequipWeapon(){
    if (hasWeaponEquipped())
    {
        inventory_->addItem(equipedWeapon_);
        equipedWeapon_ = new Weapon(Const::Default::WEAPON_NAME, Const::Default::WEAPON_DAMAGE, Const::Default::WEAPON_LETHALITY, Const::Default::WEAPON_VAMPIRISM);
    }
}

void Entity::unequipArmor(){
    if (hasArmorEquipped())
    {
        inventory_->addItem(equipedArmor_);
        equipedArmor_ = new Armor(Const::Default::ARMOR_NAME, Const::Default::ARMOR_DEFENSE, Const::Default::ARMOR_THORN, Const::Default::ARMOR_REGENERATION);
    }
}

void Entity::dealDamage(int damage){
    hp_ -= damage;
    hp_ = (hp_ < 0) ? 0 : hp_;
}

bool Entity::attack(Entity& target){
    if (this->isAlive())
    {
        if(location_ == target.getLocation()){
            int hp_mem(target.getHp());
            
            // true damage
            int trueDamage = std::round(getWeapon()->getDamage() * getWeapon()->getLethality());
            std::cout << std::to_string(trueDamage) << std::endl;
            target.dealDamage(trueDamage * ( 1 + strengh_/100));
            
            // normal damage
            int damage = getWeapon()->getDamage() - target.getArmor()->getDefense();
            damage = (damage < 0) ? 0 : damage;
            std::cout << std::to_string(damage) << std::endl;
            target.dealDamage(damage * ( 1 + strengh_/100));

            // Vampirism
            hp_ += getWeapon()->getDamage() * getWeapon()->getVampirism();
            
            std::cout << getName() << " is attacking " << target.getName() << "\nDamage : " << std::to_string(hp_mem-target.getHp()) << ", " <<  std::to_string(target.getHp()) << "HP remaining)\n";
            // if target die
            if(!target.isAlive()){
                std::cout << target.getName() + " is dead.\n";
                // get xp
                exp_ += 10;
                updateXp();
                return true;
            }
            return false;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Entity::updateXp(){
    // level up check in
    if (exp_ > lvl_ * 100)
    {
        ++lvl_; // increase +1
        exp_ = 0; // reset to 0

        hp_ += 50; // hp increase
        strengh_ += 5 ; // strengh increase
    }
}