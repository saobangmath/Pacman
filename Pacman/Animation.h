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
        sf::Vector2f position;
        sf::Vector2f margin;

    public:
        AnimationSpritesSheet();
        AnimationSpritesSheet(sf::Sprite&, sf::Vector2f position);
        // AnimationSpritesSheet(AnimationSpritesSheet&);
        AnimationSpritesSheet& operator=(const AnimationSpritesSheet&);
        // change Frame
        virtual void update() = 0;
        // add Frame
        void addFrame(Frame);
        // get Current Frame to draw
        sf::Sprite& getCurrentFrame();
        // set the position
        void setPosition(sf::Vector2f position);
        // get position
        sf::Vector2f getPosition();
        void setMargin(sf::Vector2f margin);
        sf::Vector2f getMargine();
        bool isOverlap(AnimationSpritesSheet&);
};
