#include <iostream>
#include <time.h>
#include <vector>

#include "SFML/Graphics.hpp"

#include "definitions.h"
#include "cell.h"
#include "text.h"
#include "button.h"

void reset();
void logic(Cell **g, Cell **p, Text &text, Text &infoText, Text &playerScoreText, Text &botScoreText);
sf::Vector2u smartShoot(sf::Vector2u c);
void shoot(sf::Vector2u c, Cell **g);
bool hit(sf::Vector2u c, Cell **g);
void autoPlaceShips(Cell **g);
ui getRandomNumber(ui to);
sf::Vector2u getRandomNumber(ui r, ui c);

ui turn = player; //getRandomNumber(2);
ui playerScore = 0;
ui botScore = 0;
bool scoreAdded = false;

int main() {
	// setup
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Battleship", sf::Style::Close | sf::Style::Titlebar);

	sf::Texture textures[4];
	textures[0].loadFromFile("res/images/ship.png");
	textures[1].loadFromFile("res/images/dead.png");
	textures[2].loadFromFile("res/images/unoccupied.png");
	textures[3].loadFromFile("res/images/missed.png");

	sf::Texture txtYesBtn;
	txtYesBtn.loadFromFile("res/images/yesButton.png");
	sf::Texture txtNoBtn;
	txtNoBtn.loadFromFile("res/images/noButton.png");

	sf::Font font;
	font.loadFromFile("res/fonts/font.ttf");

	sf::RectangleShape bound;
	bound.setFillColor(sf::Color::Transparent);
	bound.setOutlineColor(sf::Color::White);
	bound.setOutlineThickness(2.5f);
	bound.setSize(sf::Vector2f(260.0f, 200.0f));
	bound.setPosition(sf::Vector2f(10.0f, 370.0f));

	sf::RectangleShape line;
	line.setFillColor(sf::Color::White);
	line.setSize(sf::Vector2f(260.0f, 2.5f));
	line.setPosition(sf::Vector2f(10.0f, 400.0f));

	sf::RectangleShape infoBound;
	infoBound.setFillColor(sf::Color::Transparent);
	infoBound.setOutlineColor(sf::Color::White);
	infoBound.setOutlineThickness(2.5f);
	infoBound.setSize(sf::Vector2f(235.0f, 225.0f));
	infoBound.setPosition(sf::Vector2f(345.0f, 20.0f));

	sf::RectangleShape infoLine;
	infoLine.setFillColor(sf::Color::White);
	infoLine.setSize(sf::Vector2f(235.0f, 2.5f));
	infoLine.setPosition(sf::Vector2f(345.0f, 35.0f));

	Button yesBtn(sf::Vector2f(20.0f, 525.0f), sf::Vector2f(50.0f, 20.0f), txtYesBtn);
	Button noBtn(sf::Vector2f(100.0f, 525.0f), sf::Vector2f(50.0f, 20.0f), txtNoBtn);

	Text urGrid("Your grid", 32, sf::Vector2f(375.0f, 255.0f), sf::Color::White, font);
	Text battleship("Battleship: ", 32, sf::Vector2f(10.0f, 330.0f), sf::Color::White, font);
	Text console("Console ", 16, sf::Vector2f(15.0f, 375.0f), sf::Color::White, font);
	Text turnText("012345678901234567890123456789", 12, sf::Vector2f(15.0f, 410.0f), sf::Color::Yellow, font);
	Text infoText("012345678901234567890123456789", 12, sf::Vector2f(15.0f, 425.0f), sf::Color::Yellow, font);
	Text scoreText0("Player ", 12, sf::Vector2f(400.0f, 20.0f), sf::Color::Yellow, font);
	Text scoreText1(" Computer", 12, sf::Vector2f(470.0f, 20.0f), sf::Color::Yellow, font);
	Text playerScoreText("0", 12, sf::Vector2f(445.0f, 20.0f), sf::Color::White, font);
	Text botScoreText("0", 12, sf::Vector2f(460.0f, 20.0f), sf::Color::White, font);

	std::string letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
	std::vector<Text> numsH;
	numsH.reserve(ROWS);

	for (int i = 0; i < ROWS; i++)
		numsH.emplace_back(Text(letters[i], 18, sf::Vector2f(7.0f + (i * SCALE), 300.0f), sf::Color::White, font));

	std::vector<Text> numsV;
	numsH.reserve(COLLUMNS);

	for (int j = 0; j < COLLUMNS; j++)
		numsV.emplace_back(Text(std::to_string(j + 1), 18, sf::Vector2f(305.0f, 5.0f + (j * SCALE)), sf::Color::White, font));

	Cell **grid = new Cell * [ROWS];
	for (short i = 0; i < ROWS; i++)
		grid[i] = new Cell[COLLUMNS];

	ff grid[i][j] = Cell(i, j, textures[0], textures[1], textures[2], textures[3]);

	Cell **pGrid = new Cell * [ROWS];
	for (short i = 0; i < ROWS; i++)
		pGrid[i] = new Cell[COLLUMNS];

	ff pGrid[i][j] = Cell(i + 10, j + 10, textures[0], textures[1], textures[2], textures[3]);

	autoPlaceShips(grid);
	autoPlaceShips(pGrid);

	urGrid.init();
	battleship.init();
	console.init();
	turnText.init();
	infoText.init();
	scoreText0.init();
	scoreText1.init();
	playerScoreText.init();
	botScoreText.init();

	for (auto &n : numsH)
		n.init();

	for (auto &n : numsV)
		n.init();

	sf::Mouse mouse;

	// endless loop
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseMoved:
					if (turn == player)
						ff
						if (mouse.getPosition(window).x >= grid[i][j].getLeftPos().x && mouse.getPosition(window).x <= grid[i][j].getRightPos().x)
							if (mouse.getPosition(window).y >= grid[i][j].getLeftPos().y && mouse.getPosition(window).y <= grid[i][j].getRightPos().y)
								grid[i][j].highlight(true);
							else
								grid[i][j].highlight(false);
						else
							grid[i][j].highlight(false);
					break;
				case sf::Event::MouseButtonPressed:
					if (turn == player) {
						ff
							if (mouse.getPosition(window).x >= grid[i][j].getLeftPos().x && mouse.getPosition(window).x <= grid[i][j].getRightPos().x)
								if (mouse.getPosition(window).y >= grid[i][j].getLeftPos().y && mouse.getPosition(window).y <= grid[i][j].getRightPos().y)
									if (grid[i][j].getType() != missed && grid[i][j].getType() != dead)
										shoot(sf::Vector2u(i, j), grid);
					} else if (turn == gameOverW || turn == gameOverL) {
						if (mouse.getPosition(window).x >= yesBtn.getLeftPos().x && mouse.getPosition(window).x <= yesBtn.getRightPos().x)
							if (mouse.getPosition(window).y >= yesBtn.getLeftPos().y && mouse.getPosition(window).y <= yesBtn.getRightPos().y)
								reset();

						if (mouse.getPosition(window).x >= noBtn.getLeftPos().x && mouse.getPosition(window).x <= noBtn.getRightPos().x)
							if (mouse.getPosition(window).y >= noBtn.getLeftPos().y && mouse.getPosition(window).y <= noBtn.getRightPos().y)
								window.close();
					}
					break;
			}
		}

		logic(grid, pGrid, turnText, infoText, playerScoreText, botScoreText);

		// draw
		window.clear(sf::Color(51, 51, 51));

		ff grid[i][j].draw2(window);
		ff pGrid[i][j].draw(window);

		for (auto &n : numsH)
			n.draw(window);

		for (auto &n : numsV)
			n.draw(window);

		scoreText0.draw(window);
		scoreText1.draw(window);
		playerScoreText.draw(window);
		botScoreText.draw(window);
		turnText.draw(window);
		infoText.draw(window);
		window.draw(line);
		window.draw(infoLine);
		window.draw(bound);
		window.draw(infoBound);
		urGrid.draw(window);
		battleship.draw(window);
		console.draw(window);

		if (turn == gameOverW || turn == gameOverL) {
			yesBtn.draw(window);
			noBtn.draw(window);
		}

		window.display();
	}

	delete[] grid;
	delete[] pGrid;

	return 0;
}

