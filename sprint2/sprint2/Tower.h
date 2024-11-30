#pragma once
class Tower {
	private:
		sf::Sprite Sprite;
		sf::Texture Texture;
		sf::Clock Clock;
		float FireRate = 1750.f;
		float Range = 100.f;
		
	public:
		Tower() {}
		Tower(string sprite, sf::Vector2f position);
		sf::Sprite getSprite();
		bool canFire();
		sf::Vector2f getPosition();
		float getRange();
		~Tower() {}
};
