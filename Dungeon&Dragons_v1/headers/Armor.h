#pragma once

#include "Object.h"

class Armor : public Object {
private:
    int protection_;

public:
    Armor(std::string id, std::string name = Const::DEFAULT_ARMOR, int protection = 0);
    Armor(const Armor& other);
    ~Armor();

    std::string recap()const;
    std::string info() const override;
    int getProtection() const;

    void setProtection(int protection);

};