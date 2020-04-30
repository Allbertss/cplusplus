#include <iostream>
#include <time.h>

#include "SFML/Graphics.hpp"

#include "definitions.h"
#include "cell.h"
#include "well.h"
#include "tetromino.h"

bool check(Well &well, Tetromino &tetromino, ui dir);
ui lineDetection(Well &well);

int main() {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tetris", sf::Style::Close | sf::Style::Titlebar);

	Cell **grid = new Cell*[ROWS];
	for (short i = 0; i < ROWS; i++)
		grid[i] = new Cell[COLLUMNS];

	ff grid[i][j] = Cell(i, j);

	Well well;
	Tetromino *tetrominos = new Tetromino[7];

	bool tmp0[4][4] = {{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
	bool tmp1[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
	bool tmp2[4][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
	bool tmp3[4][4] = {{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
	bool tmp4[4][4] = {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
	bool tmp5[4][4] = {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
	bool tmp6[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
	tetrominos[0] = Tetromino(tmp0);
	tetrominos[1] = Tetromino(tmp1);
	tetrominos[2] = Tetromino(tmp2);
	tetrominos[3] = Tetromino(tmp3);
	tetrominos[4] = Tetromino(tmp4);
	tetrominos[5] = Tetromino(tmp5);
	tetrominos[6] = Tetromino(tmp6);

	ui tick = 0;

	bool keyPressed[2] = {false, false};

	bool lock = false;
	bool gameOver = false;

	ui current = rand() % 7;

	sf::Event event;
	while (window.isOpen()) {
		if (gameOver)
			break;

		if (lock) {
			current = rand() % 7;

			switch (current) {
				case 0:
					tetrominos[current] = Tetromino(tmp0);
					break;
				case 1:
					tetrominos[current] = Tetromino(tmp1);
					break;
				case 2:
					tetrominos[current] = Tetromino(tmp2);
					break;
				case 3:
					tetrominos[current] = Tetromino(tmp3);
					break;
				case 4:
					tetrominos[current] = Tetromino(tmp4);
					break;
				case 5:
					tetrominos[current] = Tetromino(tmp5);
					break;
				case 6:
					tetrominos[current] = Tetromino(tmp6);
					break;
			}

			if (check(well, tetrominos[current], down))
				gameOver = true;

			lock = false;
		}

		if (gameOver)
			std::cout << "Game Over\n";

		// Timing
		sf::sleep(sf::milliseconds(25));
		tick++;

		// Input
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
						if (!check(well, tetrominos[current], left))
							tetrominos[current].move(left);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
						if (!check(well, tetrominos[current], right))
							tetrominos[current].move(right);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
						if (!check(well, tetrominos[current], down))
							tetrominos[current].move(down);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !keyPressed[0]) {
						if (!check(well, tetrominos[current], 3)) {
							for (ui i = 0; i < ROWS; i++)
								for (ui j = 0; j < COLLUMNS; j++)
									if (grid[i][j].getType() == tetromino)
										grid[i][j].setType(empty);

							tetrominos[current].rotate();
						}

						keyPressed[0] = true;
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && !keyPressed[1]) {
						// escape (pause)
						keyPressed[1] = true;
					}
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Space)
						keyPressed[0] = false;

					if (event.key.code == sf::Keyboard::Escape)
						keyPressed[1] = false;
					break;
			}
		}

		// Logic
		if (tick == 20) {
			if (!check(well, tetrominos[current], down))
				tetrominos[current].move(down);
			else { // lock tetromino
				for (ui i = 0; i < 4; i++)
					for (ui j = 0; j < 4; j++)
						if (tetrominos[current].getTetromino(i, j)) {
							well.setType(tetrominos[current].getPoistion().x + j, tetrominos[current].getPoistion().y + i, locked);
							lock = true;
						}

				for (ui i = 0; i < 4; i++)
					if (lineDetection(well) != 0) {
						ui y = lineDetection(well);
						for (ui j = y; j > 0; j--)
							well.moveLineDown(j);
					}
			}

			tick = 0;
		}

		ff grid[i][j].setType(well.getType(i, j));

		// set tetromino to grid
		for (ui i = 0; i < 4; i++)
			for (ui j = 0; j < 4; j++)
				if (tetrominos[current].getTetromino(i, j))
					if (!lock)
						grid[tetrominos[current].getPoistion().x + j][tetrominos[current].getPoistion().y + i].setType(tetromino);

		// Draw
		window.clear(sf::Color(51, 51, 51));

		ff grid[i][j].draw(window);

		window.display();
	}

	for (ui i = 0; i < ROWS; i++)
		delete[] grid[i];

	delete[] grid;

	return 0;
}

bool check(Well &well, Tetromino &tetromino, ui dir) {
	switch (dir) {
		case left:
			for (ui i = 0; i < 4; i++)
				for (ui j = 0; j < 4; j++)
					if (tetromino.getTetromino(i, j))
						if (well.getType(tetromino.getPoistion().x + j - 1, tetromino.getPoistion().y + i) != empty)
							return true;
			break;
		case right:
			for (ui i = 0; i < 4; i++)
				for (ui j = 0; j < 4; j++)
					if (tetromino.getTetromino(i, j))
						if (well.getType(tetromino.getPoistion().x + j + 1, tetromino.getPoistion().y + i) != empty)
							return true;
			break;
		case down:
			for (ui i = 0; i < 4; i++)
				for (ui j = 0; j < 4; j++)
					if (tetromino.getTetromino(i, j))
						if (well.getType(tetromino.getPoistion().x + j, tetromino.getPoistion().y + i + 1) != empty)
							return true;
			break;
		case 3:
			Tetromino temp = tetromino;
			temp.rotate();
			for (ui i = 0; i < 4; i++)
				for (ui j = 0; j < 4; j++)
					if (temp.getTetromino(i, j))
						if (well.getType(temp.getPoistion().x + j, temp.getPoistion().y + i) != empty)
							return true;
			break;
	}

	return false;
}

ui lineDetection(Well &well) {
	for (ui j = COLLUMNS - 1; j > 0; j--) {
		ui counter = 0;
		ui collumn = 0;
		for (ui i = 1; i < ROWS - 1; i++)
			if (well.getType(i, j) == locked) {
				counter++;
				collumn = j;
			}

		if (counter == ROWS - 2)
			return collumn;
	}

	return 0;
}