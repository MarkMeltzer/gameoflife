#include "../headers/gameOfLife.hpp"
#include <cstdio>
#include <iostream>

/**
 * Returns wether the game is running or not.
 *
 * @return the current game status
 */
bool gameOfLife::getGameStatus() {
    return running;
}

/**
 * Start the game.
 */
void gameOfLife::startGame() {
    running = true;
    world->printGrid();
    menu->mainMenu();
}

/**
 * Stop the game.
 */
void gameOfLife::stopGame() {
    running = false;
    std::cout << "Exiting game...Hope you had fun." << std::endl;
}

/**
 * Returns the current x coordinate of the top-left
 * corner of the viewport.
 * 
 * @return the x coordinate of the viewport
 */
int gameOfLife::getViewPortX() {
    return viewPortX;
}

/**
 * Returns the current y coordinate of the top-left
 * corner of the viewport.
 * 
 * @return the y coordinate of the viewport
 */
int gameOfLife::getViewPortY() {
    return viewPortY;
}

/**
 * Changes the x coordinate of the viewport.
 * 
 * @param change the amount to change the x coordinate by, can
 * be negative.
 */
void gameOfLife::changeViewPortX(int change) {
    int newX = viewPortX + change;
    int viewPortMin = -1 * (viewPortSizeX / 2);
    int viewPortMax = 200 - viewPortSizeX + viewPortSizeX / 2;
    
    // constrain the viewport so it doesn't move to far out of the grid
    if (newX < viewPortMin) {
        newX = viewPortMin;
    } else if (newX > viewPortMax) {
        newX = viewPortMax;
    }

    viewPortX = newX;
}

/**
 * Changes the x coordinate of the viewport.
 * 
 * @param change the amount to change the x coordinate by, can
 * be negative.
 */
void gameOfLife::changeViewPortY(int change) {
    int newY = viewPortY + change;
    int viewPortMin = -1 * (viewPortSizeY / 2);
    int viewPortMax = 200 - viewPortSizeY + viewPortSizeY / 2;
    
    // constrain the viewport so it doesn't move to far out of the grid
    if (newY < viewPortMin) {
        newY = viewPortMin;
    } else if (newY > viewPortMax) {
        newY = viewPortMax;
    }

    viewPortY = newY;
}

/**
 * Returns the current horizontal size of the viewport.
 * 
 * @return the current horizontal size of the viewport
 */
int gameOfLife::getViewPortSizeX() {
    return viewPortSizeX;
}

/**
 * Returns the current vertical size of the viewport.
 * 
 * @return the current vertical size of the viewport
 */
int gameOfLife::getViewPortSizeY() {
    return viewPortSizeY;
}

/**
 * Returns the current horizontal viewport stepsize.
 * 
 * @return the current horizontal viewport stepsize.
 */
int gameOfLife::getViewPortStepSizeX() {
    return viewPortStepSizeX;
}

/**
 * Returns the current vertical viewport stepsize.
 * 
 * @return the current vertical viewport stepsize.
 */
int gameOfLife::getViewPortStepSizeY() {
    return viewPortStepSizeY;
}

/**
 * Changes the horizontal viewport stepsize.
 * 
 * @param newSize the new horizontal viewport stepsize
 */
void gameOfLife::changeViewPortStepSizeX(int newSize) {
    viewPortStepSizeX = newSize;
}

/**
 * Changes the vertical viewport stepsize.
 * 
 * @param newSize the new vertical viewport stepsize
 */
void gameOfLife::changeViewPortStepSizeY(int newSize) {
    viewPortStepSizeY = newSize;
}

/**
 * Returns the current dead cell representation.
 * 
 * @return the char representing a dead cell
 */
char gameOfLife::getDeadCellChar() {
    return deadCellChar;
}

/**
 * Returns the current life cell representation.
 * 
 * @return the char representing a life cell
 */
char gameOfLife::getLifeCellChar() {
    return lifeCellChar;
}

/**
 * Changes the current dead cell representation.
 * 
 * @param c the new char representing a dead cell
 */
void gameOfLife::setDeadCellChar(char c) {
    deadCellChar = c;
}

/**
 * Changes the current life cell representation.
 * 
 * @param c the new char representing a life cell
 */
void gameOfLife::setLifeCellChar(char c) {
    lifeCellChar = c;
}

/**
 * Constructor. Stores the reference to a randomNumberGenerator,
 * a gameWorld and a gameMenu object as well as initalizing parameters.
 *
 * @param r the randomNumberGenerator object reference
 * @param w the gameWorld object reference
 * @param m the gameMenu object reference
 */
gameOfLife::gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m) {
    rng = r;
    world = w;
    menu = m;

    world->setAliveProbability(0.5);
    world->fillGrid(false);

    viewPortX = 20;
    viewPortY = 60;
    viewPortSizeX = 80;
    viewPortSizeY = 40;
    viewPortStepSizeX = 20;
    viewPortStepSizeY = 20;

    lifeCellChar = 'O';
    deadCellChar = '.';
}