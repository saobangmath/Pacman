#include "SFML/Graphics.hpp"
#include "Brain.h"
#include <iostream>
#ifndef CONSTANT_H
#include "Constant.h"
#define CONSTANT_H 1
#endif // CONSTANT
using std::cout;
using std::cerr;
using std::endl;

const int CELL_SIZE = Constant::CELL_SIZE;
const int BIG_CELL_SIZE = Constant::BIG_CELL_SIZE;
const int BLOCK_HEIGHT = Constant::BLOCK_HEIGHT;
const int BLOCK_WIDTH  = Constant::BLOCK_WIDTH;

int map1[BLOCK_WIDTH][BLOCK_HEIGHT] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
											 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											 {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 1, 1, 1, 0, 2, 1},
											 {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
											 {1, 0, 0, 0, 0, 0, 0, 2, 1, 1},
											 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

Brain::Brain() {
    spriteSheet.loadFromFile("images/animationFrames3.png");
}

PacmanAnimation& Brain::setupPacman() {
    sf::Sprite sprite(spriteSheet);
    PacmanAnimation* pacman = new PacmanAnimation(sprite, sf::Vector2f(0.0f, 0.0f));
    int pacmanX[8] = {0, 2, 1, 3, 4, 6, 5, 7};
    int pacmanY = 3;
    for(int i = 0; i < 8; i++) {
        pacman->addFrame(Frame(sf::IntRect(pacmanX[i] * BIG_CELL_SIZE, pacmanY  * BIG_CELL_SIZE, BIG_CELL_SIZE, BIG_CELL_SIZE)));
    }
    int br = false;
    for(int i = 0; i < BLOCK_WIDTH && !br; i++)
        for(int j = 0; j < BLOCK_HEIGHT && !br; j++) {
            if(map1[i][j] == 0) {
                cout << i << " " << j << endl;
                cout << i * BIG_CELL_SIZE << " " << j * BIG_CELL_SIZE << endl;
                // must be j,i
                pacman->setPosition(sf::Vector2f(j * BIG_CELL_SIZE, i * BIG_CELL_SIZE));
                br = true;
            }
        }
    return *pacman;
}

std::vector<Dot*> Brain::setupDots() {
    sf::Sprite sprite(spriteSheet);
    Dot* dot = new Dot(sprite, sf::Vector2f(0.0f,0.0f), NORMAL);
    int dotX = 17;
    int dotY = 0;
    int emptyX = 22;
    int emptyY = 0;
    dot->addFrame(Frame(sf::IntRect(dotX * CELL_SIZE, dotY * CELL_SIZE, CELL_SIZE, CELL_SIZE)));
    // it is weird because we don't want the white border to appear
    dot->addFrame(Frame(sf::IntRect(emptyX * CELL_SIZE + 1, emptyY * CELL_SIZE + 1, CELL_SIZE - 5, CELL_SIZE - 5)));
    dot->update();

    Dot* bigDot = new Dot(sprite, sf::Vector2f(0.0f, 0.0f), BIG);
    int bigDotX = 21;
    int bigDotY = 0;
    bigDot->addFrame(Frame(sf::IntRect(bigDotX * CELL_SIZE, bigDotY * CELL_SIZE, CELL_SIZE, CELL_SIZE)));
    bigDot->addFrame(Frame(sf::IntRect(emptyX * CELL_SIZE + 1, emptyY * CELL_SIZE + 1, CELL_SIZE - 5, CELL_SIZE - 5)));
    bigDot->update();

    std::vector<Dot*> dots;
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++) {
            if(map1[i][j] == 0) {
                Dot* newDot = new Dot(*dot);
                // might be reverse (j, i)

                newDot->setPosition(sf::Vector2f(j * BIG_CELL_SIZE , i * BIG_CELL_SIZE ));
                newDot->setMargin(sf::Vector2f(CELL_SIZE / 2, CELL_SIZE / 2));
                dots.push_back(newDot);
                /// initiate the big dot
            }
            else if(map1[i][j] == 2) {
                Dot* newDot = new Dot(*bigDot);
                newDot->setPosition(sf::Vector2f(j * BIG_CELL_SIZE , i * BIG_CELL_SIZE ));
                newDot->setMargin(sf::Vector2f(CELL_SIZE / 2, CELL_SIZE / 2));
                dots.push_back(newDot);
            }
        }

    return dots;
}

std::vector<Fruit*> Brain::setupFruits() {
    sf::Sprite sprite(spriteSheet);
    std::vector<Fruit*> fruits;
    int fruitX = 0;
    int fruitY = 10;
    int emptyX = 22;
    int emptyY = 0;
    for(int i = 0; i < NUMBER_OF_FRUIT_TYPE; i++) {
        Fruit* fruit = new Fruit(sprite, sf::Vector2f(0.0f, 0.0f), FRUIT, (FruitType) i);
        fruit->addFrame(Frame(sf::IntRect((fruitX + i) * BIG_CELL_SIZE, fruitY * CELL_SIZE, BIG_CELL_SIZE, BIG_CELL_SIZE)));
        fruit->addFrame(Frame(sf::IntRect(emptyX * CELL_SIZE + 1, emptyY * CELL_SIZE + 1, CELL_SIZE - 5, CELL_SIZE - 5)));
        fruit->update();
        fruit->setPosition(sf::Vector2f(0, i * BIG_CELL_SIZE));
        fruits.push_back(fruit);
    }

    return fruits;
}

