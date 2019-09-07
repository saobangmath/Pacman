#include<SFML/Graphics.hpp>
#include"Constant.h"
#include<iostream>
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman");
	sf::Event event;
	sf::Texture WallTextTure;
	sf::Sprite Wall;
	// for fun only :v
	sf::CircleShape circle(200);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(200, 200);
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray triangle(sf::Triangles, 3);

	// define the position of the triangle's points
	triangle[0].position = sf::Vector2f(10.f, 10.f);
	triangle[1].position = sf::Vector2f(100.f, 10.f);
	triangle[2].position = sf::Vector2f(100.f, 100.f);

	// define the color of the triangle's points
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Blue;
	triangle[2].color = sf::Color::Green;
	// loads the wall image and 
	WallTextTure.loadFromFile("blue.jpg");
	
	Wall.setTexture(WallTextTure);
	Wall.setTextureRect(sf::IntRect(50,50,50,50));
	Wall.move(64,0);
	//
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type){
			case sf::Event::Closed:
				window.close(); break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::A) {
					std::cout << "LEFT!";
					Wall.move(-64, 0);
				}
				else if (event.key.code == sf::Keyboard::W) {
					std::cout << "UP!";
					Wall.move(0, -64);
				}
				else if (event.key.code == sf::Keyboard::S) {
					std::cout << "DOWN!";
					Wall.move(0, 64);
				}
				else if (event.key.code == sf::Keyboard::D) {
					std::cout << "RIGHT!";
					Wall.move(64, 0);
				}
	
				break;
			}
			window.clear();
			window.draw(Wall);
			window.draw(triangle);
			std::cout << CELL_SIZE;
			window.display();
		}
	}
	return 0;
}

