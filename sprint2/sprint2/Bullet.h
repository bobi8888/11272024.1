#pragma once
class Bullet {
	private:
		sf::Sprite Sprite;
		float xDelta = 0.f;
		float yDelta = 0.f;
	public:
		Bullet() {}
		Bullet(string sprite, sf::Vector2f target);
		~Bullet() {}
};

