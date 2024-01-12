#pragma once

#include <string>
#include "constants.h"

class Object {
private:
    std::string name_;
    std::string type_;

public:
    Object(std::string name="", std::string type=Const::OBJECT):name_(name), type_(type){}
    Object(const Object& obj);
    ~Object();

    virtual std::string info() const;

    std::string getName() const{return name_;}
    std::string getType() const{return type_;}

    void setName(const std::string name);
};