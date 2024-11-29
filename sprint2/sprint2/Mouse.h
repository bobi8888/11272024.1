#pragma once
class Mouse {
	private:
		sf::Vector2f Position;
		bool LeftDown = false;
	public:
		Mouse() {}
		~Mouse() {}
		sf::Vector2f getPosition(sf::RenderWindow& window);
		bool validLeftClick(sf::Event event);

};

