#pragma once

#include <string> 
#include <vector>
#include <map>

using dict = std::map<std::string, std::vector<std::string>>;
namespace Const  {
    const std::string ENEMY = "enemy";
    const std::string PLAYER = "player";
    const std::string WEAPON = "weapon";
    const std::string ARMOR = "armor";
    const std::string OBJECT = "object";

    const std::string DEFAULT_WEAPON_NAME = "Hands";
    const int DEFAULT_WEAPON_DAMAGE = 1;
    const int DEFAULT_WEAPON_PENETRING = 0;
    const int DEFAULT_WEAPON_VAMPIRISM = 0;
    
    const std::string DEFAULT_ARMOR_NAME = "Clothes";
    const int DEFAULT_ARMOR_DEFENSE = 0;
    const int DEFAULT_ARMOR_THORN = 0;
    const int DEFAULT_ARMOR_REGENERATION = 0;
}

namespace Key {
    
    // AZERTY keyboard
    namespace FR {
        const std::vector<std::string> KEYS = {"up", "down", "left", "right","z","q","s","d"};
        const std::vector<std::string> KEY_UP = {"up", "z"};
        const std::vector<std::string> KEY_DOWN = {"down", "s"};
        const std::vector<std::string> KEY_LEFT = {"left", "q"};
        const std::vector<std::string> KEY_RIGHT = {"right", "d"};
    }


    // QWERTY keyboard
    namespace EN {
        const std::vector<std::string> KEYS = {"up", "down", "left", "right","w","a","s","d"};
        const std::vector<std::string> KEY_UP = {"up", "w"};
        const std::vector<std::string> KEY_DOWN = {"down", "s"};
        const std::vector<std::string> KEY_LEFT = {"left", "a"};
        const std::vector<std::string> KEY_RIGHT = {"right", "d"};
    }
}

namespace Items {
    namespace Ores {
        const std::string TERRALITE = "terralite ore";
        const std::string IRON = "iron ore";
        const std::string STEEL = "steel ore";
        const std::string GOLD = "gold ore";
        const std::string METEORITE = "meteorite ore";
        const std::string ORIX = "orix ore";
    }
    namespace Ingots {} 
    namespace Gems {} 
    namespace Fragments {} 
    namespace Components {} 
    namespace Weapons {} 
    namespace Armors {} 
    namespace Others {} 
    
    
    // UNIX : gem parfaite multicolor, craft : 1 each gems
    // ORIX : minerais des ténèbres, lieux : deep
    // ORITIUM : cyan orb floating and lootable with mob around(some instant attack, other attack only when you get the orb) , biome ATLIS : paradis beach jungle floating in the sky
    // terralite : ore forest orange&marron
    // Hastelloy ?
}