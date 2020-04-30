#pragma once
#include "SFML/Graphics.hpp"

#include "definitions.h"

class Text {
	sf::Font _font;
	sf::Vector2f _pos = sf::Vector2f(.0f, .0f);
	sf::Color _color = sf::Color::Black;
	int _charSize = 0;
	std::string _text = "";
	sf::Text _body;
public:
	Text();
	Text(std::string text, int charSize, sf::Vector2f pos, sf::Color color, sf::Font font);
	~Text();

	void init();
	void draw(sf::RenderWindow &window);
	void setText(std::string s);
};