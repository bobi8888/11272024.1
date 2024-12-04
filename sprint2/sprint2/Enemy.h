#pragma once

class Enemy {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		const float BaselineHP = 5.f;
		float HP = 5.f;
		float Speed = 10;
		int PathIndex = 0;
		bool IsActive = false;
		bool IsAlive = true;

	public:
		Enemy(){}
		Enemy(string sprite, sf::Vector2f position);
		Enemy(string sprite, sf::Vector2f position, float speed);

		sf::Sprite getSprite();
		void setPosition(sf::Vector2f position);

		int getPathIndex();
		void incrementPathIndex();

		float getX();
		float getY();
		void updateX();
		void updateY();

		bool getIsActive();
		void setIsActive(bool isActive);

		float getHP();
		void setHP(float damage);
		void hpCheckForActivity();
		bool isDestroyed();
		void healHP();

		~Enemy(){}
};

