#pragma once
#include<SFML/Graphics.hpp>
class TileMap : public sf::Drawable, public sf::Transformable 
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, int width, int height) {
		
	}
};

