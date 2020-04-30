#pragma once
#include "SFML/Graphics.hpp"

#include "definitions.h"

class Cell {
	sf::RectangleShape _body;
	ui _type = empty;
public:
	Cell();
	Cell(ui i, ui j);
	~Cell();

	void draw(sf::RenderWindow &window);

	void setType(ui t);
	ui getType() const;
};