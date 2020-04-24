#include "../headers/randomNumberGenerator.hpp"
#include <time.h>

/**
 * Generates a new seed.
 */
void randomNumberGenerator::genSeed() {
    seed = time(NULL) % 2147483648;
}

/**
 * Gives a new random number and updates the seed.
 * 
 * @return a random float between 0 and 1
 */
float randomNumberGenerator::getRnd() {
    seed = (214013 * seed + 12345) % 2147483648;
    return (float) seed / 2147483648;
}

/**
 * Constructor. The initial seed.
 */
randomNumberGenerator::randomNumberGenerator() {
    genSeed();
}