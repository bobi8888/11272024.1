#include "utils.h"
#include "Wave.h"
#include "Bullet.h"
#include "Tower.h"

Tower::Tower(string sprite, sf::Vector2f position) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
	Clock.restart();
}

sf::Sprite Tower::getSprite() {
	return Sprite;
}
bool Tower::getCanFire() {
	return CanFire;
}
void Tower::setCanFire(bool canFire) {
	CanFire = canFire;
}
void Tower::updateCanFire() {
	if (Clock.getElapsedTime().asMilliseconds() > FireRate) {
		Clock.restart();
		setCanFire(true);
	}
	else {
		setCanFire(false);
	}
}
sf::Vector2f Tower::getPosition() {
	return Sprite.getPosition();
}

float Tower::getRange() {
	return Range;
}
