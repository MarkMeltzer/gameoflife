#include "../headers/gameMenu.hpp"
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <string>

gameMenu::gameMenu(gameWorld *w) {
    world = w;
}

void gameMenu::linkGameObj(gameOfLife *g) {
    game = g;
}

int gameMenu::getMenuInput(int min, int max) {
    int input;
    std::cin >> input;
    while (std::cin.fail() || input < min || input > max) {
        std::cout << "Please provide valid input [" << min << "-" << max << "]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cin >> input;
    }
    return input;
}

float gameMenu::getInputFloat(float min, float max) {
    float input;
    std::cin >> input;
    while (std::cin.fail() || input < min || input > max) {
        std::cout << "Please provide valid input [" << min << "-" << max << "]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cin >> input;
    }
    return input;
}

char gameMenu::getInputChar() {
    std::string input;
    std::cin >> input;
    while (std::cin.fail() || input.length() > 1) {
        std::cout << "Please provide valid input [single character]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cin >> input;
    }
    return input[0];
}

void gameMenu::mainMenu() {
    while(game->getGameStatus()) {
        std::cout << ":::::::::::::::::::::::::::::::Main menu:::::::::::::::::::::::::::::::" << std::endl;
        std::cout << "[1]Stop [2]Clean [3]Randomize [4]One [5]Go " << 
                    "[6]Move [7]Parameter [8]File" << std::endl;

        switch (getMenuInput(1,8)) {
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
        case 7:
            world->printGrid();
            paramMenu();
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
        std::cout << "::::::::::::::::::Move menu::::::::::::::::" << std::endl;
        std::cout << "[1]Left [2]Right [3]Up [4]Down [5]Main Menu" << std::endl;

        switch (getMenuInput(1,5)) {
        case 1:
            game->changeViewPortX(-1 * game->getViewPortStepSizeX());
            world->printGrid();
            break;
        case 2:
            game->changeViewPortX(game->getViewPortStepSizeX());
            world->printGrid();
            break;
        case 3:
            game->changeViewPortY(-1 * game->getViewPortStepSizeY());
            world->printGrid();
            break;
        case 4:
            game->changeViewPortY(game->getViewPortStepSizeY());
            world->printGrid();
            break;
        case 5:
            world->printGrid();
            inMoveMenu = false;
            break;
        }
    }
}

void gameMenu::paramMenu() {
    bool inparamMenu = true;

    while (inparamMenu) {
        std::cout << "::::::::::::::::::::::::::::::::Set parameters::::::::::::::::::::::::::::::" << std::endl;
        std::cout << "[1]Hor viewport stepsize [2]Vert viewport stepsize [3]Cell spawn probability " << std::endl 
                  << "[4]Life cell char \t [5]Dead cell char \t   [6]Main Menu" << std::endl;

        int paramMenuInput = getMenuInput(1,6);
        switch (paramMenuInput) {
        case 1: 
        {
            std::cout << "What should the new stepsize be [1-100]? ";
            int input = getMenuInput(1,100);
            game->changeViewPortStepSizeX(input);
            world->printGrid();
            break;
        }
        case 2:
        {
            std::cout << "What should the new stepsize be [1-100]? ";
            int input = getMenuInput(1,100);
            game->changeViewPortStepSizeY(input);
            world->printGrid();
            break;
        }
        case 3:
        {
            std::cout << "What should the new probability be [0.0-1.0]? ";
            float input = getInputFloat(0.0,1.0);
            world->setAliveProbability(input);
            world->printGrid();
            break;
        }
        case 4:
        {
            std::cout << "What should the new life representation be? [character]? ";
            float input = getInputChar();
            game->setLifeCellChar(input);
            world->printGrid();
            break;
        }
        case 5:
        {
            std::cout << "What should the new dead representation be? [character]? ";
            float input = getInputChar();
            game->setDeadCellChar(input);
            world->printGrid();
            break;
        }
        case 6:
            world->printGrid();
            inparamMenu = false;
            break;
        }
    }
}