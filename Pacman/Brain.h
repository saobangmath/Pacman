#pragma once
#include "PacmanAnimation.h"
#include "Dot.h"
#include <vector>

class Brain {
private:
//    PacmanAnimation pacman;
    sf::Texture spriteSheet;
    PacmanAnimation& setupPacman();
    std::vector<Dot*> setupDots();

public:
    Brain();
    void run();
    void createMap(sf::RenderWindow&);
};
