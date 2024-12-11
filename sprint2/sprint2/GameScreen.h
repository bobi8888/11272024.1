#pragma once
#include "utils.h"
#include "Button.h"

class GameScreen {
	private:
		sf::Texture Texture;
		sf::Sprite Sprite;
		sf::Font Font;
		sf::Text Text;
		vector <Button> Buttons;

	public:
		GameScreen();
		GameScreen(string texture, sf::Vector2f position);
		GameScreen(string texture, sf::Vector2f position, string font, int charSize, sf::Vector2f textPosition, string textString);
		void drawScreen(sf::RenderWindow& window);
		bool contains(sf::Vector2f point);
		void addButton(string texture, sf::Vector2f position);
		Button getButton(int button);
};

