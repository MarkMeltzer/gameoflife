#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

#include "randomNumberGenerator.hpp"
#include "gameWorld.hpp"

class gameOfLife {
private:
    randomNumberGenerator *rng;
    gameWorld *world;

public:
    // Set up and start the game
    gameOfLife(randomNumberGenerator *r, gameWorld *w);

    void stop();
};

#endif