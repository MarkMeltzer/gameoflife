#include "../headers/randomNumberGenerator.hpp"
#include <time.h>

randomNumberGenerator::randomNumberGenerator() {
    genSeed();
}

void randomNumberGenerator::genSeed() {
    seed = time(NULL) % 2147483648;
}

float randomNumberGenerator::getRnd() {
    seed = (214013 * seed + 12345) % 2147483648;
    return (float) seed / 2147483648;
}