#include "utils.h"
#include "Enemy.h"

Enemy::Enemy(string sprite) {
	sf::Texture texture;
	texture.loadFromFile(sprite);
	Sprite.setTexture(texture);
}
