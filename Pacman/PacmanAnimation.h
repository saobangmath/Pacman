#pragma once
#include "Animation.h"
#include <string>

enum DIRECTION {
    LEFT,
    UP,
    RIGHT,
    DOWN,
    NUMBER_DIRECTIONS
};

enum STATUS {
    EATING,
    NOT_EATING,
    NUMBER_STATUS
};

class PacmanAnimation: public AnimationSpritesSheet {
    private:
        DIRECTION direction;
        STATUS status;
        void changeDirection(DIRECTION);
        void changeStatus(STATUS);
    public:
        PacmanAnimation();
        PacmanAnimation(sf::Sprite& sprite, sf::Vector2f);
        void update();
        void move();
        void copyDirection(PacmanAnimation&);
        DIRECTION getDirection();
        void unmove();
        void turnLeft();
        void turnUp();
        void turnRight();
        void turnDown();
        void toEating();
        void toNotEating();
        PacmanAnimation& operator=(const PacmanAnimation&);
        sf::Vector2f getNextCellPosition();
        sf::Vector2f getSecondNextCellPosition();
        std::string getDirectionString();
        bool canMove();
};
