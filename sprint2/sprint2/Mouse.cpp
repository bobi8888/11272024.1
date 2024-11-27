#include "utils.h"
#include "Mouse.h"

sf::Vector2f Mouse::getPosition(sf::RenderWindow& window) {
	return Position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}
