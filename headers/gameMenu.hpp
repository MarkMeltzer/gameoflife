#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

class gameMenu;

#include "gameWorld.hpp"
#include "gameOfLife.hpp"

class gameMenu {
private:
    gameOfLife *game;
    gameWorld *world;

public:
    int getInput(int min, int max);
    void mainMenu();
    void clean();
    void randomize();
    void one();
    void hundred();
    void linkGameObj(gameOfLife *g);
    void moveMenu();

    gameMenu(gameWorld *w);
};

#endif