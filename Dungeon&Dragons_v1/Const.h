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
    
    struct MonsterParams {
        std::string name;
        int hp;
        int velocity;
        Weapon weapon;
        Armor armor;
        Ressources ressources;
    };
    std::map<std::string, MonsterParams> monsterParamsDict;

    const MonsterParams goblinParams = {"Goblin", 10, 3, sword};
    const MonsterParams orcParams = {};
    const MonsterParams dragonParams = {};
    const MonsterParams shadowspireParams = {};
    const MonsterParams blihtbeastParams = {};
    const MonsterParams thundermawParams = {};
    const MonsterParams frostbaneParams = {};
    const MonsterParams venomshadeParams = {};
    const MonsterParams emberfiendParams = {};
    const MonsterParams dreadhowlParams = {};
    const MonsterParams runebladeParams = {};
    const MonsterParams lunarshroudParams = {};
    const MonsterParams neanterosParams = {};
    
}

#endif