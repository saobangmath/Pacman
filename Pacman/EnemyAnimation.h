#pragma once
#include<SFML/Graphics.hpp>
class EnemyAnimation
{
	private:
		sf::Vector2f position;
		void changeStatus();
	
	public:
		EnemyAnimation();
		EnemyAnimation(sf::Sprite& sprite, sf::Vector2f position);
		void BFS(sf::Vector2f PacmanPosition);
		void toEating();
		void toNotEating();
};

