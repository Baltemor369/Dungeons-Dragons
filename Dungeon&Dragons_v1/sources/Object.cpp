#include "../headers/Object.h"

Object::Object(std::string name, std::string type, std::string id=Const::OBJECT) :id_(id), name_(name), type_(type) {}
Object::Object(const Object& obj){
    this->id_ = obj.getId();
    this->name_ = obj.getName();
    this->type_ = obj.getType();
}
Object::~Object() {}

std::string Object::info() const {
    return "Object: " + name_ + "#ID:" + id_ + ", Type: " + type_ + "\n";
}

void Object::setName(const std::string name) {
    name_ = name;
}


void Object::setType(const std::string type) {
    type_ = type;
}