#include<SFML/Graphics.hpp>
#include"Constant.h"
#include<iostream>
int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pacman");
	sf::Event event;
	sf::Texture WallTextTure;
	sf::Sprite Wall;

	// loads the wall image and 
	WallTextTure.loadFromFile("blue.jpg");
	
	Wall.setTexture(WallTextTure);
	Wall.setTextureRect(sf::IntRect(50,50,50,50));
	Wall.move(64,0);
	//
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			for (int i = 19; i < BLOCK_WIDTH; i++) {
				for (int j = 19; j < BLOCK_HEIGHT; j++) {
					Wall.setTextureRect(sf::IntRect(50, 50, 50, 50));
					window.draw(Wall);
				}
			}
			switch (event.type){
			case sf::Event::Closed:
				window.close(); break;
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
			window.display();
		}
	}
	return 0;
}

