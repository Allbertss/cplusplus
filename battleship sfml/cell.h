#pragma once
#include "SFML/Graphics.hpp"

#include "definitions.h"

#include <iostream>

class Cell {
	sf::RectangleShape _body;
	sf::Vector2f _position;
	sf::Vector2u _pos;
	sf::Vector2f _size {sf::Vector2f(SCALE, SCALE)};
	sf::Texture _textures[4];
	ui _type {unoccupied};

	bool _highlighted = false;
public:
	Cell();
	Cell(ui i, ui j, sf::Texture texture0, sf::Texture texture1, sf::Texture texture2, sf::Texture texture3);
	~Cell();

	void draw(sf::RenderWindow &window);
	void draw2(sf::RenderWindow &window);
	ui getType() const;
	void setType(ui t);
	void highlight(bool b);
	sf::Vector2f getLeftPos() const;
	sf::Vector2f getRightPos() const;
};