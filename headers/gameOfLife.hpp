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

    bool running;

    // the coordinates of the top-left corner of the viewport
    // and the size of the viewport
    int viewPortX;
    int viewPortY;
    int viewPortSizeX;
    int viewPortSizeY;
    int viewPortStepSizeX;
    int viewPortStepSizeY;

    char lifeCellChar;
    char deadCellChar;

public:
    // Set up
    gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m);

    void startGame();
    void stopGame();
    bool getGameStatus();

    int getViewPortX();
    int getViewPortY();

    int getViewPortSizeX();
    int getViewPortSizeY();

    int getViewPortStepSizeX();
    int getViewPortStepSizeY();

    void changeViewPortX(int change);
    void changeViewPortY(int change);

    void changeViewPortStepSizeX(int newSize);
    void changeViewPortStepSizeY(int newSize);

    void setLifeCellChar(char c);
    void setDeadCellChar(char c);

    char getLifeCellChar();
    char getDeadCellChar();
};

#endif