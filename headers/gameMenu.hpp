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
    int getMenuInput(int min, int max);
    float getInputFloat(float min, float max);
    char getInputChar();
    void mainMenu();
    void clean();
    void randomize();
    void one();
    void hundred();
    void linkGameObj(gameOfLife *g);
    void moveMenu();
    void paramMenu();

    gameMenu(gameWorld *w);
};

#endif