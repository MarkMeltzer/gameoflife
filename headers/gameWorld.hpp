#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include "randomNumberGenerator.hpp"

class gameWorld {
private:
    // safe a reference to the rng
    randomNumberGenerator *rng;

    // declare grid
    static const int gridSize = 100;
    int grid[gridSize][gridSize];
    
    // initialize properties
    float aliveProbability;

public:
    gameWorld(randomNumberGenerator *r);

    // declare game functions
    void fillGrid(bool empty);
    void printGrid();
    void updateGame();
    int countAliveNb(int x, int y);
    void setAliveProbability(float p);
};

#endif