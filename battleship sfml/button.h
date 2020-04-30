#pragma once
#include "SFML/Graphics.hpp"

#include "definitions.h"

class Button {
	sf::Vector2f _position;
	sf::Vector2f _size {sf::Vector2f(SCALE, SCALE)};
	sf::Texture _texture;
	sf::RectangleShape _body;
public:
	Button();
	Button(sf::Vector2f position, sf::Vector2f size, sf::Texture texture);
	~Button();

	void draw(sf::RenderWindow &window);
	sf::Vector2f getLeftPos() const;
	sf::Vector2f getRightPos() const;
};