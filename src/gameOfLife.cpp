#include "../headers/gameOfLife.hpp"
#include <cstdio>
#include <iostream>

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

int gameOfLife::getViewPortX() {
    return viewPortX;
}

int gameOfLife::getViewPortY() {
    return viewPortY;
}

int gameOfLife::getViewPortSizeX() {
    return viewPortSizeX;
}

int gameOfLife::getViewPortSizeY() {
    return viewPortSizeY;
}

int gameOfLife::getViewPortStepSizeX() {
    return viewPortStepSizeX;
}

int gameOfLife::getViewPortStepSizeY() {
    return viewPortStepSizeY;
}

void gameOfLife::startGame() {
    running = true;
    world->printGrid();
    menu->mainMenu();
}

void gameOfLife::stopGame() {
    running = false;
    std::cout << "Exiting game...Hope you had fun." << std::endl;
}

bool gameOfLife::getGameStatus() {
    return running;
}

void gameOfLife::changeViewPortStepSizeX(int newSize) {
    viewPortStepSizeX = newSize;
}

void gameOfLife::changeViewPortStepSizeY(int newSize) {
    viewPortStepSizeY = newSize;
}

void gameOfLife::setDeadCellChar(char c) {
    deadCellChar = c;
}

void gameOfLife::setLifeCellChar(char c) {
    lifeCellChar = c;
}

char gameOfLife::getDeadCellChar() {
    return deadCellChar;
}

char gameOfLife::getLifeCellChar() {
    return lifeCellChar;
}