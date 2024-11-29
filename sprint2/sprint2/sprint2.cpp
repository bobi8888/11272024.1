#include "utils.h"
#include "Point.h"
#include "Mouse.h"
#include "Path.h"
#include "Enemy.h"
#include "Wave.h"
#include "Bullet.h"
#include "Tower.h"

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

//CLOCK measures elapsed time
//TIME is the time value 
//sf::Clock sets sf::time

sf::Clock* frameClock = new sf::Clock;
frameClock->restart();

sf::Clock* waveClock = new sf::Clock;
waveClock->restart();

sf::Clock* buildClock = new sf::Clock;
buildClock->restart();

//GAME LOOP

int i = 0;
//bool leftClicked = false;

Point point1('x', 200.f);
Point point2('y', 500.f);
Point point3('x', 300.f);
Point point4('y', 550.f);

map <int, Point> pointsMap;
pointsMap[0] = point1;
pointsMap[1] = point2;
pointsMap[2] = point3;
pointsMap[3] = point4;

Path testPath(100, 100, pointsMap);

//sf::Sprite testSprite;
//sf::Texture testTexture;
//testTexture.loadFromFile("bug.png");
//testSprite.setTexture(testTexture);
//testSprite.setPosition(testPath.getStart());

Enemy* testEnemy = new Enemy("bug.png", testPath.getStart());

Wave* testWave = new Wave(*testEnemy);
int frameNum = 0;

bool canBuild = false;
vector <Tower*> towers;
vector <Bullet*> bullets;

	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//cout << "\nx is :" << myMouse->getPosition(window).x << " y is :" << myMouse->getPosition(window).y;
			cout << waveClock->getElapsedTime().asMilliseconds() << "\n";
		}
		for (int i = 0; i < testWave->getSize(); i++) {
			window.draw(testWave->getEnemy(i).getSprite());
		}
		window.display();
		window.clear();

		if (buildClock->getElapsedTime().asSeconds() > 3) {
			canBuild = true;
		}

		if (myMouse->validLeftClick(event) && canBuild) {
			towers.push_back(new Tower("switch.png", myMouse->getPosition(window)));
			buildClock->restart();
			canBuild = false;
		}

		for (int i = 0; i < towers.size(); i++) {

			window.draw(towers.at(i)->getSprite());

			if (towers.at(i)->canFire()) {
				bullets.push_back(new Bullet ());
			}
		}

		if (waveClock->getElapsedTime().asSeconds() > 1 && testWave->getEnemyNum() < 5) {
			waveClock->restart();
			testWave->activateNextEnemy();
		}

		if (frameClock->getElapsedTime().asMilliseconds() > 16.66) {
			frameClock->restart();
			testWave->updateActiveEnemyPositions(testPath);
		}

		if (frameNum > 60) frameNum = 0;



		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}
