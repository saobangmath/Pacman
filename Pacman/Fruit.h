#include "Dot.h"

enum FruitType {
    CHERRY, // 100
    STRAWBERRY, // 300
    ORANGE, // 500
    BELL, // 3000
    APPLE, // 700
    MELON, // 1000
    GALAXIAN, // 2000
    KEY, // 5000
    NUMBER_OF_FRUIT_TYPE,
    EMPTY, // 0
};

class Fruit: public Dot {
private:
    FruitType fruitType;
public:
    Fruit(sf::Sprite&, sf::Vector2f, DotType, FruitType);
    int getScore();
};
