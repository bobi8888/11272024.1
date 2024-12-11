#pragma once
#include "utils.h"

class Button {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;

	public:
		Button(){}
		Button(string texture, sf::Vector2f position);
		sf::Sprite getSprite();
		bool containsMouse(sf::Vector2f mousePosition);
		~Button(){}
};

