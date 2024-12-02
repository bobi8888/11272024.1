#pragma once

class Enemy {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		float HP = 5.f;
		float Speed = 60;
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
		void setHP(float damage);
		void hpCheckForActivity();
		~Enemy(){}
};

