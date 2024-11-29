#include "utils.h"
#include "Bullet.h"

Bullet::Bullet(string sprite, sf::Vector2f target) {
	sf::Texture texture;
	texture.loadFromFile(sprite);
	Sprite.setTexture(texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	//Sprite.setPosition(position);
}
