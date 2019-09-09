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
                pacman->setPosition(sf::Vector2f(i * BIG_CELL_SIZE, j * BIG_CELL_SIZE));
                br = true;
            }
        }
    return *pacman;
}

std::vector<Dot*> Brain::setupDots() {
    sf::Sprite sprite(spriteSheet);
    Dot* dot = new Dot(sprite, sf::Vector2f(0.0f,0.0f));
    int dotX = 17;
    int dotY = 0;
    dot->addFrame(Frame(sf::IntRect(dotX * CELL_SIZE, dotY * CELL_SIZE, CELL_SIZE, CELL_SIZE)));
    dot->update();

    std::vector<Dot*> dots;
    for(int i = 0; i < BLOCK_WIDTH; i++)
        for(int j = 0; j < BLOCK_HEIGHT; j++) {
            if(map1[i][j] == 0) {
                Dot* newDot = new Dot(*dot);
                // might be reverse (j, i)
                newDot->setPosition(sf::Vector2f(i * BIG_CELL_SIZE + CELL_SIZE / 2, j * BIG_CELL_SIZE + CELL_SIZE / 2));
                dots.push_back(newDot);
            }
        }
    return dots;
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
				Wall.setPosition(sf::Vector2f(i * BIG_CELL_SIZE, j * BIG_CELL_SIZE));
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
    std::vector<Dot*> dots = setupDots();
    cout << dots.size() << endl;
    int cnt = 0;
    bool start = false;
    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                renderWindow.close();
            else if(event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    pacman.turnLeft();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    pacman.turnRight();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    pacman.turnUp();
                    start = true;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    pacman.turnDown();
                    start = true;
                }
            }
        }

        if(clock.getElapsedTime().asSeconds() >= 0.05f){
            if(start== true) {
                if(cnt % 2 == 0)
                    pacman.toEating();
                else
                    pacman.toNotEating();
                cnt += 1;
                pacman.move();
                float pacmanXf = pacman.getPosition().x * 1.0 / BIG_CELL_SIZE;
                float pacmanYf = pacman.getPosition().y * 1.0 / BIG_CELL_SIZE;
                int pacmanXi = pacman.getPosition().x / BIG_CELL_SIZE;
                int pacmanYi = pacman.getPosition().y / BIG_CELL_SIZE;
                cout << pacmanXi << " " << pacmanYi << endl;
                cout << pacmanXf << " " << pacmanYf << endl << endl;
                if(pacmanXf > pacmanXi || pacmanYf > pacmanYi){
                    if(pacmanXf > pacmanXi){
                        pacmanXi += 1;
                        if(map1[pacmanXi][pacmanYi] == 1){
                            pacman.unmove();
                        }
                    }
                    else if(pacmanYf > pacmanYi){
                        pacmanYi += 1;
                        if(map1[pacmanXi][pacmanYi] == 1){
                            pacman.unmove();
                        }
                    }
                }
                clock.restart();
            }
        }


        pacman.update();

        renderWindow.clear();
        Brain::createMap(renderWindow);
        for(int i = 0; i < dots.size(); i++) {
            renderWindow.draw(dots[i]->getCurrentFrame());
        }
        renderWindow.draw(pacman.getCurrentFrame());

        renderWindow.display();
  }

  // delete &pacman;
}





