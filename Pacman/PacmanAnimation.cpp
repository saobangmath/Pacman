#include "PacmanAnimation.h"
#include <iostream>
using std::cout;

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
    float v = 5.0f;
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

