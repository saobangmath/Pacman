#include<SFML/Graphics.hpp>
#include<iostream>
void func() {
	for (int i = 0; i < 10; ++i) {
		std::cout << "Thread 1" << std::endl;
	}
}
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pacman");
	sf::CircleShape shape(400.f);
	shape.setFillColor(sf::Color::Green);
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	//main
	for (int i = 0; i < 10; i++) {
		std::cout << "Main" << std::endl;
	}
	sf::Thread thread(&func);
	// run thread;
	thread.launch();
	return 0;
}

