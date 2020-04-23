#include "../headers/gameOfLife.hpp"
#include <cstdio>
#include <iostream>

gameOfLife::gameOfLife(randomNumberGenerator *r, gameWorld *w, gameMenu *m) {
    rng = r;
    world = w;
    menu = m;

    world->setAliveProbability(0.5);
    world->fillGrid(false);
    
}

void gameOfLife::startGame() {
    world->printGrid();
    menu->mainMenu();
}

void gameOfLife::stopGame() {
    std::cout << "Exiting game...Hope you had fun." << std::endl;
}