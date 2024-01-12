#pragma once

#include "Object.h"

class Armor : public Object {
private:
    int protection_;

public:
    Armor(std::string name = Const::DEFAULT_ARMOR_NAME, int protection = Const::DEFAULT_ARMOR_PROTECTION);
    Armor(const Armor& other);
    ~Armor();

    std::string info() const override;

    int getProtection() const;

    void setProtection(int protection);

};