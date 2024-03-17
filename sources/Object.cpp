#include "../headers/Object.h"

Object::Object(const Object& obj){
    this->name_ = obj.getName();
    this->type_ = obj.getType();
}
Object::~Object() {}

std::string Object::info() const {
    return "Object : " + name_ + "\n";
}

void Object::setName(const std::string name) {
    name_ = name;
}