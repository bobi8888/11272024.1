#pragma once
class Bullet {
	private:
		sf::Sprite Sprite;
		sf::Texture Texture;
		sf::Vector2f Target;
		float DeltaX = 0.f;
		float DeltaY = 0.f;
		float Damage = 100.f;
		bool IsActive = true;
	public:
		Bullet() {}
		Bullet(string sprite, sf::Vector2f position, sf::Vector2f target);
		sf::Sprite getSprite();
		void updatePosition();
		bool hitEnemy(sf::FloatRect enemyBB);
		bool getIsActive();
		void setIsActive(bool isActive);
		float getDamage();
		~Bullet() {}
};

