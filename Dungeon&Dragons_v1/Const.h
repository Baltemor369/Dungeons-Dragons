#ifndef CONST_H
#define CONST_H

#include <vector>
#include <map>
#include <string>

#include "Weapon.h"
#include "Armor.h"
#include "Ressources.h"


namespace Const {
    const std::vector<std::string> DIRECTIONS = {"up", "down","right","left"};
    const int MAP_HEIGHT_MAX = 10;
    const int MAP_WIDTH_MAX = 10;
    const int MAP_HEIGHT_MIN = -10;
    const int MAP_WIDTH_MIN = -10;

    struct WeaponsParams {
        std::string name;
        int damage;
        int letha;
        int reach;
    };
    std::map<std::string, WeaponsParams> weaponsParamsDict;

    WeaponsParams ;
    
    struct MonsterParams {
        std::string name;
        int hp;
        int velocity;
        Weapon weapon;
        Armor armor;
        Ressources ressources;
    };
    std::map<std::string, MonsterParams> monsterParamsDict;

    MonsterParams goblinParams = {"Goblin", 10, 3, sword};
    MonsterParams orcParams = {};
    MonsterParams dragonParams = {};
    MonsterParams shadowspireParams = {};
    MonsterParams blihtbeastParams = {};
    MonsterParams thundermawParams = {};
    MonsterParams frostbaneParams = {};
    MonsterParams venomshadeParams = {};
    MonsterParams emberfiendParams = {};
    MonsterParams dreadhowlParams = {};
    MonsterParams runebladeParams = {};
    MonsterParams lunarshroudParams = {};
    MonsterParams neanterosParams = {};
    
}

#endif