#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP

class gameMenu;

#include "gameWorld.hpp"
#include "gameOfLife.hpp"
#include <fstream>

class gameMenu {
private:
    // references to gameOfLife and gameWorld objects
    gameOfLife *game;
    gameWorld *world;

public:
    // input functions
    int getMenuInput(int min, int max);
    float getInputFloat(float min, float max);
    char getInputChar();
    std::ifstream getInputFile();

    // menus
    void mainMenu();
    void moveMenu();
    void paramMenu();

    void linkGameObj(gameOfLife *g);

    // constructor
    gameMenu(gameWorld *w);
};

#endif