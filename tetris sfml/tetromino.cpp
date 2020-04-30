#include "tetromino.h"

Tetromino::Tetromino() {

}

Tetromino::Tetromino(bool tetromino[4][4]) {
	std::memcpy(_tetromino, tetromino, 4 * 4 * sizeof(bool));
}

Tetromino::~Tetromino() {

}

void Tetromino::rotate() {
	for (ui i = 0; i < 2; i++) {
		for (ui j = i; j < 3 - i; j++) {
			bool temp = _tetromino[i][j];
			_tetromino[i][j] = _tetromino[3 - j][i];
			_tetromino[3 - j][i] = _tetromino[3 - i][3 - j];
			_tetromino[3 - i][3 - j] = _tetromino[j][3 - i];
			_tetromino[j][3 - i] = temp;
		}
	}
}

bool Tetromino::getTetromino(ui i, ui j) const {
	return _tetromino[i][j];
}

sf::Vector2u Tetromino::getPoistion() const {
	return _pos;
}

void Tetromino::move(ui dir) {
	if (dir == left)
		_pos.x--;
	else if (dir == right)
		_pos.x++;
	else if (dir == down)
		_pos.y++;
}

Tetromino &Tetromino::operator=(const Tetromino &other) {
	std::memcpy(_tetromino, other._tetromino, 4 * 4 * sizeof(bool));
	_pos = other._pos;

	return *this;
}