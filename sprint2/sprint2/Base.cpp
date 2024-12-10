#include "Base.h"

Base::Base(string texture, sf::Vector2f position) {

	Texture.loadFromFile(texture);

	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);

	HealthBar.setSize(sf::Vector2f(Sprite.getGlobalBounds().width, 15));
	HealthBar.setPosition(sf::Vector2f(position.x - Sprite.getGlobalBounds().width / 2, position.y + Sprite.getGlobalBounds().height / 2));
	HealthBar.setFillColor(sf::Color::Green);

	DamageBar.setSize(sf::Vector2f(Sprite.getGlobalBounds().width, 15));
	DamageBar.setPosition(sf::Vector2f(position.x - Sprite.getGlobalBounds().width / 2, position.y + Sprite.getGlobalBounds().height / 2));
	DamageBar.setFillColor(sf::Color::Red);
}

sf::Sprite Base::getSprite() {
	return Sprite;
}

void Base::drawBase(sf::RenderWindow& window) {
	window.draw(Sprite);
	window.draw(DamageBar);
	window.draw(HealthBar);
}

void Base::damageHP(int dmg) {
	HP -= dmg;
	HealthBar.setSize(sf::Vector2f(HealthBar.getGlobalBounds().width - 5, 15));
}

int Base::getHP() {
	return HP;
}
