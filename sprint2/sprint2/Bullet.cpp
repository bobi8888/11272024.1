#include "utils.h"
#include "Bullet.h"

Bullet::Bullet(string sprite, sf::Vector2f position, sf::Vector2f target) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
	Target = target;
	DeltaX = (target.x - position.x) / 1000;
	DeltaY = (target.y - position.y) / 1000;
}
void Bullet::updatePosition() {
	Sprite.setPosition(Sprite.getPosition().x + DeltaX, Sprite.getPosition().y + DeltaY);
}
bool Bullet::hitEnemy(sf::FloatRect enemyBB) {
	
	if (Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width < enemyBB.left || Sprite.getGlobalBounds().left > enemyBB.left + enemyBB.width) {
		return false;
	}
		
	if (Sprite.getGlobalBounds().top + Sprite.getGlobalBounds().height < enemyBB.top || Sprite.getGlobalBounds().top > enemyBB.top + enemyBB.height) {
		return false;
	}		

	return true;
}
bool Bullet::getIsActive() {
	return IsActive;
}
void Bullet::setIsActive(bool isActive) {
	IsActive = isActive;
}
sf::Sprite Bullet::getSprite() {
	return Sprite;
}
