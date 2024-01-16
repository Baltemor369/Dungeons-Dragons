#include "../headers/Armor.h"

Armor::Armor(const Armor &other):Object(other.getName(), other.getType()) {
    defense_ = other.getDefense();
}

std::string Armor::info() const {
    std::string text;
    text += "Armor: " + getName();
    text += ", Defense=" + std::to_string(getDefense());
    text += ", Thorns=" + std::to_string(getThorns());
    text += ", Regeneration=" + std::to_string(getRegeneration());
    text += "\n";
    return text;
}