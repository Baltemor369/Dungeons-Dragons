#pragma once

#include <string> 
#include <vector>

namespace Const  {
    const std::string ENEMY = "enemy";
    const std::string PLAYER = "player";
    const std::string WEAPON = "weapon";
    const std::string ARMOR = "armor";
    const std::string OBJECT = "object";
    const std::string DEFAULT_WEAPON_NAME = "Hands";
    const int DEFAULT_WEAPON_DAMAGE = 1;
    const std::string DEFAULT_ARMOR_NAME = "Clothes";
    const int DEFAULT_ARMOR_PROTECTION = 0;
}

namespace Key {
    
    // AZERTY keyboard
    const std::vector<std::string> FR_KEYS = {"up", "down", "left", "right","z","q","s","d"};
    const std::vector<std::string> FR_KEY_UP = {"up", "z"};
    const std::vector<std::string> FR_KEY_DOWN = {"down", "s"};
    const std::vector<std::string> FR_KEY_LEFT = {"left", "q"};
    const std::vector<std::string> FR_KEY_RIGHT = {"right", "d"};


    // QWERTY keyboard
    const std::vector<std::string> EN_KEYS = {"up", "down", "left", "right","w","a","s","d"};
    const std::vector<std::string> EN_KEY_UP = {"up", "w"};
    const std::vector<std::string> EN_KEY_DOWN = {"down", "s"};
    const std::vector<std::string> EN_KEY_LEFT = {"left", "a"};
    const std::vector<std::string> EN_KEY_RIGHT = {"right", "d"};
}

namespace Items{
    
}