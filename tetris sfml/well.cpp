#include "well.h"

Well::Well() {
	for (ui i = 0; i < ROWS; i++) {
		for (ui j = 0; j < COLLUMNS; j++) {
			_types[i][j] = empty;

			if (i == 0)
				_types[i][j] = wall;

			if (i == ROWS - 1)
				_types[i][j] = wall;

			if (j == COLLUMNS - 1)
				_types[i][j] = wall;
		}
	}
}

Well::~Well() {

}

ui Well::getType(ui i, ui j) const {
	return _types[i][j];
}

void Well::setType(ui i, ui j, ui t) {
	_types[i][j] = t;
}

void Well::moveLineDown(ui j) {
	for (ui i = 1; i < ROWS - 1; i++)
		_types[i][j] = _types[i][j - 1];
}

void Well::moveDown(ui i, ui j) {
	_types[i][j] = _types[i][j - 1];
}