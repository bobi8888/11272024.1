#pragma once
class Bullet {
	private:
		sf::Sprite Sprite;
		sf::Texture Texture;
		sf::Vector2f Target;
		float deltaX = 0.f;
		float deltaY = 0.f;
	public:
		Bullet() {}
		Bullet(string sprite, sf::Vector2f position, sf::Vector2f target);
		sf::Sprite getSprite();
		void updatePosition();
		~Bullet() {}
};

