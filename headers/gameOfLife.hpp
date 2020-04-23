#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

class gameOfLife;

#include "randomNumberGenerator.hpp"
#include "gameMenu.hpp"
#include "gameWorld.hpp"

class gameOfLife {
private:
    randomNumberGenerator *rng;
    gameWorld *world;
    gameMenu *menu;

public:
    // Set up and start the game
    gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m);

    void startGame();
    void stopGame();
};

#endif