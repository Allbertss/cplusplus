#include "text.h"

Text::Text() {

}

Text::Text(std::string text, int charSize, sf::Vector2f pos, sf::Color color, sf::Font font) :
	_text(text), _charSize(charSize), _pos(pos), _color(color), _font(font) {

}

Text::~Text() {

}

void Text::init() {
	_body.setFont(_font);
	_body.setPosition(_pos);
	_body.setFillColor(_color);
	_body.setCharacterSize(_charSize);
	_body.setString(_text);
}

void Text::draw(sf::RenderWindow &window) {

	window.draw(_body);
}

void Text::setText(std::string s) {
	_body.setString(s);
}
