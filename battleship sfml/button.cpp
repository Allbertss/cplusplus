#include "button.h"

Button::Button() {

}

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Texture texture) : 
	_position(position), _size(size), _texture(texture) {
	_body.setSize(_size);
	_body.setPosition(_position);
	_body.setTexture(&_texture);
}

Button::~Button() {

}

void Button::draw(sf::RenderWindow &window) {
	window.draw(_body);
}

sf::Vector2f Button::getLeftPos() const {
	return _body.getPosition();
}

sf::Vector2f Button::getRightPos() const {
	return sf::Vector2f(_body.getPosition().x + _size.x, _body.getPosition().y + _size.y);
}