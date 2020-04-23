#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

class gameOfLife;

#include "randomNumberGenerator.hpp"
#include "gameOfLife.hpp"

class gameWorld {
private:
    // safe a reference to the rng and game obj
    randomNumberGenerator *rng;
    gameOfLife *game;


    // declare grid
    static const int gridSize = 200;
    int grid[gridSize][gridSize];
    
    // initialize properties
    float aliveProbability;

public:
    gameWorld(randomNumberGenerator *r);

    // declare game functions
    void linkGameObj(gameOfLife *g);
    void fillGrid(bool empty);
    void printGrid();
    void updateGame();
    int countAliveNb(int x, int y);
    void setAliveProbability(float p);
};

#endif