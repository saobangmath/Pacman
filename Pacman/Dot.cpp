#include "Dot.h"

Dot::Dot(sf::Sprite& sprite, sf::Vector2f position): AnimationSpritesSheet(sprite, position) {
}

Dot::Dot(const Dot& other) {
    this -> position = position;
    this -> frames = other.frames;
    sf::Sprite sprite(other.target);
    this -> target = sprite;
}

void Dot::update() {
    int positionFrame = 0;
    target.setTextureRect(frames[positionFrame].rect);
}

