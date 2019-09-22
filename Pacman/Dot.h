#include "Animation.h"

enum DotType {
    NORMAL,
    BIG,
    FRUIT,
    NUNMBER_DOT_TYPES
};

class Dot: public AnimationSpritesSheet {
    private:
        sf::Vector2f position;
        bool isEatenYet;
        DotType type;
    public:
        Dot(sf::Sprite&, sf::Vector2f position, DotType type);
        Dot(const Dot&);
        void update();
        bool isEaten();
        void beEaten();
        DotType getType();
        int getScore();
};


