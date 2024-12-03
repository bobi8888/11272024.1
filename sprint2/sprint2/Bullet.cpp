#include "utils.h"
#include "Bullet.h"

Bullet::Bullet(string sprite, sf::Vector2f position, sf::Vector2f target) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setScale(0.15, 0.15);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
	Target = target;
	DeltaX = round(((target.x - position.x) / Speed) * 100.0) / 100.0;
	DeltaY = round(((target.y - position.y) / Speed) * 100.0) / 100.0;
	cout << "\n DeltaX: " << DeltaX << " & DeltaY: " << DeltaY;
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
float Bullet::getDamage() {
	return Damage;
}
sf::Sprite Bullet::getSprite() {
	return Sprite;
}
