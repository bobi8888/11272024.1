#include "Button.h"

Button::Button(string texture, sf::Vector2f position) {
	Texture.loadFromFile(texture);

	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
}

sf::Sprite Button::getSprite() {
	return Sprite;
}

bool Button::containsMouse(sf::Vector2f mousePosition) {
	if (Sprite.getGlobalBounds().contains(mousePosition))
		return true;
	else
		return false;
}
