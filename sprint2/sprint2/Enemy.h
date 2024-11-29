#pragma once

class Enemy {
	private:
		sf::Sprite Sprite;
		float HP = 5.f;
		//float Speed = 0.1;

	public:
		Enemy(){}
		Enemy(string sprite);
		~Enemy(){}
};

