#pragma once

#include <string> 
#include <vector>
#include <map>

using Dict = std::map<std::string, std::vector<std::string>>;

namespace Const  {
    const std::string ENEMY = "Enemy";
    const std::string PLAYER = "Player";
    const std::string WEAPON = "Weapon";
    const std::string ARMOR = "Armor";
    const std::string OBJECT = "Object";
    namespace ERROR {
        const int INT = -1;
        const std::string STR = "Error";
        const auto POINTER = nullptr;
    }
    namespace Reserved {
        const std::vector<std::string> NAMES = {"Chest","Barrel","Box","Wardrobe", "Bag", "Crate", "Locker"};
    }
    namespace Response {
        const std::vector<std::string> ALL = {"Yes", "No"};
        const std::string YES = "Yes";
        const std::string NO = "No";
    }
        
    namespace Default {
        const std::string WEAPON_NAME = "Hands";
        const int WEAPON_DAMAGE = 1;
        const int WEAPON_LETHALITY = 0;
        const int WEAPON_VAMPIRISM = 0;
        
        const std::string ARMOR_NAME = "Clothes";
        const int ARMOR_DEFENSE = 0;
        const int ARMOR_THORN = 0;
        const int ARMOR_REGENERATION = 0;
    }
}

namespace Action
{
    const std::vector<std::string> ALL = {"Info","Move","Stuff","Crafting","Fight","Loot","Create","Exit", "Quit"};
    const std::string HOME = "Home";
    namespace Info {
        const std::vector<std::string> KEY_WORDS = {"Tile","Player","Inventory","Weapon","Armor"};
        const std::string SELF = "Info";
        const std::string TILE = "Tile";
        const std::string PLAYER = "Player";
        const std::string INVENTORY = "Inventory";
        const std::string WEAPON = "Weapon";
        const std::string ARMOR = "Armor";
    }
    namespace Move {
        const std::string SELF = "Move";
    }
    namespace Stuff {
        const std::vector<std::string> KEY_WORDS = {"Equip","Unequip","Weapon","Armor"};
        const std::string SELF = "Stuff";
        const std::string EQUIP_WEAPON = "Equip Weapon";
        const std::string UNEQUIP_WEAPON = "Unequip Weapon";
        const std::string EQUIP_ARMOR = "Equip Armor";
        const std::string UNEQUIP_ARMOR = "Unequip Armor";
    }
    namespace Crafting {
        const std::vector<std::string> KEY_WORDS = {};
        const std::string SELF = "Crafting";
    }
    namespace Fight {
        const std::vector<std::string> KEY_WORDS = {"Attack", "Swap", "Weapon", "Armor", "Escape"};
        const std::string SELF = "Fight";
        const std::string ATTACK = "Attack";
        const std::string SWAP_WEAPON = "Swap Weapon";
        const std::string SWAP_ARMOR = "Swap Armor";
        const std::string ESCAPE = "Escape";
    }
    namespace Loot {
        const std::vector<std::string> KEY_WORDS = {};
        const std::string SELF = "Loot";
    }
    namespace Create {
        const std::vector<std::string> KEY_WORDS = {"Weapon","Armor","Object","Enemy"};
        const std::string SELF = "Create";
        const std::string WEAPON = "Weapon";
        const std::string ARMOR = "Armor";
        const std::string OBJECT = "Object";
        const std::string ENEMY = "Enemy";
    }
}

namespace Key {
    // AZERTY keyboard
    namespace FR {
        const std::vector<std::string> KEY_WORDS = {"Up", "Down", "Left", "Right","Z","Q","S","D"};
        const std::vector<std::string> KEY_UP = {"Up", "Z"};
        const std::vector<std::string> KEY_DOWN = {"Down", "S"};
        const std::vector<std::string> KEY_LEFT = {"Left", "Q"};
        const std::vector<std::string> KEY_RIGHT = {"Right", "D"};
    }

    // QWERTY keyboard
    namespace EN {
        const std::vector<std::string> KEY_WORDS = {"Up", "Down", "Left", "Right","W","A","S","D"};
        const std::vector<std::string> KEY_UP = {"Up", "W"};
        const std::vector<std::string> KEY_DOWN = {"Down", "S"};
        const std::vector<std::string> KEY_LEFT = {"Left", "A"};
        const std::vector<std::string> KEY_RIGHT = {"Right", "D"};
    }
}

namespace Items {
    namespace Ores {
        const std::string COPPER = "Copper ore";
        const std::string TERRALITE = "Terralite ore";
        const std::string IRON = "Iron ore";
        const std::string STEEL = "Steel ore";
        const std::string GOLD = "Gold ore";
        const std::string METEORITE = "Meteorite ore";
        const std::string ORIX = "Orix ore";
    }
    namespace Ingots {
        const std::string COPPER = "Copper ingot";
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
    namespace Components {
        const std::string FIBER = "Fiber";
        const std::string LEAVES = "Leaves";
        const std::string BONE = "Bone";
        const std::string ORITIUM = "Oritium orb";
        const std::string STICK = "Stick";
        const std::string BONE_STICK = "Bone stick";
        const std::string IRON_BAR = "Iron bar";
        const std::string WOOD = "Wood";
        const std::string FLINT = "Flint";
        const std::string ROPE = "Rope";

    } 
    namespace Weapons {
        const std::string WOODEN_SWORD = "Wooden sword";
        const std::string COPPER_SWORD = "Wooden sword";
        const std::string TERRALITE_SWORD = "Wooden sword";
        const std::string IRON_SWORD = "Wooden sword";
        const std::string STEEL_SWORD = "Wooden sword";
        const std::string GOLD_SWORD = "Wooden sword";
        const std::string METEORITE_SWORD = "Wooden sword";
        const std::string ORIX_SWORD = "Wooden sword"; 
    } 
    namespace Armors {} 
    namespace Others {} 
    
    
    // UNIX : gem parfaite multicolor, craft : 1 each gems
    // ORIX : minerais des ténèbres, lieux : deep
    // ORITIUM : cyan orb floating and lootable with mob around(some instant attack, other attack only when you get the orb) , biome ATLIS : paradis beach jungle floating in the sky
    // terralite : ore forest orange&marron
    // Hastelloy ?
}