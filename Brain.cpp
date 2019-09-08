#include "SFML/Graphics.hpp"
#include "Brain.h"
#include <iostream>
#ifndef CONSTANT
    #include "Constant.h"
    #define CONSTANT 1
#endif // CONSTANT
using std::cout;
using std::cerr;
using std::endl;

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
    return *pacman;
}

void Brain::run() {
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
    sf::Event event;
    sf::Clock clock;
    PacmanAnimation pacman = setupPacman();

    int cnt = 0;
    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                renderWindow.close();
            else if(event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    pacman.turnLeft();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    pacman.turnRight();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    pacman.turnUp();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    pacman.turnDown();
                }
            }
        }

        if(clock.getElapsedTime().asSeconds() >= 0.05f){
            if(cnt % 2 == 0)
                pacman.toEating();
            else
                pacman.toNotEating();
            cnt += 1;
            pacman.move();
            clock.restart();
        }


        pacman.update();

        renderWindow.clear();
        Brain::createMap(renderWindow);
        renderWindow.draw(pacman.getCurrentFrame());

        renderWindow.display();
  }

  // delete &pacman;
}

void Brain::createMap(sf::RenderWindow &window) {
    int map1[BLOCK_WIDTH][BLOCK_HEIGHT] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
											 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
											 {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
											 {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
											 {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
											 {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
											 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	sf::Texture WallTextTure;
	sf::Sprite Wall;
	WallTextTure.loadFromFile("images/blue.jpg");
	Wall.setTexture(WallTextTure);
	for (int i = 0; i < BLOCK_WIDTH; i++) {
		for (int j = 0; j < BLOCK_HEIGHT; j++) {
			if (map1[i][j] == 1) {
				Wall.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
				Wall.setPosition(sf::Vector2f(i * CELL_SIZE, j * CELL_SIZE));
				window.draw(Wall);
			}
		}
	}
}



