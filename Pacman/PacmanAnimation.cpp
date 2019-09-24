#include "PacmanAnimation.h"
#include <iostream>
#ifndef CONSTANT_H
    #include "Constant.h"
    #define CONSTANT_H 1
#endif // CONSTANT
using std::cout;

extern int CELL_SIZE, BIG_CELL_SIZE;

//PacmanAnimation::PacmanAnimation() {
//    position = sf::Vector2f(0.0f, 0.0f);
//    direction = RIGHT;
//    status = EATING;
//}

PacmanAnimation::PacmanAnimation(sf::Sprite& sprite, sf::Vector2f postion): AnimationSpritesSheet(sprite, position){
    // this -> position = position;
    direction = RIGHT;
    status = EATING;
}

void PacmanAnimation::update() {
    // frame 0 and 1 would be LEFT
    // frame 2 and 3 would be UP
    // frame 4 and 5 would be RIGHT
    // frame 6 and 7 would be DOWN
    int positionFrame = direction * 2 + status;
    target.setTextureRect(frames[positionFrame].rect);
}

// only move horizontally or vertically
void PacmanAnimation::move() {
    sf::Vector2f speed(0.0f, 0.0f);
    float v = 3.0f;
    if(direction == LEFT || direction == RIGHT) {
        if(direction == LEFT)
            speed.x -= v;
        else
            speed.x += v;
    }
    else if(direction == UP || direction == DOWN) {
        if(direction == UP)
            speed.y -= v;
        else
            speed.y += v;
    }
    position += speed;
    target.setPosition(position);
}

void PacmanAnimation::unmove() {
    sf::Vector2f speed(0.0f, 0.0f);
    float v = 3.0f;
    if(direction == LEFT || direction == RIGHT) {
        if(direction == LEFT)
            speed.x += v;
        else
            speed.x -= v;
    }
    else if(direction == UP || direction == DOWN) {
        if(direction == UP)
            speed.y += v;
        else
            speed.y -= v;
    }
    position += speed;
    target.setPosition(position);
}

void PacmanAnimation::turnLeft() {
    changeDirection(LEFT);
}

void PacmanAnimation::turnUp() {
    changeDirection(UP);
}

void PacmanAnimation::turnRight() {
    changeDirection(RIGHT);
}

void PacmanAnimation::turnDown() {
    changeDirection(DOWN);
}

void PacmanAnimation::toEating() {
    changeStatus(EATING);
}

void PacmanAnimation::toNotEating() {
    changeStatus(NOT_EATING);
}

void PacmanAnimation::changeDirection(DIRECTION direction) {
    this -> direction = direction;
    update();
}

DIRECTION PacmanAnimation::getDirection() {
    return direction;
}

void PacmanAnimation::copyDirection(PacmanAnimation& other) {
    changeDirection(other.direction);
}

void PacmanAnimation::changeStatus(STATUS status){
    this -> status = status;
    update();
}

PacmanAnimation& PacmanAnimation::operator=(const PacmanAnimation& other) {
    this -> frames = other.frames;
    this -> direction = other.direction;
    this -> status = other.status;
    sf::Sprite sprite(other.target);
    this -> target = sprite;
    return *this;
}

sf::Vector2f PacmanAnimation::getNextCellPosition() {
    // convert to cell coordinate
    float pacmanXf = getPosition().x * 1.0 / Constant::BIG_CELL_SIZE;
    float pacmanYf = getPosition().y * 1.0 / Constant::BIG_CELL_SIZE;
    int pacmanXi = getPosition().x / Constant::BIG_CELL_SIZE;
    int pacmanYi = getPosition().y / Constant::BIG_CELL_SIZE;
    // LEFT only if it in the CELL completely
    if(direction == LEFT || direction == RIGHT){
        if( pacmanYf == pacmanYi) {
            if(direction == LEFT) {
                pacmanXi -= 1;
            }
        }
        // RIGHT always has to +1
        if(direction == RIGHT) {
            pacmanXi += 1;
        }
    }
    // UP is like LEFT
    if(pacmanXf == pacmanXi) {
        if(direction == UP) {
            pacmanYi -= 1;
        }

    }
    // DOWN is like RIGHT
    if(direction == DOWN) {
        pacmanYi += 1;
    }
    // convert back to window coordinate
    return sf::Vector2f(pacmanXi * Constant::BIG_CELL_SIZE, pacmanYi * Constant::BIG_CELL_SIZE);
}

sf::Vector2f PacmanAnimation::getSecondNextCellPosition() {
    // convert to cell coordinate
    float pacmanXf = getPosition().x * 1.0 / Constant::BIG_CELL_SIZE;
    float pacmanYf = getPosition().y * 1.0 / Constant::BIG_CELL_SIZE;
    int pacmanXi = getPosition().x / Constant::BIG_CELL_SIZE;
    int pacmanYi = getPosition().y / Constant::BIG_CELL_SIZE;
    int retX = getNextCellPosition().x / Constant::BIG_CELL_SIZE;
    int retY = getNextCellPosition().y / Constant::BIG_CELL_SIZE;
    if(pacmanYf != pacmanYi) {
        if(direction == LEFT) {
            retY = getNextCellPosition().y / Constant::BIG_CELL_SIZE + 1;
        }
        else if(direction == RIGHT) {
            retY = getNextCellPosition().y / Constant::BIG_CELL_SIZE + 1;
        }
    }
    if(pacmanXf != pacmanXi) {
        if(direction == UP) {
            retX = getNextCellPosition().x / Constant::BIG_CELL_SIZE + 1;
        }
        else if(direction == DOWN) {
            std::cout << "PACMAN Xf: " << pacmanXf << std::endl;
            retX = getNextCellPosition().x / Constant::BIG_CELL_SIZE + 1;
        }
    }
    // convert back to window coordinate
    return sf::Vector2f(retX * Constant::BIG_CELL_SIZE, retY * Constant::BIG_CELL_SIZE);
}

std::string PacmanAnimation::getDirectionString() {
    switch(direction){
        case (LEFT): {
            return "Left";
        }
        case (RIGHT): {
            return "Right";
        }
        case (UP): {
            return "Up";
        }
        case (DOWN): {
            return "Down";
        }
    }
}

//bool PacmanAnimation::canMove() {
//    int x = position.x;
//    int y = position.y;
//    if(x % BIG_CELL_SIZE == 0 && y % BIG_CELL_SIZE == 0)
//
//}
