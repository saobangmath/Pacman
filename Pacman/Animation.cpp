#include "SFML/Graphics.hpp"
#include "Animation.h"

#ifndef CONSTANT_H
    #include "Constant.h"
    #define CONSTANT_H 1
#endif // CONSTANT
#include <iostream>
using std::cout;
using std::endl;

Frame::Frame(sf::IntRect rect): rect(rect) {
}

AnimationSpritesSheet::AnimationSpritesSheet() {
}

AnimationSpritesSheet::AnimationSpritesSheet(sf::Sprite& target, sf::Vector2f position): target(target), position(position) {
    margin = sf::Vector2f(0.0, 0.0);
}

void AnimationSpritesSheet::addFrame(Frame frame) {
    frames.push_back(frame);
}

sf::Sprite& AnimationSpritesSheet::getCurrentFrame() {
    return target;
}

void AnimationSpritesSheet::setPosition(sf::Vector2f position) {
    this -> position = position;
    this -> position += margin;
    target.setPosition(position);
}

sf::Vector2f AnimationSpritesSheet::getPosition() {
    // return (position - margin);
    return sf::Vector2f(position.x - margin.x, position.y - margin.y);
}

void AnimationSpritesSheet::setMargin(sf::Vector2f margin) {
    this -> position -= this -> margin;
    this -> margin = margin;
    setPosition(this -> position);
}

bool AnimationSpritesSheet::isOverlap(AnimationSpritesSheet& other) {
    float x = getPosition().x;
    float y = getPosition().y;
//    cout << "X: " << x << " Y: " << y << endl;
//    cout << "Margin: X:" << margin.x << " Y:" << margin.y << endl;
//    cout << "Other x:" << other.getPosition().x << "  Y:" << other.getPosition().y << endl;
    if(y > other.getPosition().y - Constant::BIG_CELL_SIZE / 2 && y < other.getPosition().y + Constant::BIG_CELL_SIZE / 2
        && x > other.getPosition().x - Constant::BIG_CELL_SIZE / 2 && x < other.getPosition().x + Constant::BIG_CELL_SIZE / 2)
            return true;
    else
        return false;


}
