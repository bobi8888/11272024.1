#pragma once
class Tower {
	private:
		sf::Sprite Sprite;
		sf::Texture Texture;
		sf::Clock Clock;
		float FireRate = 3000.f; //milliseconds between each shot
		float Range = 700.f;
		bool CanFire = false;
		
	public:
		Tower() {}
		Tower(string sprite, sf::Vector2f position);
		sf::Sprite getSprite();
		bool getCanFire();
		void setCanFire(bool canFire);
		void updateCanFire();
		sf::Vector2f getPosition();
		float getRange();
		~Tower() {}
};
