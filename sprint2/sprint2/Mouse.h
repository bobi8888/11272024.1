#pragma once
class Mouse {
	private:
		sf::Vector2f Position;
		bool ValidMouseClick = false;
	public:
		Mouse() {}
		~Mouse() {}
		sf::Vector2f getPosition(sf::RenderWindow& window);
};

