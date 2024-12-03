#pragma once

class Enemy {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		const float BaselineHP = 5.f;
		float HP = 5.f;
		float Speed = 1;
		int PathPosition = 0;
		bool IsActive = false;
		bool IsAlive = true;

	public:
		Enemy(){}
		Enemy(string sprite, sf::Vector2f position);
		sf::Sprite getSprite();
		int getPathPositon();
		void incrementPathPosition();
		void updateX();
		float getX();
		float getY();
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

