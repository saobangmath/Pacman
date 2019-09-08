#pragma once
#include "PacmanAnimation.h"
#ifndef CONSTANT
    #include "Constant.h"
    #define CONSTANT
#endif // CONSTANT

class Brain {
private:
//    PacmanAnimation pacman;
    sf::Texture spriteSheet;
    PacmanAnimation& setupPacman();

public:
    Brain();
    void run();
    // void createMap(sf::RenderWindow&);
};
