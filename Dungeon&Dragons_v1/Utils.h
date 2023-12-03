#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

namespace Const {
    // map size
    const int MAP_HEIGHT_MAX = 10;
    const int MAP_WIDTH_MAX = 10;
    const int MAP_HEIGHT_MIN = -10;
    const int MAP_WIDTH_MIN = -10;

    //direction possibility
    const std::vector<std::string> DIRECTIONS = {"up","down","left","right"};
}

#endif