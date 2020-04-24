#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

class gameOfLife;
class gameWorld;

#include "randomNumberGenerator.hpp"
#include "gameMenu.hpp"
#include "gameWorld.hpp"

class gameOfLife {
private:
    // references to randomNumberGenerator, gameWorld and gameMenu objects
    randomNumberGenerator *rng;
    gameWorld *world;
    gameMenu *menu;

    // game status
    bool running;

    // viewport parameters
    int viewPortX;
    int viewPortY;
    int viewPortSizeX;
    int viewPortSizeY;
    int viewPortStepSizeX;
    int viewPortStepSizeY;

    // cell representations
    char lifeCellChar;
    char deadCellChar;

public:
    // functions that concern the game status
    bool getGameStatus();
    void startGame();
    void stopGame();

    // functions that concern the viewport location
    int getViewPortX();
    int getViewPortY();
    void changeViewPortX(int change);
    void changeViewPortY(int change);

    // function that concern the viewport size
    int getViewPortSizeX();
    int getViewPortSizeY();

    // functions that concern the viewport stepsize
    int getViewPortStepSizeX();
    int getViewPortStepSizeY();
    void changeViewPortStepSizeX(int newSize);
    void changeViewPortStepSizeY(int newSize);

    // functions that concern the character representations
    char getLifeCellChar();
    char getDeadCellChar();
    void setLifeCellChar(char c);
    void setDeadCellChar(char c);

    // constructor
    gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m);
};

#endif