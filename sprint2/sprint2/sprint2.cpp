#include "utils.h"

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

	while (window.isOpen())	{
		while (window.pollEvent(event))
		{
			//what else goes on in here?
			if (event.type == sf::Event::Closed) {
				window.close();
			//	Log.open(logFileName, ios::app);//appends the log
			//	Log << timestamp.getTimeString() << " : Window closed \n";
			//	Log.close();
			}
		}
	}
}
