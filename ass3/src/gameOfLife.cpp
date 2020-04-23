#include <cstdio>
#include <iostream>
#include <time.h>

class gameOfLife {
private:
        // declare grid
        static const int gridSize = 40;
        int grid[gridSize][gridSize];
        
        // initialize properties
        long seed;
        float aliveProbability;

        // declare game functions
        void fillGrid(bool empty);
        void printGrid();
        void genSeed();
        float getRnd();
        void updateGame();
        int countAliveNb(int x, int y);
        void run();

        // declare menu functions
        void mainMenu();
        


public:
        // Set up the game
        gameOfLife() {
            aliveProbability = 0.5;

            genSeed();
            fillGrid(false);
            printGrid();

            while (true)
            {
                std::cin.get();
                updateGame();
                printGrid();
            }
        }

    
};

void gameOfLife::fillGrid(bool empty) {
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            int cellValue;
            if (empty) {
                cellValue = 0;
            } else {
                if (getRnd() < aliveProbability) {
                    cellValue = 1;
                } else {
                    cellValue = 0;
                }
            }

            grid[x][y] = cellValue;
        }
    }
}

void gameOfLife::printGrid() {
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

void gameOfLife::genSeed() {
    seed = time(NULL) % 2147483648;
}

float gameOfLife::getRnd() {
    seed = (214013 * seed + 12345) % 2147483648;
    return (float) seed / 2147483648;
}

void gameOfLife::updateGame() {
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

int gameOfLife::countAliveNb(int x_coord, int y_coord) {
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


int main() {
    gameOfLife g;

    return 0;
}