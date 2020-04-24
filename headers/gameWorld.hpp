#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

class gameOfLife;

#include "randomNumberGenerator.hpp"
#include "gameOfLife.hpp"
#include <fstream>

class gameWorld {
private:
    // safe a reference to the rng and game obj
    randomNumberGenerator *rng;
    gameOfLife *game;


    // declare grid
    int grid[200][200];
    
    // initialize properties
    float aliveProbability;

public:
    gameWorld(randomNumberGenerator *r);

    // declare game functions
    void linkGameObj(gameOfLife *g);
    void changeGridByFile(std::ifstream& file);
    void fillGrid(bool empty);
    void printGrid();
    void updateGame();
    int countAliveNb(int x, int y);
    void setAliveProbability(float p);
    float getAliveProbability();
};

#endif