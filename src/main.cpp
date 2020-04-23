#include "../headers/gameOfLife.hpp"
#include "../headers/gameWorld.hpp"
#include "../headers/gameMenu.hpp"
#include "../headers/randomNumberGenerator.hpp"
#include <cstdio>
#include <iostream>

int main() {
    randomNumberGenerator rng;
    gameWorld world(&rng);
    gameOfLife game(&rng, &world);
    gameMenu menu(&world, &game);


    std::cout << "This is the end of main..." << std::endl;
    return 0;
}