#include <cstdio>
#include <iostream>
#include <time.h>

class gameOfLife {
private:
    class randomNumberGenerator {
    public:
        long seed;
        void genSeed();
        float getRnd();

        randomNumberGenerator() {
            genSeed();
        }
    };
    randomNumberGenerator rng;
    
    class world {
    public:
        // declare grid
        static const int gridSize = 40;
        int grid[gridSize][gridSize];
        
        // initialize properties
        float aliveProbability;

        // declare game functions
        void fillGrid(bool empty, gameOfLife::randomNumberGenerator rng);
        void printGrid();
        void updateGame();
        int countAliveNb(int x, int y);
        void run();
    };
    world w;
    
    // declare menu functions
    void mainMenu();
        


public:
    // Set up the game
    gameOfLife() {
        w.aliveProbability = 0.5;

        w.fillGrid(false, rng);
        w.printGrid();

        while (true)
        {
            std::cin.get();
            w.updateGame();
            w.printGrid();
        }
    }

    
};

void gameOfLife::world::fillGrid(bool empty, randomNumberGenerator rng) {
    for (int x = 0; x < gridSize; x++) {
        for (int y = 0; y < gridSize; y++) {
            int cellValue;
            if (empty) {
                cellValue = 0;
            } else {
                if (rng.getRnd() < aliveProbability) {
                    cellValue = 1;
                } else {
                    cellValue = 0;
                }
            }

            grid[x][y] = cellValue;
        }
    }
}

void gameOfLife::world::printGrid() {
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

void gameOfLife::randomNumberGenerator::genSeed() {
    seed = time(NULL) % 2147483648;
}

float gameOfLife::randomNumberGenerator::getRnd() {
    seed = (214013 * seed + 12345) % 2147483648;
    return (float) seed / 2147483648;
}

void gameOfLife::world::updateGame() {
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

int gameOfLife::world::countAliveNb(int x_coord, int y_coord) {
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