#pragma once

#include <string>

class Object {
private:
    std::string name_;
    std::string type_;

public:
    Object(std::string name, std::string type="Any");

    virtual std::string info() const;

    std::string getName() const;
    std::string getType() const;

    void setName(const std::string name);
    void setType(const std::string type);
};