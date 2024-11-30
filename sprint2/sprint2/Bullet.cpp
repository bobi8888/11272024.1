#include "utils.h"
#include "Bullet.h"

Bullet::Bullet(string sprite, sf::Vector2f position, sf::Vector2f target) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
	Target = target;
	deltaX = (target.x - position.x) / 1000;
	deltaY = (target.y - position.y) / 1000;
}
void Bullet::updatePosition() {
	Sprite.setPosition(Sprite.getPosition().x - deltaX, Sprite.getPosition().y - deltaY);
}
sf::Sprite Bullet::getSprite() {
	return Sprite;
}
