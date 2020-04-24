#include "../headers/gameWorld.hpp"
#include <cstdio>
#include <iostream>

/**
 * Returns the current the aliveProbability parameter.
 * 
 * @return the aliveProbability parameter
 */
float gameWorld::getAliveProbability() {
    return aliveProbability;
}

/**
 * Changes the current the aliveProbability parameter.
 * 
 * @param p the aliveProbability parameter
 */
void gameWorld::setAliveProbability(float p) {
    aliveProbability = p;
}

/**
 * Changes the grid according to a pattern file.
 * 
 * @param file the ifstream object reference of the file
 */
void gameWorld::changeGridByFile(std::ifstream& file) {
    char c;
    int patternStartX = game->getViewPortX();
    int patternStartY = game->getViewPortY();
    int x = 0;
    int y = 0;
    while (file.get(c)) {
        if (c == '.' or c == ' ') {
            // new column of the grid
            grid[patternStartY + y][patternStartX + x] = 0;
            x++;
        } else if (c == '\n') {
            // new row of the grid
            y++;
            x = 0;
        } else {
            grid[patternStartY + y][patternStartX + x] = 1;
            x++;
        }
    }
}

/**
 * Fills the grid either with dead cells or randomly according to the
 * aliveProbability parameter.
 * 
 * @param empty determines whether the grid should be filled with dead cells
 */
void gameWorld::fillGrid(bool empty) {
    for (int x = 0; x < 200; x++) {
        for (int y = 0; y < 200; y++) {
            int cellValue;
            if (empty) {
                cellValue = 0;
            } else {
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

/**
 * Outputs the grid to the console according the viewport and cell
 * representation parameters.
 */
void gameWorld::printGrid() {
    int minX = game->getViewPortX();
    int minY = game->getViewPortY();
    int maxX = game->getViewPortSizeX();
    int maxY = game->getViewPortSizeY();

    for (int y = minY; y < minY + maxY; y++) {
        for (int x = minX; x < minX + maxX; x++) {
            if (x < 0 || y < 0 || x >= 200 || y >= 200) {
                // the current coordinates are not within the grid
                std::cout << '#';
            } else {
                if (grid[y][x] == 1) {
                    std::cout << game->getLifeCellChar();
                } else {
                    std::cout << game->getDeadCellChar();
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Updates the grid according to Conways game of life rules.
 */
void gameWorld::updateGame() {
    // create a new grid
    int updatedGrid[200][200];

    // iterater over the old grid to fill the new one
    for (int x = 0; x < 200; x++) {
        for (int y = 0; y < 200; y++) {
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
    for (int x = 0; x < 200; x++) {
        for (int y = 0; y < 200; y++) {
            grid[x][y] = updatedGrid[x][y];
        }
    }
}

/**
 * Counts the number of life cells in within a one cell
 * distance of a certain cell.
 * 
 * @param x_coord the x coordinate of the main cell
 * @param y_coord the y coordinate of the main cell
 * @return the amount of neighbours
 */
int gameWorld::countAliveNb(int x_coord, int y_coord) {
    int counter = 0;
    for (int x = x_coord - 1; x < x_coord + 2; x++) {
        for (int y = y_coord - 1; y < y_coord + 2; y++) {
            if (grid[x][y] == 1) {
                counter++;
            }
        }
    }
    // do not count the main cell itself, in the case it is alive
    return counter - grid[x_coord][y_coord];
}

/**
 * Links a gameOfLife object to this gameWorld object
 *
 * @param g the gameOfLife object reference
 */
void gameWorld::linkGameObj(gameOfLife *g) {
    game = g;
}

/**
 * Constructor. Stores to a randomNumberGenerator object
 * 
 * @param r the randomNumberGenerator object reference
 */
gameWorld::gameWorld(randomNumberGenerator *r) {
    rng = r;
}