void Brain::createMap(sf::RenderWindow &window) {
	sf::Texture WallTextTure;
	sf::Sprite Wall;
	WallTextTure.loadFromFile("images/blue.jpg");
	Wall.setTexture(WallTextTure);

	for (int i = 0; i < BLOCK_WIDTH; i++) {
		for (int j = 0; j < BLOCK_HEIGHT; j++) {
			if (map1[i][j] == 1) {
				Wall.setTextureRect(sf::IntRect(BIG_CELL_SIZE, BIG_CELL_SIZE, BIG_CELL_SIZE, BIG_CELL_SIZE));
				// must be j, i
				Wall.setPosition(sf::Vector2f(j * BIG_CELL_SIZE, i * BIG_CELL_SIZE));
				window.draw(Wall);
			}
		}
	}
}

void Brain::run() {
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
    sf::Event event;
    sf::Clock clock;
    PacmanAnimation pacman = setupPacman();
    // for pending movement
    PacmanAnimation clonePacman = setupPacman();
    std::vector<Dot*> dots = setupDots();
    std::vector<Fruit*> fruits = setupFruits();
    cout << dots.size() << endl;
    int cnt = 0;
    bool start = false;
    int stop = 0;
    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                renderWindow.close();
            else if(event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    clonePacman.turnLeft();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    clonePacman.turnRight();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    clonePacman.turnUp();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    clonePacman.turnDown();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    stop ^= 1;
                }
            }
        }

        if(clock.getElapsedTime().asSeconds() >= 0.05f && stop == 0){
            if(start== true) {
                if(cnt % 2 == 0)
                    pacman.toEating();
                else
                    pacman.toNotEating();
                cnt += 1;

                // to know if pacman can do the act
                clonePacman.setPosition(pacman.getPosition());
                sf::Vector2f nextPosition = clonePacman.getNextCellPosition();

//                cout << "Next: [" << nextPosition.y / BIG_CELL_SIZE << " ," << nextPosition.x / BIG_CELL_SIZE << "]" << endl;
//                cout << nextPosition.x << " " << nextPosition.y << endl;
//                cout << "Current: [" << pacman.getPosition().y / BIG_CELL_SIZE << " ," << pacman.getPosition().x / BIG_CELL_SIZE << "]" << endl;
//                cout << pacman.getPosition().x << " " << pacman.getPosition().y << endl;
//                cout << (map1[(int) clonePacman.getNextCellPosition().y / BIG_CELL_SIZE ][(int) clonePacman.getNextCellPosition().x / BIG_CELL_SIZE] == 0 ? "Way" : "Wall" )<< endl;
//                cout << "Clone direction: " << clonePacman.getDirectionString() << " Pacman Direction: " << pacman.getDirectionString() << endl;
//                cout << "Adjancent: [" << pacman.getSecondNextCellPosition().y / BIG_CELL_SIZE << " ," << pacman.getSecondNextCellPosition().x / BIG_CELL_SIZE << "]" << endl;
//                cout << pacman.getSecondNextCellPosition().x << " " << pacman.getSecondNextCellPosition().y << endl;

                /// important that (y,x) not (x,y)
                if((pacman.getDirection() - clonePacman.getDirection()) % 2 == 0) {
                    pacman.copyDirection(clonePacman);
                }
                else if((int) pacman.getPosition().y % BIG_CELL_SIZE == 0 && (int) pacman.getPosition().x % BIG_CELL_SIZE == 0){
                    if(map1[(int) nextPosition.y / BIG_CELL_SIZE][(int) nextPosition.x / BIG_CELL_SIZE] == 0) {
                        pacman.copyDirection(clonePacman);
                    }
                }
                if((int) pacman.getPosition().y % BIG_CELL_SIZE == 0 && (int) pacman.getPosition().x % BIG_CELL_SIZE == 0){
                    if(map1[(int) pacman.getNextCellPosition().y / BIG_CELL_SIZE][(int) pacman.getNextCellPosition().x / BIG_CELL_SIZE] != 1 ){
                        pacman.move();
                    }
                }
                else
                    pacman.move();

                for(int i = 0; i < (int) dots.size(); i++){
                    if(pacman.isOverlap(*dots[i])) {
                        cout << "It did overlap" << endl;
                    }
                    if( !dots[i]->isEaten() && pacman.isOverlap(*dots[i])) {
                        cout << "and be eaten" << endl;
                        dots[i]->beEaten();
                    }
                }

                clock.restart();
            }
        }


        pacman.update();

        renderWindow.clear();
        Brain::createMap(renderWindow);
        for(int i = 0; i < (int) dots.size(); i++) {
            renderWindow.draw(dots[i]->getCurrentFrame());
        }
        for(int i = 0; i < (int) fruits.size(); i++) {
            renderWindow.draw(fruits[i]->getCurrentFrame());
        }
        renderWindow.draw(pacman.getCurrentFrame());

        renderWindow.display();
  }

  // delete &pacman;
}





