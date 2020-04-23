#include "../headers/gameOfLife.hpp"
#include "../headers/gameWorld.hpp"
#include "../headers/gameMenu.hpp"
#include "../headers/randomNumberGenerator.hpp"
#include <cstdio>
#include <iostream>

int main() {
    randomNumberGenerator rng;
    gameWorld world(&rng);
    gameMenu menu(&world);
    gameOfLife game(&rng, &world, &menu);
    menu.linkGameObj(&game);
    
    game.startGame();


    std::cout << "This is the end of main..." << std::endl;
    return 0;
}