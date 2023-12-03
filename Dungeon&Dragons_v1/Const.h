#ifndef CONST_H
#define CONST_H

#include <vector>
#include <string>

namespace Const {
    const std::vector<std::string> DIRECTIONS = {"up", "down","right","left"};
    const int MAP_HEIGHT_MAX = 10;
    const int MAP_WIDTH_MAX = 10;
    const int MAP_HEIGHT_MIN = -10;
    const int MAP_WIDTH_MIN = -10;
}

#endif