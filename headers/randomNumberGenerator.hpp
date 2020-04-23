#ifndef RANDOMNUMBERGENERATOR_HPP
#define RANDOMNUMBERGENERATOR_HPP

class randomNumberGenerator {
public:
    long seed;
    void genSeed();
    float getRnd();

    randomNumberGenerator();
};

#endif