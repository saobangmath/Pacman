#include "Animation.h"

class Dot: public AnimationSpritesSheet {
    private:
        sf::Vector2f position;
    public:
        Dot(sf::Sprite&, sf::Vector2f position);
        Dot(const Dot&);
        void update();
};


