#pragma once

#include "Entity.h"

class Group {
private:
    int size_;
    Entity* player_;
    std::vector<Entity*> enemies_;
public:
    Group();
    ~Group();

    std::string recap()const;
    std::string info() const;

    int size() const { return size_; }
    Entity* getPlayer() const { return player_; }
    std::vector<Entity*> getEnemies() const { return enemies_; }
    Entity* getEnemy(std::string id) const ;

    void addPlayer(Entity& player);
    void addEnemy(Entity* enemy);
    void removePlayer();
    void removeEnemy(std::string name);
};

