
#include "SFML/Graphics.hpp"
#include "Animation.h"

Frame::Frame(sf::IntRect rect): rect(rect) {
}

AnimationSpritesSheet::AnimationSpritesSheet(sf::Sprite& target): target(target) {
}

void AnimationSpritesSheet::addFrame(Frame frame) {
    frames.push_back(frame);
}

sf::Sprite& AnimationSpritesSheet::getCurrentFrame() {
    return target;
}
