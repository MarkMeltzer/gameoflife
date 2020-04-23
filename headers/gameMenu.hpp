#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

#include "gameOfLife.hpp"
#include "gameWorld.hpp"

class gameMenu {
private:
    gameOfLife *game;
    gameWorld *world;

public:
    int getInput(int min, int max);
    void mainMenu();
    void clean();
    void randomize();

    gameMenu(gameWorld *w, gameOfLife *g);
};

#endif