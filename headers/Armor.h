#pragma once

#include "Object.h"

class Armor : public Object {
private:
    int defense_, thorns_, regeneration_;

public:
    Armor(std::string name, int defense, int thorns, int regenerate):
        Object(name, Const::ARMOR), defense_(defense), thorns_(thorns), regeneration_(regenerate) {}
    Armor(const Armor& other);
    ~Armor(){}

    std::string info() const override;

    int getDefense() const{ return defense_;}
    int getThorns() const{ return thorns_;}
    int getRegeneration() const{ return regeneration_;}

    void setDefense(int value){defense_ = value;}
    void setThorns(int value){thorns_ = value;}
    void setRegeneration(int value){regeneration_ = value;}

};