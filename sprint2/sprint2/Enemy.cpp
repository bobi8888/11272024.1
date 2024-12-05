#include "Enemy.h"

Enemy::Enemy(string sprite, sf::Vector2f position) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
}
Enemy::Enemy(string sprite, sf::Vector2f position, float speed, float targetY) {
	Texture.loadFromFile(sprite);
	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
	Speed = speed;
	if (position.y > targetY)
		IsAboveMid = false;	
	else 
		IsAboveMid = true;	
}
sf::Sprite Enemy::getSprite() {
	return Sprite;
}
void Enemy::setPosition(sf::Vector2f position) {
	Sprite.setPosition(position);
}
int Enemy::getPathIndex() {
	return PathIndex;
}
void Enemy::incrementPathIndex() {
	PathIndex++;
}
float Enemy::getPrevX() {
	return PrevX;
}
void Enemy::setPrevX() {
	PrevX = Sprite.getPosition().x;
}
float Enemy::getPrevY() {
	return PrevY;
}
void Enemy::setPrevY() {
	PrevY = Sprite.getPosition().y;
}
float Enemy::getX() {
	return Sprite.getPosition().x;
}
float Enemy::getY() {
	return Sprite.getPosition().y;
}
void Enemy::updateX() {
	Sprite.setPosition(Sprite.getPosition().x + Speed, Sprite.getPosition().y);
}
void Enemy::updateY() {
	if (IsAboveMid) 
		Sprite.setPosition(Sprite.getPosition().x, Sprite.getPosition().y + Speed);
	else
		Sprite.setPosition(Sprite.getPosition().x, Sprite.getPosition().y - Speed);
}
bool Enemy::getIsActive() {
	return IsActive;
}
void Enemy::setIsActive(bool isActive) {
	IsActive = isActive;
}
float Enemy::getHP() {
	return HP;
}
void Enemy::setHP(float damage) {
	HP = HP - damage;
}
void Enemy::hpCheckForActivity() {
	if (HP <= 0)
		IsActive = false;
}
bool Enemy::isDestroyed() {
	if (HP <= 0 && IsActive) {
		IsActive = false;
		return true;
	}
	return false;
}
void Enemy::healHP() {
	HP = BaselineHP;
}
