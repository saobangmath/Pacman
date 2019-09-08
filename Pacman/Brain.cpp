#include "Brain.h"
#include<iostream>
#include"Constant.h"
#include<SFML/Graphics.hpp>


// loads the wall image and 
void Brain::run() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pacman");
	sf::Event event;
	sf::Texture WallTextTure;
	sf::Sprite Wall;
	WallTextTure.loadFromFile("blue.jpg");
	Wall.setTexture(WallTextTure);
	while (window.isOpen()) {
		while (window.pollEvent(event)) {

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::A) {
					std::cout << "LEFT!";
					// Pacman move left
				}
				else if (event.key.code == sf::Keyboard::W) {
					std::cout << "UP!";
					// Pacman move up
				}
				else if (event.key.code == sf::Keyboard::S) {
					std::cout << "DOWN!";
					// Pacman move down
				}
				else if (event.key.code == sf::Keyboard::D) {
					std::cout << "RIGHT!";
					// Pacman move right
				}

				break;
			}

			window.clear();
			for (int i = 0; i < BLOCK_WIDTH; i++) {
				for (int j = 0; j < BLOCK_HEIGHT; j++) {
					if (map1[i][j] == 1) {
						Wall.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
						Wall.setPosition(sf::Vector2f(i * CELL_SIZE, j * CELL_SIZE));
						window.draw(Wall);
					}
				}
			}
			window.display();
		}
	}
}
