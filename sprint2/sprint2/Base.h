#pragma once
#include "utils.h"

class Base {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		int HP = 500;
		sf::RectangleShape HealthBar;
		sf::RectangleShape DamageBar;


	public:
		Base();
		Base(string texture, sf::Vector2f position);
		sf::Sprite getSprite();
		void drawBase(sf::RenderWindow& window);
		void damageHP(int dmg);
		int getHP();
};

