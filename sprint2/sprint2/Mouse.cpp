#include "utils.h"
#include "Mouse.h"

sf::Vector2f Mouse::getPosition(sf::RenderWindow& window) {
	return Position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}
bool Mouse::validLeftClick(sf::Event event) {

	if (event.type == sf::Event::EventType::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
		LeftDown = true;
	}

	if (event.type == sf::Event::EventType::MouseButtonReleased && LeftDown) {
		LeftDown  = false;
		return true;
	}

	return false;
}
