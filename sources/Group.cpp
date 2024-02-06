#include "../headers/Group.h"

Group::Group() : size_(0) {
    player_ = nullptr;
}

Group::~Group() {
    player_ = nullptr;
    for(auto& elt : enemies_){
        delete elt;
    }
}

std::string Group::recap()const{
    std::string text;
    text += "Group :\n";
    if(player_ != nullptr){
        text += player_->recap();
    }
    for(Entity* elt : enemies_){
        text += elt->recap();
    }
    return text;
}

std::string Group::info() const {
    std::string text;
    text += "Group:\n";
    if(player_ != nullptr){
        text += player_->info();
    }
    for(Entity* elt : enemies_){
        text += elt->info();
    }
    return text;
}

Entity* Group::getEnemy(std::string name) const {
    for (const auto& elt : enemies_) {
        if (elt->getName() == name) {
            return elt;
        }
    }
    return nullptr;
}

void Group::addPlayer(Entity& player) {
    player_ = &player;
}

void Group::addEnemy(Entity* enemy) {
    enemies_.push_back(enemy);
    ++size_;
}

void Group::removePlayer() {
    player_ = nullptr;
}

void Group::removeEnemy(std::string name) {
    int i(0);
    for (auto e : enemies_) {
        if ((e)->getName() == name) {
            enemies_.erase(enemies_.begin()+i);
            --size_;
        }
        ++i;
    }
}