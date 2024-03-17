#include "../headers/Group.h"

Group::Group() : size_(0) {
    player_ = nullptr;
}

Group::~Group() {
    player_ = nullptr;
    for(auto& elt : enemies_){
        delete std::get<1>(elt);
    }
}

std::string Group::recap()const{
    std::string text;
    text += "Group :\n";
    if(player_ != nullptr){
        text += player_->recap();
    }
    for(auto elt : enemies_){
        text += std::get<1>(elt)->recap();
    }
    return text;
}

std::string Group::info() const {
    std::string text;
    text += "Group:\n";
    if(player_ != nullptr){
        text += player_->info();
    }
    for(auto elt : enemies_){
        text += std::get<1>(elt)->info();
    }
    return text;
}

Entity* Group::getEntity(std::string name) const {
    for (const auto& elt : enemies_) {
        if (std::get<1>(elt)->getName() == name) {
            return std::get<1>(elt);
        }
    }
    return Const::ERROR::POINTER;
}

int Group::getNbEntity(std::string name) const {
    for (const auto& elt : enemies_) {
        if (std::get<1>(elt)->getName() == name) {
            return std::get<0>(elt);
        }
    }
    return Const::ERROR::INT;
}

void Group::addPlayer(Entity& player) {
    player_ = &player;
}

void Group::addEnemy(Entity* enemy, int stack) {
    auto find = getElt(enemy->getName());
    if (find != nullptr)
    {
        modifyEntityStack(enemy->getName(), stack);
    }else{
        enemies_.push_back({stack, enemy});
    }
    size_ += stack;
}

void Group::removePlayer() {
    player_ = nullptr;
}

void Group::removeEnemy(std::string name, int stack) {
    auto find = getElt(name);
    if (find != nullptr)
    {
        if (std::get<0>(*find) >= stack)
        {
            modifyEntityStack(name, -stack);
        }else{
            modifyEntityStack(name, -std::get<0>(*find));
        }
    }   
    
    clean();
}

void Group::modifyEntityStack(std::string name, int delta){
    for (auto& it : enemies_)
    {
        if (std::get<1>(it)->getName() == name)
        {
            std::get<0>(it) += delta;
            size_ += delta;
        }
    }
}

const std::tuple<int, Entity*>* Group::getElt(std::string name) const{
    for (auto& it : enemies_)
    {
        if (std::get<1>(it)->getName() == name)
        {
            return &it;
        }
    }
    return nullptr;
}

void Group::clean(){
    for (auto it = enemies_.begin(); it != enemies_.end();)
    {
        if (std::get<0>(*it) == 0)
        {
            enemies_.erase(it);
        }else{
            ++it;
        }   
    }
}