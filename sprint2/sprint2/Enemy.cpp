#include "utils.h"
#include "Enemy.h"

Enemy::Enemy(string sprite, sf::Vector2f position) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
}

sf::Sprite Enemy::getSprite() {
	return Sprite;
}

int Enemy::getPathPositon() {
	return PathPosition;
}

void Enemy::incrementPathPosition() {
	PathPosition++;
}

void Enemy::updateX() {
	Sprite.setPosition(Sprite.getPosition().x + Speed, Sprite.getPosition().y);
}
void Enemy::updateY() {
	Sprite.setPosition(Sprite.getPosition().x, Sprite.getPosition().y + Speed);
}
