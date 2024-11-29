#pragma once

class Enemy {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		float HP = 5.f;
		float Speed = 0.5;
		int PathPosition = 0;

	public:
		Enemy(){}
		Enemy(string sprite, sf::Vector2f position);
		sf::Sprite getSprite();
		int getPathPositon();
		void incrementPathPosition();
		void updateX();
		void updateY();
		~Enemy(){}
};

