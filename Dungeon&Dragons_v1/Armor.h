#pragma once

#include "Object.h"

class Armor : public Object {
private:
    int protection_;

public:
    Armor(std::string name = "Clothes", int protection = 1);

    int getProtection() const;

    void setProtection(int protection);

    std::string info() const override;
};