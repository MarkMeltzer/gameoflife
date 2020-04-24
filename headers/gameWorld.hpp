#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

class gameOfLife;

#include "randomNumberGenerator.hpp"
#include "gameOfLife.hpp"
#include <fstream>

class gameWorld {
private:
    // safe a reference to RandomNumberGenerator and gameOfLife objects
    randomNumberGenerator *rng;
    gameOfLife *game;

    // the cell grid
    int grid[200][200];
    
    // probability a cell will become alive when randomized
    float aliveProbability;

public:
    // functions that concern the aliveProbability parameter
    float getAliveProbability();
    void setAliveProbability(float p);
    
    // functions that concern the grid as a whole
    void changeGridByFile(std::ifstream& file);
    void fillGrid(bool empty);
    void printGrid();

    // function to get the next timestep
    void updateGame();

    // functions concerning the neighbours of a cell
    int countAliveNb(int x, int y);

    void linkGameObj(gameOfLife *g);

    // constructor
    gameWorld(randomNumberGenerator *r);
};

#endif