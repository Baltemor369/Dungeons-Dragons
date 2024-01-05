#pragma once

#include <string>
#include "constants.h"

class Object {
private:
    std::string id_;
    std::string name_;
    std::string type_;

public:
    Object(std::string id, std::string name, std::string type="Any");
    Object(const Object& obj);
    ~Object();

    virtual std::string info() const;

    std::string getName() const{return name_;}
    std::string getType() const{return type_;}
    std::string getId() const{return id_;}

    void setName(const std::string name);
    void setType(const std::string type);
};