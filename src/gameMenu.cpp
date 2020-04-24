#include "../headers/gameMenu.hpp"
#include <cstdio>
#include <iostream>
#include <unistd.h>

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
    while(game->getGameStatus()) {
        std::cout << ":::::::::::::::::::::Main menu::::::::::::::::::::" << std::endl;
        std::cout << "[1]Stop [2]Clean [3]Randomize [4]One [5]Go " << 
                    "[6]Move" << std::endl;

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
        case 4:
            one();
            break;
        case 5:
            hundred();
            break;
        case 6:
            world->printGrid();
            moveMenu();
            break;
        }
    }
}

void gameMenu::clean() {
    world->fillGrid(true);
    world->printGrid();
}

void gameMenu::randomize() {
    world->fillGrid(false);
    world->printGrid();
}

void gameMenu::one() {
    world->updateGame();
    world->printGrid();
}

void gameMenu::hundred() {
    for (int i = 0; i < 100; i++) {
        world->updateGame();
        world->printGrid();
        std::cout << "::: Timestep: " << i + 1 << std::endl << std::endl;
        usleep(50000);
    }
    world->printGrid();
}

void gameMenu::moveMenu() {
    bool inMoveMenu = true;

    while (inMoveMenu) {
        std::cout << "::::::::::::::::::Move menu:::::::::::::::::" << std::endl;
        std::cout << "[1]Left [2]Right [3]Up [4]Down [5]Main Menu" << std::endl;

        switch (getInput(1,8)) {
        case 1:
            game->changeViewPortX(-20);
            world->printGrid();
            break;
        case 2:
            game->changeViewPortX(20);
            world->printGrid();
            break;
        case 3:
            game->changeViewPortY(-20);
            world->printGrid();
            break;
        case 4:
            game->changeViewPortY(20);
            world->printGrid();
            break;
        case 5:
            world->printGrid();
            inMoveMenu = false;
            break;
        }
    }
}