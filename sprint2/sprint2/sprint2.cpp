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
	Mouse* myMouse = new Mouse();

//SFX
	sf::Sound* sfx = new sf::Sound;

//GAME LOOP
	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			cout << "\nx is :" << myMouse->getPosition(window).x << " y is :" << myMouse->getPosition(window).y;
		}

		window.display();
		window.clear();

		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}
