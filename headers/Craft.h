#pragma once

#include "Weapon.h"
#include "Armor.h"

using Recipe = std::vector<std::tuple<int, std::string>>;

class Craft
{
private:
    Recipe recipe_;
    Object* object_;
public:
    Craft(Recipe recipe, Object* item):recipe_(recipe), object_(item){};
    Craft(Recipe recipe, Weapon* item):recipe_(recipe), object_(item){};
    Craft(Recipe recipe, Armor* item):recipe_(recipe), object_(item){};
    ~Craft(){};
};

namespace Crafting {
    namespace Weapons {
        const Craft woodenSword({{1, Items::Components::STICK},{2, Items::Components::WOOD}}, new Weapon(Items::Weapons::WOODEN_SWORD,5,2,0));
        const Craft terraliteSword({{1, Items::Components::STICK},{2, Items::Ingots::TERRALITE}}, new Weapon(Items::Weapons::TERRALITE_SWORD,10,3,0));
        const Craft copperSword({{1, Items::Components::STICK},{2, Items::Ingots::COPPER}}, new Weapon(Items::Weapons::COPPER_SWORD,20,6,0));
        const Craft ironSword({{1, Items::Components::STICK},{2, Items::Ingots::IRON}}, new Weapon(Items::Weapons::IRON_SWORD,40,12,0));
        const Craft steelSword({{1, Items::Components::STICK},{2, Items::Ingots::STEEL}}, new Weapon(Items::Weapons::STEEL_SWORD,80,24,0));
        const Craft goldSword({{1, Items::Components::STICK},{2, Items::Ingots::GOLD}}, new Weapon(Items::Weapons::GOLD_SWORD,160,48,0));
        const Craft meteoriteSword({{1, Items::Components::STICK},{2, Items::Ingots::METEORITE}}, new Weapon(Items::Weapons::METEORITE_SWORD,320,92,0));
        const Craft orixSword({{1, Items::Components::STICK},{2, Items::Ingots::ORIX}}, new Weapon(Items::Weapons::ORIX_SWORD,640,184 ,0));
    }
    namespace Armors {

    }
    namespace Components {
        const Craft stick({{2,Items::Components::WOOD}}, new Object(Items::Components::STICK));
        const Craft ironStick({{2,Items::Ingots::IRON}}, new Object(Items::Components::IRON_BAR));
        const Craft boneStick({{2, Items::Components::BONE}}, new Object(Items::Components::BONE_STICK));
        const Craft rope({{3, Items::Components::LEAVES}}, new Object(Items::Components::ROPE));
    }
}