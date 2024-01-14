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
    const std::string DEFAULT_ARMOR_NAME = "Clothes";
    const int DEFAULT_ARMOR_PROTECTION = 0;

}

namespace Items {
    namespace Ores {
        std::string TERRALITE = "terralite ore";
        std::string IRON = "iron ore";
        std::string STEEL = "steel ore";
        std::string GOLD = "gold ore";
        std::string METEORITE = "meteorite ore";
        std::string ORIX = "orix ore";
    }
    namespace Gems {
        std::string DIAMOND = "diamond gem";
        std::string RUBY = "ruby gem";
        std::string SAPHIR = "saphir gem";
        std::string EMERAULD = "emerauld gem";
        std::string AMBER = "amber gem";
        std::string AMETHYST = "amethyst gem";
        std::string QUARTZ = "quartz gem";
        std::string UNIX = "unix gem";
    }
    namespace Ingots {
        std::string TERRALITE = "terralite ingot";
        std::string IRON = "iron ingot";
        std::string STEEL = "steel ingot";
        std::string GOLD = "gold ingot";
        std::string METEORITE = "meteorite ingot";
        std::string ORIX = "orix ingot";
    }
    namespace Fragments {
        std::string MANGALITE = "mangalite fragment";
        std::string ORITIUM = "oritium fragment";
    }
    namespace Components {
        std::string STICK = "stick";
        std::string IRON_BAR = "iron bar";
        std::string STEEL_BAR = "steel bar";
        std::string FLINT = "flint";
    }
    namespace Weapon {

    }
    namespace Armor {

    }
    // UNIX : gem parfaite multicolor, craft : 1 each gems
    // ORIX : minerais des ténèbres, lieux : deep
    // ORITIUM : cyan orb floating and lootable with mob around(some instant attack, other attack only when you get the orb) , biome ATLIS : paradis beach jungle floating in the sky
    // terralite : ore forest orange&marron
    // Hastelloy ?
}

namespace Craft {
    const dict WOODEN_SWORD = {{"wooden sword", {"stick", "wood", "wood"}}};
    const dict BONES_SWORD = {{"bones sword", {"stick", "bone", "bone"}}};
    const dict STONE_SWORD = {{"stone sword", {"stick", "stone", "stone"}}};
    const dict TERRALITE_SWORD = {{"terralite sword", {"stick", "terralite", "terralite"}}}; // brun orangé
    const dict IRON_SWORD = {{"iron sword", {"stick", "iron ingot", "iron ingot"}}};
    const dict GOLDEN_SWORD = {{"golden sword", {"stick", "golden ingot", "golden ingot"}}};
    const dict DIAMOND_SWORD = {{"diamond sword", {"stick", "diamond gem", "diamond gem"}}};
    const dict MANGALITE_SWORD = {{"mangalite sword", {"stick", "mangalite ingot", "mangalite ingot"}}};
    const dict METEORITE_SWORD = {{"meteorite sword", {"stick", "meteorite ingot", "meteorite ingot"}}};
    const dict ORITIUM_SWORD = {{"oritium sword", {"stick", "oritium", "oritium"}}};
    const dict MANGALITE_SWORD = {{"mangalite sword", {"stick", "mangalite ingot", "mangalite ingot", "mangalite ingot", "mangalite ingot"}}};
    const dict _SWORD = {{"mangalite sword", {"stick", "mangalite ingot", "mangalite ingot", "mangalite ingot", "mangalite ingot"}}};

    const dict WOODEN_AXE = {{"wooden axe", {"stick", "wood", "wood", "wood"}}};
    const dict BONES_AXE = {{"bones axe", {"stick", "bone", "bone", "bone"}}};
    const dict TERRALITE_AXE = {{"terralite axe", {"stick", "terralite", "terralite", "terralite"}}};
    const dict STONE_AXE = {{"stone axe", {"stick", "stone", "stone", "stone"}}};
    const dict IRON_AXE = {{"iron axe", {"stick", "iron ingot", "iron ingot", "iron ingot"}}};
    const dict GOLDEN_AXE = {{"golden axe", {"stick", "golden ingot", "golden ingot", "golden ingot"}}};
    const dict DIAMOND_AXE = {{"diamond axe", {"stick", "diamond gem", "diamond gem", "diamond gem"}}};
    const dict MANGALITE_AXE = {{"mangalite axe", {"stick", "mangalite ingot", "mangalite ingot", "mangalite ingot"}}};
    const dict METEORITE_AXE = {{"meteorite axe", {"stick", "meteorite ingot", "meteorite ingot", "meteorite ingot"}}};
    const dict UNIX_AXE = {{"unix axe", {"stick", "unix ingot", "unix ingot", "unix ingot", "unix ingot"}}};  
    const dict ORIX_AXE = {{"orix axe", {"stick", "orix ingot", "orix ingot", "orix ingot", "orix ingot"}}}; 

    const dict WOODEN_HAMMER = {{"wooden hammer", {"stick", "wood", "wood", "wood", "wood"}}};
    const dict BONES_HAMMER = {{"bones hammer", {"stick", "bone", "bone", "bone", "bone"}}};
    const dict TERRALITE_HAMMER = {{"terralite hammer", {"stick", "terralite", "terralite", "terralite", "terralite"}}};
    const dict STONE_HAMMER = {{"stone hammer", {"stick", "stone", "stone", "stone", "stone"}}};
    const dict IRON_HAMMER = {{"iron hammer", {"stick", "iron ingot", "iron ingot", "iron ingot", "iron ingot"}}};
    const dict GOLDEN_HAMMER = {{"golden hammer", {"stick", "golden ingot", "golden ingot", "golden ingot", "golden ingot"}}};
    const dict DIAMOND_HAMMER = {{"diamond hammer", {"stick", "diamond gem", "diamond gem", "diamond gem", "diamond gem"}}};
    const dict MANGALITE_HAMMER = {{"mangalite hammer", {"stick", "mangalite ingot", "mangalite ingot", "mangalite ingot", "mangalite ingot"}}};
    const dict METEORITE_HAMMER = {{"meteorite hammer", {"stick", "meteorite ingot", "meteorite ingot", "meteorite ingot", "meteorite ingot"}}};
    
    const dict WOODEN_SPEAR = {{"wooden spear", {"stick", "rope", "stick"}}};
    const dict STONE_SPEAR = {{"wooden spear", {"stick", "rope", "stick", "rope", "flint"}}};
    const dict IRON_SPEAR = {{"iron spear", {"iron ingot", "rope", "iron ingot", "rope", "iron ingot"}}};
    const dict GOLD_SPEAR = {{"gold spear", {"gold ingot", "rope", "gold ingot", "rope", "gold ingot"}}};
    const dict DIAMOND_SPEAR = {{"diamond spear", {"iron ingot", "rope", "iron ingot", "rope", "diamond gem"}}};
    const dict MANGALITE_SPEAR = {{"meteorite spear", {"iron ingot", "rope", "iron ingot", "rope", "meteorite ingot"}}};
    const dict METEORITE_SPEAR = {{"meteorite spear", {"iron ingot", "rope", "iron ingot", "rope", "meteorite ingot"}}};
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