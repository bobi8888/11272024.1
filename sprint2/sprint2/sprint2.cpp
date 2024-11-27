#include "utils.h"
#include "Mouse.h"

void main() {
//WINDOW
	int screenWidth = GetSystemMetrics(SM_CXSCREEN) - 100;
	int screenHeight = GetSystemMetrics(SM_CYSCREEN) - 100;
	int screenMinDim = std::min(screenWidth, screenHeight);
	const int minWindowXY = 500;
	int windowXY = 800;
	sf::ContextSettings antialiasing;
	sf::RenderWindow window(sf::VideoMode(windowXY, windowXY), "Enter Window Name Here", sf::Style::Default, antialiasing);
	sf::Vector2f centerOfScreen(windowXY / 2, windowXY / 2);

//EVENT
	sf::Event event{};

//MOUSE
	Mouse myMouse;
	sf::Vector2f mousePosition;

//GAME LOOP
	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			cout << "\nx is :" << mousePosition.x << " y is :" << mousePosition.y;
		}

		window.display();
		window.clear();

		mousePosition = myMouse.getPosition(window);

		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}
