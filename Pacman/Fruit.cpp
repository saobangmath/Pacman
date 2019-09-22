#include "Fruit.h"

Fruit::Fruit(sf::Sprite& sprite, sf::Vector2f position, DotType type, FruitType fruitType): Dot(sprite, position, type) {
    this -> fruitType = fruitType;
}

int Fruit::getScore() {
    int score = 0;
    switch(fruitType) {
        case(CHERRY):
            score = 100;
            break;
        case (STRAWBERRY):
            score = 300;
            break;
        case(ORANGE):
            score = 500;
            break;
        case(BELL):
            score = 3000;
            break;
        case(APPLE):
            score = 700;
            break;
        case(MELON):
            score = 1000;
            break;
        case(GALAXIAN):
            score = 2000;
            break;
        case(KEY):
            score = 5000;
            break;
        case(EMPTY):
            score = 0;
            break;
    }
    return score;
}
