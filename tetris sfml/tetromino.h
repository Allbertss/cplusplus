#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"

#include "definitions.h"

class Tetromino {
	bool _tetromino[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	sf::Vector2u _pos = {4, 0};
public:
	Tetromino();
	Tetromino(bool tetromino[4][4]);
	~Tetromino();

	void rotate();

	bool getTetromino(ui i, ui j) const;
	sf::Vector2u getPoistion() const;
	void move(ui dir);

	Tetromino &operator=(const Tetromino &tetromino);
};