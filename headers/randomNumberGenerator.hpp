#ifndef RANDOMNUMBERGENERATOR_HPP
#define RANDOMNUMBERGENERATOR_HPP

class randomNumberGenerator {
public:
    // the starting seed and random value
    long seed;

    void genSeed();
    float getRnd();

    // constructor
    randomNumberGenerator();
};

#endif