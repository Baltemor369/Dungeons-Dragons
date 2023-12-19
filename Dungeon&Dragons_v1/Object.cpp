#include "../headers/Object.h"

Object::Object(std::string name, std::string type) : name_(name), type_(type) {}

std::string Object::info() const {
    return "Object: " + name_ + ", Type: " + type_;
}

std::string Object::getName() const {
    return name_;
}

std::string Object::getType() const {
    return type_;
}

void Object::setName(const std::string name) {
    name_ = name;
}


void Object::setType(const std::string type) {
    type_ = type;
}