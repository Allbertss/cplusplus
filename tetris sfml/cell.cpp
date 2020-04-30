#include "cell.h"

Cell::Cell() {

}

Cell::Cell(ui i, ui j) {	
	_body.setSize(sf::Vector2f(SCALE, SCALE));
	_body.setPosition(i * SCALE, j * SCALE);
}

Cell::~Cell() {

}

void Cell::draw(sf::RenderWindow &window) {
	_body.setOutlineThickness(1.0f);
	_body.setOutlineColor(sf::Color::Black);

	switch (_type) {
		case empty:
			_body.setFillColor(sf::Color::White);
			break;
		case wall:
			_body.setFillColor(sf::Color::Black);
			break;
		case tetromino:
			_body.setFillColor(sf::Color::Yellow);
			break;
		case locked:
			_body.setFillColor(sf::Color::Blue);
			break;
	}

	window.draw(_body);
}

void Cell::setType(ui t) {
	_type = t;
}

ui Cell::getType() const {
	return _type;
}