#pragma once

// w 10 cells + 2
// h 20 cells + 2

#define ui unsigned int

#define SCREEN_WIDTH 360
#define SCREEN_HEIGHT 660

#define ROWS 12
#define COLLUMNS 22

#define SCALE 30.0f

#define ff for (ui i = 0; i < ROWS; i++) for (ui j = 0; j < COLLUMNS; j++)

enum Types {
	empty,
	tetromino,
	wall,
	locked
};

enum Directions {
	left,
	right,
	down
};