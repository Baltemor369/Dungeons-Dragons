#pragma once

#include <string> 
#include <vector>

namespace Const  {
    const std::string ENEMY = "enemy";
    const std::string PLAYER = "player";
    const std::string WEAPON = "weapon";
    const std::string ARMOR = "armor";
    const std::string OBJECT = "any";
    const std::string DEFAULT_WEAPON = "Hands";
    const std::string DEFAULT_ARMOR = "Clothes";
}

namespace KeyFR {
    
    // AZERTY keyboard
    const std::vector<std::string> KEYS = {"up", "down", "left", "right","z","q","s","d"};
    const std::vector<std::string> KEY_UP = {"up", "z"};
    const std::vector<std::string> KEY_DOWN = {"down", "s"};
    const std::vector<std::string> KEY_LEFT = {"left", "q"};
    const std::vector<std::string> KEY_RIGHT = {"right", "d"};
}

namespace KeyEN {
    // QWERTY keyboard
    const std::vector<std::string> KEYS = {"up", "down", "left", "right","w","a","s","d"};
    const std::vector<std::string> KEY_UP = {"up", "w"};
    const std::vector<std::string> KEY_DOWN = {"down", "s"};
    const std::vector<std::string> KEY_LEFT = {"left", "a"};
    const std::vector<std::string> KEY_RIGHT = {"right", "d"};
}