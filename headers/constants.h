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
    const int DEFAULT_WEAPON_LETHALITY = 0;
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
        const std::string TERRALITE = "Terralite ore";
        const std::string IRON = "Iron ore";
        const std::string STEEL = "Steel ore";
        const std::string GOLD = "Gold ore";
        const std::string METEORITE = "Meteorite ore";
        const std::string ORIX = "Orix ore";
    }
    namespace Ingots {
        const std::string TERRALITE = "Terralite ingot";
        const std::string IRON = "Iron ingot";
        const std::string STEEL = "Steel ingot";
        const std::string GOLD = "Gold ingot";
        const std::string METEORITE = "Meteorite ingot";
        const std::string ORIX = "Orix ingot";
    } 
    namespace Gems {
        const std::string DIAMOND = "Diamond gem";
        const std::string SAPHIR = "Saphir gem";
        const std::string EMERAULD = "Emerauld gem";
        const std::string RUBY = "Ruby gem";
        const std::string AMETHYST = "Amethyst gem";
        const std::string AMBER = "Amber gem";
        const std::string UNIX = "Unix gem";
    }
    namespace Fragments {
        const std::string BONE = "Bone";
        const std::string ORITIUM = "Oritium orb";
    } 
    namespace Components {
        const std::string STICK = "Stick";
        const std::string IRON_BAR = "Iron bar";
        const std::string WOOD = "Wood";
        const std::string FLINT = "Flint";
    } 
    namespace Weapons {} 
    namespace Armors {} 
    namespace Others {} 
    
    
    // UNIX : gem parfaite multicolor, craft : 1 each gems
    // ORIX : minerais des ténèbres, lieux : deep
    // ORITIUM : cyan orb floating and lootable with mob around(some instant attack, other attack only when you get the orb) , biome ATLIS : paradis beach jungle floating in the sky
    // terralite : ore forest orange&marron
    // Hastelloy ?
}