#pragma once
#include "PacmanAnimation.h"
#include "Fruit.h"
#include <vector>

class Brain {
private:
//    PacmanAnimation pacman;
    sf::Texture spriteSheet;
    PacmanAnimation& setupPacman();
    std::vector<Dot*> setupDots();
    std::vector<Fruit*> setupFruits();

public:
    Brain();
    void run();
    void createMap(sf::RenderWindow&);
};
