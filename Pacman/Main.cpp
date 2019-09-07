#include<SFML/Graphics.hpp>
#include"Constant.h"
#include<iostream>
int main() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pacman");
	sf::Event event;
	sf::Texture WallTextTure;
	sf::Sprite Wall;
	sf::Vertex vertex;
	vertex.position = sf::Vector2f(10.f, 50.f);
	vertex.color = sf::Color::Red;
	vertex.texCoords = sf::Vector2f(100.f, 100.f);
	std::vector<sf::Vertex> vertices = { vertex };
	// loads the wall image and 
	WallTextTure.loadFromFile("blue.jpg");
	Wall.setTexture(WallTextTure);
	//
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			
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
			for (int i = 0; i < BLOCK_WIDTH; i++) {
				for (int j = 0; j < BLOCK_HEIGHT; j++) {
					if (map1[i][j] == 1) {
						Wall.setTextureRect(sf::IntRect(80, 80, 80, 80));
						Wall.setPosition(sf::Vector2f(i * 80, j * 80));
						window.draw(Wall);
					}
				}
			}
			window.display();
		}
	}
	return 0;
}