void reset() {
	turn = getRandomNumber(2);
	scoreAdded = false;
}

void logic(Cell **g, Cell **p, Text &text, Text &infoText, Text &playerScoreText, Text &botScoreText) {
	short a = 0;
	short b = 0;

	ff if (g[i][j].getType() == ship) a++;
	ff if (p[i][j].getType() == ship) b++;

	if (a == 0)
		turn = gameOverW;
	else if (b == 0)
		turn = gameOverL;

	if (turn == player) {
		text.setText("Your turn...");
		infoText.setText("Shoot.");
	} else if (turn == bot) { // bot
		text.setText("Opponent's turn.");
		infoText.setText("Please wait.");
		sf::Vector2u c = getRandomNumber(ROWS, COLLUMNS);
		while ((p[c.x][c.y].getType() == missed || p[c.x][c.y].getType() == dead))
			c = getRandomNumber(ROWS, COLLUMNS);

		the:
		if (hit(c, p)) {
			p[c.x][c.y].setType(dead);
			c = smartShoot(c);
			goto the;
		} else {
			p[c.x][c.y].setType(missed);
			turn = player;
		}
	} else if (gameOverW) {
		if (!scoreAdded)
			playerScore++;

		playerScoreText.setText(std::to_string(playerScore));
		text.setText("You win!");
		infoText.setText("Play again?");
		scoreAdded = true;
	} else if (gameOverL) {
		if (!scoreAdded)
			botScore++;

		botScoreText.setText(std::to_string(botScore));
		text.setText("You lost!");
		infoText.setText("Play again?");
		scoreAdded = true;
	}
}

