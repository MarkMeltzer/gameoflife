#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

class gameOfLife;
class gameWorld;

#include "randomNumberGenerator.hpp"
#include "gameMenu.hpp"
#include "gameWorld.hpp"

class gameOfLife {
private:
    randomNumberGenerator *rng;
    gameWorld *world;
    gameMenu *menu;

    // the coordinates of the top-left corner of the viewport
    // and the size of the viewport
    int viewPortX;
    int viewPortY;
    int viewPortSizeX;
    int viewPortSizeY;

public:
    // Set up
    gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m);

    void startGame();
    void stopGame();

    int getViewPortX();
    int getViewPortY();

    int getViewPortSizeX();
    int getViewPortSizeY();

    void changeViewPortX(int change);
    void changeViewPortY(int change);
};

#endif