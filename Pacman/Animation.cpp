
#include "SFML/Graphics.hpp"
#include "Animation.h"

Frame::Frame(sf::IntRect rect): rect(rect) {
}

AnimationSpritesSheet::AnimationSpritesSheet() {
}

AnimationSpritesSheet::AnimationSpritesSheet(sf::Sprite& target, sf::Vector2f position): target(target), position(position) {
}

void AnimationSpritesSheet::addFrame(Frame frame) {
    frames.push_back(frame);
}

sf::Sprite& AnimationSpritesSheet::getCurrentFrame() {
    return target;
}

void AnimationSpritesSheet::setPosition(sf::Vector2f position) {
    this -> position = position;
    target.setPosition(position);
}

sf::Vector2f AnimationSpritesSheet::getPosition() {
    return position;
}
