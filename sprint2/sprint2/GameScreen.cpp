#include "GameScreen.h"
#include "Button.h"

GameScreen::GameScreen() {}
GameScreen::GameScreen(string texture, sf::Vector2f position) {
	Texture.loadFromFile(texture);

	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);
}
GameScreen::GameScreen(string texture, sf::Vector2f position, string font, int charSize, sf::Vector2f textPosition, string textString) {
	Texture.loadFromFile(texture);

	Sprite.setTexture(Texture);
	Sprite.setOrigin(Sprite.getLocalBounds().width / 2, Sprite.getLocalBounds().height / 2);
	Sprite.setPosition(position);

	Font.loadFromFile(font);
	Text.setFont(Font);
	Text.setCharacterSize(charSize);
	Text.setPosition(position);
	Text.setString(textString);
}
void GameScreen::drawScreen(sf::RenderWindow& window) {

	window.draw(Sprite);

	for (int i = 0; i < Buttons.size(); i++) {
		window.draw(Buttons.at(i).getSprite());
	}

	if (Text.getString() != "") {
		window.draw(Text);
	}
}
bool GameScreen::contains(sf::Vector2f point) {
	if (Sprite.getGlobalBounds().contains(point))
		return true;
	else 
		return false;
}
void GameScreen::addButton(string texture, sf::Vector2f position) {

	Button* newButton = new Button(texture, position);

	Buttons.push_back(*newButton);
}

Button GameScreen::getButton(int button) {
	return Buttons.at(button);	
}