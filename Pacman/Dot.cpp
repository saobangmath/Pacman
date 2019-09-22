#include "Dot.h"
#include <iostream>
using std::cerr;
using std::endl;

Dot::Dot(sf::Sprite& sprite, sf::Vector2f position, DotType type): AnimationSpritesSheet(sprite, position) {
    isEatenYet = false;
    this -> type = type;
}

Dot::Dot(const Dot& other) {
    this -> position = position;
    this -> frames = other.frames;
    sf::Sprite sprite(other.target);
    this -> target = sprite;
}

void Dot::update() {
    // not eaten
    int positionFrame = 0;
    if(isEatenYet) {
        if(frames.size() < 2) {
            cerr << "Dot error: Does not have a being Eaten frame!" << endl;
            return;
        }
        positionFrame = 1;
    }
    target.setTextureRect(frames[positionFrame].rect);
}

bool Dot::isEaten() {
    return isEatenYet;
}

void Dot::beEaten() {
    isEatenYet = true;
    update();
}

DotType Dot::getType() {
    return type;
}

int Dot::getScore() {
    if(type == NORMAL) {
        return 10;
    }
    else if(type == BIG) {
        return 50;
    }
}

