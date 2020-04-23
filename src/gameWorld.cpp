#include "../headers/gameWorld.hpp"
#include <cstdio>
#include <iostream>

gameWorld::gameWorld(randomNumberGenerator *r) {
    rng = r;
}

void gameWorld::setAliveProbability(float p) {
    aliveProbability = p;
}

void gameWorld::fillGrid(bool empty) {
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            int cellValue;
            if (empty) {
                cellValue = 0;
            } else {
                // std::cout << "wat";
                if (rng->getRnd() < aliveProbability) {
                    cellValue = 1;
                } else {
                    cellValue = 0;
                }
            }

            grid[x][y] = cellValue;
        }
    }
}

void gameWorld::printGrid() {
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            if (grid[x][y] == 1) {
                std::cout << 'O';
            } else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void gameWorld::updateGame() {
    int updatedGrid[gridSize][gridSize];
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            // count the alive neighbours
            int nb = countAliveNb(x, y);

            // apply the game of life rules
            if (nb < 2) {
                updatedGrid[x][y] = 0;
            } else if (nb > 3) {
                updatedGrid[x][y] = 0;
            } else if (nb == 3) {
                updatedGrid[x][y] = 1;
            } else {
                updatedGrid[x][y] = grid[x][y];
            }
        }
    }

    // replace the old grid with the new one
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            grid[x][y] = updatedGrid[x][y];
        }
    }
}

int gameWorld::countAliveNb(int x_coord, int y_coord) {
    int counter = 0;
    for (int x = x_coord - 1; x < x_coord + 2; x++) {
        for (int y = y_coord - 1; y < y_coord + 2; y++) {
            if (grid[x][y] == 1) {
                counter++;
            }
        }
    }
    return counter - grid[x_coord][y_coord];
}