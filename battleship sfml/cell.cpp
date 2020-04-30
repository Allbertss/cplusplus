#include "cell.h"

Cell::Cell() {

}

Cell::Cell(ui i, ui j, sf::Texture texture0, sf::Texture texture1, sf::Texture texture2, sf::Texture texture3) : _pos(sf::Vector2u(i, j)), _position(sf::Vector2f(i * _size.x, j * _size.y)) {
	_body.setSize(_size);
	_body.setPosition(_position);
	_textures[0] = texture0;
	_textures[1] = texture1;
	_textures[2] = texture2;
	_textures[3] = texture3;
}

Cell::~Cell() {

}

void Cell::draw(sf::RenderWindow &window) {
	if (this->_type == unoccupied)
		_body.setTexture(&_textures[2]);
	else if (this->_type == reserved)
		_body.setTexture(&_textures[2]);
	else if (this->_type == ship)
		_body.setTexture(&_textures[0]);
	else if (this->_type == dead)
		_body.setTexture(&_textures[1]);
	else if (this->_type == missed)
		_body.setTexture(&_textures[3]);

	window.draw(_body);
}

void Cell::draw2(sf::RenderWindow &window) {
	if (!_highlighted) {
		_body.setOutlineThickness(1.0f);
		_body.setOutlineColor(sf::Color::Black);
		_body.setTexture(&_textures[2]);
	} else {
		_body.setOutlineThickness(1.7f);

		if (this->_type == dead || this->_type == missed)
			_body.setOutlineColor(sf::Color::Red);
		else
			_body.setOutlineColor(sf::Color::Yellow);
	}

	if (this->_type == dead)
		_body.setTexture(&_textures[1]);
	else if (this->_type == missed)
		_body.setTexture(&_textures[3]);

	window.draw(_body);
}

ui Cell::getType() const {
	return _type;
}

void Cell::setType(ui t) {
	_type = t;
}

void Cell::highlight(bool b) {
	_highlighted = b;
}

sf::Vector2f Cell::getLeftPos() const {
	return _body.getPosition();
}

sf::Vector2f Cell::getRightPos() const {
	return sf::Vector2f(_body.getPosition().x + SCALE, _body.getPosition().y + SCALE);
}