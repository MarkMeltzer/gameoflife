#include "../headers/gameOfLife.hpp"

gameOfLife::gameOfLife(randomNumberGenerator *r, gameWorld *w) {
    rng = r;
    world = w;

    world->setAliveProbability(0.5);

    world->fillGrid(false);
    world->printGrid();
}