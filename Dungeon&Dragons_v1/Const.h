#ifndef CONST_H
#define CONST_H

#include <vector>
#include <map>
#include <string>

namespace Const {
    const std::vector<std::string> DIRECTIONS = {"up", "down","right","left"};
    const int MAP_HEIGHT_MAX = 10;
    const int MAP_WIDTH_MAX = 10;
    const int MAP_HEIGHT_MIN = -10;
    const int MAP_WIDTH_MIN = -10;

    //monsters specifications :
    std::vector<std::string> MOB_NAMES = {
        "Dragon", "Goblin", "Ogre","skeleton","zombie"
    }
    
}

#endif