#pragma once

#define ui unsigned int

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define SCREEN_wMID SCREEN_WIDTH / 2
#define SCREEN_hMID SCREEN_HEIGHT / 2

#define ROWS 10
#define COLLUMNS ROWS

#define SCALE 30.0f
#define SCL SCALE / 2

#define ff for (short i = 0; i < ROWS; i++) for (short j = 0; j < COLLUMNS; j++)

enum Types {
	unoccupied,
	reserved,
	ship,
	dead,
	missed
};

enum Turns {
	player,
	bot,
	gameOverW,
	gameOverL
};