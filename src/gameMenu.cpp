#include "../headers/gameMenu.hpp"
#include <cstdio>
#include <iostream>

gameMenu::gameMenu(gameWorld *w) {
    world = w;
}

void gameMenu::linkGameObj(gameOfLife *g) {
    game = g;
}

int gameMenu::getInput(int min, int max) {
    int input;
    std::cin >> input;
    while (std::cin.fail() || input < min || input > max) {
        std::cout << "Please provide valid input [1-8]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cin >> input;
    }
    return input;
}

void gameMenu::mainMenu() {
    std::cout << "[1]Stop [2]Clean [3]Randomize" << std::endl;

    switch (getInput(1,8)) {
    case 1:
        game->stopGame();
        break;
    case 2:
        clean();
        break;
    case 3:
        randomize();
        break;
    }
}

void gameMenu::clean() {
    world->fillGrid(true);
    world->printGrid();
    mainMenu();
}

void gameMenu::randomize() {
    world->fillGrid(false);
    world->printGrid();
    mainMenu();
}