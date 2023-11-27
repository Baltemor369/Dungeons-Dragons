/**
 * @file Character.h
 * @brief Definition of the Character class
 * 
 * Handles actions and attributes for a player or NPC, such as HP, Damage, speed, etc.
 * 
 * Author: Baltemor369
 * Date: November 15, 2023
 */

#ifndef Character_H
#define Character_H

#include <string>
#include "Weapon.h"
#include"Armor.h"

/**
 * @class Character
 * @brief Represents a character with attributes like HP, damage, speed, etc.
 */
class Character
{
private:
    std::string p_name; /** A unique name (ID) */
    Weapon p_weapon;
    Armor p_armor;
    int p_hp, p_velocity; /** Basic stats: health, damage, speed move */
    int p_x, p_y; /** 2D position */
    bool p_move_up, p_move_down, p_move_right, p_move_left; /** Boolean variables to manage movement */
public:
    /**
     * @brief Constructor for the Character class.
     * @param name The name of the character.
     * @param hp The character's hit points (HP) (default is 100).
     * @param weapon The character's weapon.
     * @param armor The character's armor.
     * @param x The x-coordinate of the character's position (default is 0).
     * @param y The y-coordinate of the character's position (default is 0).
     * @param velocity The character's velocity (default is 1).
     */
    Character(std::string name, int hp=100, Weapon weapon=Weapon(), Armor armor=Armor(), int x=0, int y=0, int velocity=1):p_name(name), p_hp(hp), p_weapon(weapon), p_armor(armor), p_x(x), p_y(y), p_velocity(velocity){}

    /**
     * @brief Destructor for the Character class.
     */
    ~Character();

    /**
     * @brief Display information about the character.
     */
    void info();

    /**
     * @brief Get the name of the character.
     * @return The name of the character.
     */
    std::string get_name() { return p_name;}

    /**
     * @brief Get the damage of the character.
     * @return The damage of the character.
     */
    Weapon get_weapon() { return p_weapon;}

    /**
     * @brief Get the hit points (HP) of the character.
     * @return The hit points (HP) of the character.
     */
    int get_hp() { return p_hp; }

    /**
     * @brief Get the x-coordinate of the character's position.
     * @return The x-coordinate of the character's position.
     */
    int get_x() { return p_x; }

    /**
     * @brief Get the y-coordinate of the character's position.
     * @return The y-coordinate of the character's position.
     */
    int get_y() { return p_y; }

    /**
     * @brief Set the upward movement of the character.
     * @param val Boolean value indicating if the character is moving up.
     */
    void set_move_up(bool val);

    /**
     * @brief Set the downward movement of the character.
     * @param val Boolean value indicating if the character is moving down.
     */
    void set_move_down(bool val);

    /**
     * @brief Set the rightward movement of the character.
     * @param val Boolean value indicating if the character is moving right.
     */
    void set_move_right(bool val);

    /**
     * @brief Set the leftward movement of the character.
     * @param val Boolean value indicating if the character is moving left.
     */
    void set_move_left(bool val);

    /**
     * @brief Inflict damage on the character.
     * @param damage The damage to inflict.
     */
    void deal_damage(Weapon* weapon);

    /**
     * @brief Attack another character, dealing damage to them.
     * @param c2 The character to attack.
     */
    void attack(Character* c2);

    /**
     * @brief Move the character based on its current movement status.
     * 
     * Moves the character's position based on the current movement status
     * (up, down, left, right) and the character's velocity.
     * 
     * If the character is moving up, its y-coordinate is decremented.
     * If the character is moving down, its y-coordinate is incremented.
     * If the character is moving right, its x-coordinate is incremented.
     * If the character is moving left, its x-coordinate is decremented.
     */
    void move();
};

#endif
