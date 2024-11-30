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

Enemy* testEnemy = new Enemy("bug.png", testPath.getStart());

Wave* testWave = new Wave(*testEnemy);
int frameNum = 0;

bool canBuild = false;
vector <Tower*> towers;
vector <Bullet*> bullets;

sf::Texture bgTexture;
bgTexture.loadFromFile("intoRed.png");
sf::Sprite background;
background.setTexture(bgTexture);
background.setOrigin(background.getLocalBounds().width / 2, background.getLocalBounds().height / 2);
background.setPosition(centerOfScreen);

	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//cout << "\nx is :" << myMouse->getPosition(window).x << " y is :" << myMouse->getPosition(window).y;
			cout << waveClock->getElapsedTime().asMilliseconds() << "\n";
		}

		window.display();
		window.clear();

		window.draw(background);

		for (int i = 0; i < testWave->getSize(); i++) {
			window.draw(testWave->getEnemy(i).getSprite());
		}

		//update bullets
		//need to destroy bullets if they are not on screen
		//bullets firing in the wrong direction

		for (int i = 0; i < bullets.size(); i++) {

			if (!background.getGlobalBounds().contains(bullets.at(i)->getSprite().getPosition())) 

				bullets.at(i)->~Bullet();
			
		}
		for (int i = 0; i < bullets.size(); i++) {

			bullets.at(i)->updatePosition();

			window.draw(bullets.at(i)->getSprite());
		}

		if (buildClock->getElapsedTime().asSeconds() > 3) 

			canBuild = true;

		if (myMouse->validLeftClick(event) && canBuild) {
			towers.push_back(new Tower("switch.png", myMouse->getPosition(window)));
			buildClock->restart();
			canBuild = false;
		}

		for (int i = 0; i < towers.size(); i++) {

			window.draw(towers.at(i)->getSprite());

			if (towers.at(i)->canFire()) {
				float targetDist = 10000.f;
				float hyp = 0.f;
				sf::Vector2f enemyPosition;

				for (int j = 0; j < testWave->getSize(); j++) {

					if (testWave->getEnemy(j).getIsActive()) {
						hyp = sqrt(pow(abs(towers.at(i)->getPosition().x - testWave->getEnemy(j).getX()), 2) + pow(abs(towers.at(i)->getPosition().y - testWave->getEnemy(j).getY()), 2));
					}

					if (hyp < towers.at(i)->getRange()) {

						if (hyp < targetDist) {
							targetDist = hyp;
							enemyPosition = testWave->getEnemy(j).getSprite().getPosition();
						}
						else {
							targetDist = targetDist;
						}

						Bullet* bullet = new Bullet("key.png", towers.at(i)->getPosition(), enemyPosition);
						cout << "\n BANG! " << j;
						cout << "\n Bullets Size " << bullets.size();
						bullets.push_back(bullet);
					}
				}
			}
		}

		if (waveClock->getElapsedTime().asSeconds() > 1 && testWave->getEnemyNum() < 5) {
			waveClock->restart();
			testWave->activateNextEnemy();
		}

		if (frameNum > 60) frameNum = 0;

		if (frameClock->getElapsedTime().asMilliseconds() > 16.66) {
			frameClock->restart();
			testWave->updateActiveEnemyPositions(testPath);
		}

		while (window.pollEvent(event))	{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}
