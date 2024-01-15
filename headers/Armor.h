#pragma once

#include "Object.h"

class Armor : public Object {
private:
    int defense_;

public:
    Armor(std::string name = Const::DEFAULT_ARMOR_NAME, int protection = Const::DEFAULT_ARMOR_DEFENSE);
    Armor(const Armor& other);
    ~Armor();

    std::string info() const override;

    int getDefense() const{ return defense_;}

    void setProtection(int protection);

};