void shoot(sf::Vector2u c, Cell **g) {
	if (hit(c, g))
		g[c.x][c.y].setType(dead);
	else {
		g[c.x][c.y].setType(missed);
		turn = bot;
	}
}

sf::Vector2u smartShoot(sf::Vector2u c) {
	sf::Vector2u a = c;
	ui t = getRandomNumber(4);

	switch (t) {
		case 0:
			if (c.x != 0)
				c.x--;
			break;
		case 1:
			if (c.x != ROWS - 1)
				c.x++;
			break;
		case 2:
			if (c.y != 0)
				c.y--;
			break;
		case 3:
			if (c.y != COLLUMNS - 1)
				c.y++;
			break;
	}

	return c;
}

bool hit(sf::Vector2u c, Cell **g) {
	return (g[c.x][c.y].getType() == ship || g[c.x][c.y].getType() == dead) ? true : false;
}

void autoPlaceShips(Cell **g) {
	short ships = 4;
	short shipSizes[5] {2, 3, 3, 4, 5};

	while (ships >= 0) {
		if (getRandomNumber(2) == 0) { // ship is not rotated (horizontal)
			short cSize = shipSizes[ships]; // current ship size
			sf::Vector2u shipCoords = getRandomNumber(ROWS - cSize, COLLUMNS); // ships' heads' coords
			short x = shipCoords.x;
			short y = shipCoords.y;
			short counter = 0;

			for (short i = 0; i < cSize; i++)
				if (g[x + i][y].getType() == unoccupied)
					counter++;

			if (counter == cSize) {
				for (short i = 0; i < cSize; i++) {
					g[x + i][y].setType(ship);

					if (i == 0) {
						if (x != 0) {
							g[x - 1][y].setType(reserved);

							if (y != 0)
								g[x - 1][y - 1].setType(reserved);

							if (y != COLLUMNS - 1)
								g[x - 1][y + 1].setType(reserved);
						}
					}

					if (i == cSize - 1) {
						if (x != ROWS - 1) {
							g[x + i + 1][y].setType(reserved);

							if (y != 0)
								g[x + i + 1][y - 1].setType(reserved);

							if (y != COLLUMNS - 1)
								g[x + i + 1][y + 1].setType(reserved);
						}
					}

					if (y != 0)
						g[x + i][y - 1].setType(reserved);

					if (y != COLLUMNS - 1)
						g[x + i][y + 1].setType(reserved);
				} // end of: for (short i = 0; i < cSize; i++)

				ships--;
			}
		} else { // ship is rotated (vertical)
			short cSize = shipSizes[ships]; // current ship size
			sf::Vector2u shipCoords = getRandomNumber(ROWS, COLLUMNS - cSize); // ships' heads' coords
			short x = shipCoords.x;
			short y = shipCoords.y;
			short counter = 0;

			for (short j = 0; j < cSize; j++)
				if (g[x][y + j].getType() == unoccupied)
					counter++;

			if (counter == cSize) {
				for (short j = 0; j < cSize; j++) {
					g[x][y + j].setType(ship);

					if (j == 0) {
						if (y != 0) {
							g[x][y - 1].setType(reserved);

							if (x != 0)
								g[x - 1][y - 1].setType(reserved);

							if (x != ROWS - 1)
								g[x + 1][y - 1].setType(reserved);
						}
					}

					if (j == cSize - 1) {
						if (y + j != COLLUMNS - 1) {
							g[x][y + j + 1].setType(reserved);

							if (x != 0)
								g[x - 1][y + j + 1].setType(reserved);

							if (x != ROWS - 1)
								g[x + 1][y + j + 1].setType(reserved);
						}
					}

					if (x != 0)
						g[x - 1][y + j].setType(reserved);

					if (x != ROWS - 1)
						g[x + 1][y + j].setType(reserved);
				} // end of: for (short j = 0; j < cSize; j++)

				ships--;
			}
		}
	} // end of: while (ships >= 0)
}

ui getRandomNumber(ui to) {
	return rand() % to;
}

sf::Vector2u getRandomNumber(ui r, ui c) {
	return sf::Vector2u(rand() % r, rand() % c);
}