#pragma once
#include "definitions.h"

class Well {
	ui _types[ROWS][COLLUMNS];
public:
	Well();
	~Well();

	ui getType(ui i, ui j) const;
	void setType(ui i, ui j, ui t);
	void moveLineDown(ui j);
	void moveDown(ui i, ui j);
};