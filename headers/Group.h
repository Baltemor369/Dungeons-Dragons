#pragma once

#include "Entity.h"

class Group {
private:
    int size_;
    Entity* player_;
    std::vector<std::tuple<int, Entity*>> enemies_;
public:
    Group();
    ~Group();

    std::string recap()const;
    std::string info() const;

    int size() const { return size_; }
    Entity* getPlayer() const { return player_; }
    std::vector<std::tuple<int, Entity*>> getEnemies() const { return enemies_; }
    int getNbEntity(std::string name) const ;
    const std::tuple<int, Entity*>* getElt(std::string name) const;
    Entity* getEntity(std::string name) const ;

    void addPlayer(Entity& player);
    void removePlayer();
    void addEnemy(Entity* enemy, int stack=1);
    void removeEnemy(std::string name, int stack=1);
    void modifyEntityStack(std::string name, int delta);

    void clean();
};

