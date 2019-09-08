#include <vector>
#include "SFML/Graphics.hpp"
#pragma once

struct Frame {
    sf::IntRect rect;
    Frame(sf::IntRect);
};

class AnimationSpritesSheet {

    protected:
        std::vector<Frame> frames;
        sf::Sprite target;

    public:
        AnimationSpritesSheet();
        AnimationSpritesSheet(sf::Sprite&);
        // AnimationSpritesSheet(AnimationSpritesSheet&);
        AnimationSpritesSheet& operator=(const AnimationSpritesSheet&);
        // change Frame
        virtual void update() = 0;
        // add Frame
        void addFrame(Frame);
        // get Current Frame to draw
        sf::Sprite& getCurrentFrame();
};
