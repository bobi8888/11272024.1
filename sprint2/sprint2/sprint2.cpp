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

int frameNum = 0;


sf::Clock* waveClock = new sf::Clock;
waveClock->restart();

sf::Clock* buildClock = new sf::Clock;
buildClock->restart();

//GAME LOOP

//int i = 0;

sf::Texture chessTexture;
chessTexture.loadFromFile("chessPiece.png");
sf::Sprite chess;
chess.setTexture(chessTexture);
chess.setOrigin(chess.getLocalBounds().width / 2, chess.getLocalBounds().height / 2);
chess.setPosition(sf::Vector2f(windowXY - 25, windowXY / 2));

Point point1('x', 200.f);
Point point2('y', 500.f);
Point point3('x', 300.f);
Point point4('y', 550.f);

map <int, Point> pointsMap;
pointsMap[0] = point1;
pointsMap[1] = point2;
pointsMap[2] = point3;
pointsMap[3] = point4;

Path testPath(100, 100, pointsMap, chess.getPosition());

//Enemy* testEnemy = new Enemy("bug.png", testPath.getStart());

Wave* testWave = new Wave(5, "bug.png", testPath.getStart());

bool canBuild = false;
vector <Tower*> towers;
vector <Bullet*> bullets;

sf::Texture bgTexture;
bgTexture.loadFromFile("intoRed.png");
sf::Sprite background;
background.setTexture(bgTexture);
background.setOrigin(background.getLocalBounds().width / 2, background.getLocalBounds().height / 2);
background.setPosition(centerOfScreen);



//TODO:
//update to next wave when wave is dead
//generate next path the next wave will take
//implement currency for destroying enemeies to buy towers

	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//cout << "\nx is :" << myMouse->getPosition(window).x << " y is :" << myMouse->getPosition(window).y;
			//cout << waveClock->getElapsedTime().asMilliseconds() << "\n";
			testPath.rerollPath(windowXY, 6);
		}

		window.display();
		window.clear();

		window.draw(background);
		window.draw(chess);

		testWave->updateRemainingUnits();

		//WAVE CLOCK
		if (waveClock->getElapsedTime().asSeconds() > 1 && testWave->getEnemyNum() < 5) {

			waveClock->restart();

			testWave->activateNextEnemy();
		}

		if (testWave->getRemainingUnits() == 0) {
			testWave->resetWave();
		}

		//LOOP THROUGH WAVE
		for (int i = 0; i < testWave->getSize(); i++) {

			testWave->checkEnemyActivity(i);

			if (testWave->getEnemy(i).getIsActive()) {
				window.draw(testWave->getEnemy(i).getSprite());
			}
		}

		//LOOP THROUGH BULLETS
		for (int i = 0; i < bullets.size(); i++) {

			bullets.at(i)->updatePosition();

			window.draw(bullets.at(i)->getSprite());

			for (int j = 0; j < testWave->getSize(); j++) {

				if (testWave->getEnemy(j).getIsActive()) {

					if (bullets.at(i)->hitEnemy(testWave->getEnemy(j).getSprite().getGlobalBounds())) {
						bullets.at(i)->setIsActive(false);
						testWave->setEnemyHP(j, bullets.at(i)->getDamage());
						break;
					}
				}
			}
			
			if (!background.getGlobalBounds().contains(bullets.at(i)->getSprite().getPosition()) || !bullets.at(i)->getIsActive())
				bullets.erase(bullets.begin() + i);
		}

		if (buildClock->getElapsedTime().asSeconds() > 1) 

			canBuild = true;

		if (myMouse->validLeftClick(event) && canBuild) {
			towers.push_back(new Tower("switch.png", myMouse->getPosition(window)));
			buildClock->restart();
			canBuild = false;
		}

		//LOOP THROUGH TOWERS
		for (int i = 0; i < towers.size(); i++) {

			window.draw(towers.at(i)->getSprite());
			towers.at(i)->updateCanFire();

			if (towers.at(i)->getCanFire()) {
				float targetDist = 10000.f;
				float hyp = 0.f;
				sf::Vector2f enemyPosition;

				for (int j = 0; j < testWave->getSize(); j++) {

					testWave->updateRemainingUnits();

					if (testWave->getEnemy(j).getIsActive()) {
						hyp = sqrt(pow(abs(towers.at(i)->getPosition().x - testWave->getEnemy(j).getX()), 2) + pow(abs(towers.at(i)->getPosition().y - testWave->getEnemy(j).getY()), 2));
					}
					else {
						hyp = 10000.f;
					}

					if (hyp < towers.at(i)->getRange() && towers.at(i)->getCanFire()) {

						if (hyp < targetDist) {
							targetDist = hyp;
							enemyPosition = testWave->getEnemy(j).getSprite().getPosition();
						}
						else {
							targetDist = targetDist;
						}

						Bullet* bullet = new Bullet("key.png", towers.at(i)->getPosition(), enemyPosition);
						bullets.push_back(bullet);
						towers.at(i)->setCanFire(false);
					}
				}
			}
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
