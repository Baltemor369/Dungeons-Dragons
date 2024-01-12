#pragma once

#include <random>

/**
 * @brief A simple random number generator class.
 *
 * \n This class provides a basic interface for generating random integers within a specified range.
 */
class Random {
private:
    std::random_device rd_; /**< A random device for seeding the generator. */
    std::mt19937 generator_; /**< Mersenne Twister 19937 pseudo-random number generator. */
    std::uniform_int_distribution<int> distribution_; /**< Uniform integer distribution. */

public:
    /**
     * @brief Constructor for the Random class.
     *
     * Initializes the random number generator with a default range [0, 1].
     *
     * @param min The minimum value for the random number range.
     * @param max The maximum value for the random number range.
     */
    Random(int min = 0, int max = 1) : distribution_(min, max), generator_(rd_()) {}

    /**
     * @brief Destructor for the Random class.
     */
    ~Random() {}

    /**
     * @brief Generates a random integer within the specified range [min, max].
     *
     * @return A random integer within the specified range.
     */
    int getRandomNumber() { return distribution_(generator_); }

    /**
     * @brief Sets the minimum value of the random number range.
     *
     * @param min The new minimum value for the random number range.
     */
    void setMin(int min) { distribution_ = std::uniform_int_distribution<int>(min, distribution_.max()); }

    /**
     * @brief Sets the maximum value of the random number range.
     *
     * @param max The new maximum value for the random number range.
     */
    void setMax(int max) { distribution_ = std::uniform_int_distribution<int>(distribution_.min(), max); }

    /**
     * @brief Sets both the minimum and maximum values of the random number range.
     *
     * @param min The new minimum value for the random number range.
     * @param max The new maximum value for the random number range.
     */
    void setBorder(int min, int max) { distribution_ = std::uniform_int_distribution<int>(min, max); }
};
