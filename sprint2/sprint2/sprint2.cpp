#include "utils.h"
#include "Point.h"
#include "Mouse.h"
#include "Path.h"
#include "Enemy.h"
#include "Wave.h"
#include "Bullet.h"
#include "Tower.h"
#include "Wallet.h"
#include "Base.h"
#include "GameScreen.h"

//class MyClass { 
//	public: 
//		int intValue; 
//		double doubleValue; 
//		char* charArray; 
//		
//		MyClass(int intVal, double doubleVal, size_t arraySize) : intValue(intVal), doubleValue(doubleVal) { charArray = new char[arraySize]; } 
//		~MyClass() { delete[] charArray; } 
//
//		void printMemoryUsage() const { 
//			size_t charArr = sizeof(*charArray);
//			size_t charSing = sizeof(char);
//			cout << "charArr: " << charArr << " charSing: " << charSing;
//			size_t dynamicMemory = sizeof(*charArray) * (sizeof(charArray) / sizeof(char)); 
//			cout << "\n Memory used by MyClass " << sizeof(*this);
//			cout << "\n Memory used by dynamicMemory " << dynamicMemory;
//		}
//};

void main() {

//size_t arraySize = 50; 
		//MyClass obj(42, 3.14, arraySize); 
		//obj.printMemoryUsage();

//SEED RNG
	srand(time(0));

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

Base base("chessPiece.png", sf::Vector2f(windowXY - 50, centerOfScreen.y));

Path randomPath(windowXY, base.getSprite().getPosition());

Wave* testWave = new Wave(1, 22.f, "bug.png", randomPath);

Wave* Waves[10];
Waves[0] = testWave;

bool canBuild = false;
vector <Tower*> towers;
vector <Bullet*> bullets;

//create background class so that sprites can deposit death spots on the background
GameScreen background("intoRed.png", centerOfScreen);
GameScreen gameover("centerNoChessPiece.png", centerOfScreen, "RobotoCondensed-Regular.ttf", 50, centerOfScreen, "Game Over");

Wallet Wallet("RobotoCondensed-Regular.ttf", 40, sf::Vector2f(centerOfScreen.x, 25));
bool pause = false;

//TODO:
 		//Frame rate is affecting speed of sprites: unitize sprite movement
		//create a struct of new wave params? increment an array of them?
		//testWave->resetWave(Waves[testWave->getWaveNum()]);
		//testWave->incrementWaves();

	while (window.isOpen())	{

		//DEV TOOLS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			//cout << "\nx is :" << myMouse->getPosition(window).x << " y is :" << myMouse->getPosition(window).y;
			//cout << waveClock->getElapsedTime().asMilliseconds() << "\n";
			//cout << "\n Enemies sprite x: " << testWave->getEnemy(0).getSprite().getPosition().x;
			//cout << "\n Enemies sprite y: " << testWave->getEnemy(0).getSprite().getPosition().y;
			//cout << "\n Enemies x: " << testWave->getEnemy(0).getX();
			//cout << "\n Enemies y: " << testWave->getEnemy(0).getY();
		}

		//FRAMES

		//Frame rate is affecting speed of sprites


			if (frameClock->getElapsedTime().asMilliseconds() > 16.66) {

				window.display();
				window.clear();

				if (!pause) {

					window.draw(Wallet.getText());

					frameClock->restart();

					Wallet.updateAmountString();

					testWave->updateEnemyActivity(randomPath, base.getSprite());
					testWave->updateActiveEnemyPositions(randomPath);
					testWave->cullEnemies();	

					background.drawScreen(window);

					base.drawBase(window);

					//WAVE CLOCK
					if (waveClock->getElapsedTime().asSeconds() > 1 && testWave->getEnemyNum() < testWave->getSize()) {

						waveClock->restart();

						testWave->activateNextEnemy();
					}

					//WAVE DESTROYED
					if (testWave->getRemainingUnits() == 0) {

						randomPath.generateNewPath();
			
						testWave->resetWave(3, 5.f, "bug.png", randomPath);
					}

					//LOOP THROUGH WAVE
					for (int i = 0; i < testWave->getSize(); i++) {

						if (testWave->getEnemy(i).getIsActive() && base.getSprite().getGlobalBounds().contains(testWave->getEnemy(i).getSprite().getPosition())) {
							base.damageHP(testWave->getEnemy(i).getDamage());
							testWave->setEnemyDamage(i, 0);
							//testWave->setEnemyActivity(i, false);
							testWave->killEnemy(i);
						}

						if (testWave->getEnemy(i).getIsActive())
							window.draw(testWave->getEnemy(i).getSprite());			
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

									if (testWave->getEnemy(j).isDestroyed())
										Wallet.updateAmount(testWave->getEnemy(j).getValue());

									break;
								}
							}
						}
			
						//if (!background.getGlobalBounds().contains(bullets.at(i)->getSprite().getPosition()) || !bullets.at(i)->getIsActive())
						if (!background.contains(bullets.at(i)->getSprite().getPosition()) || !bullets.at(i)->getIsActive())
							bullets.erase(bullets.begin() + i);
					}


					//BUILDING TOWERS
					if (buildClock->getElapsedTime().asSeconds() > 1) 
						canBuild = true;

					if (myMouse->validLeftClick(event) && canBuild && Wallet.getAmount() >= Wallet.getTowerCost()) {

						Wallet.deductTowerCost();

						towers.push_back(new Tower("switch.png", myMouse->getPosition(window)));

						buildClock->restart();

						canBuild = false;
					}

					//LOOP THROUGH TOWERS
					for (int i = 0; i < towers.size(); i++) {

						window.draw(towers.at(i)->getSprite());

						towers.at(i)->updateCanFire();

						if (towers.at(i)->getCanFire()) {

							//what is targetDist doing?
							float targetDist = 10000.f;
							float hyp = 0.f;
							sf::Vector2f enemyPosition;

							for (int j = 0; j < testWave->getSize(); j++) {

								if (testWave->getEnemy(j).getIsActive()) 
									hyp = sqrt(pow(abs(towers.at(i)->getPosition().x - testWave->getEnemy(j).getX()), 2) + pow(abs(towers.at(i)->getPosition().y - testWave->getEnemy(j).getY()), 2));
					
								else 
									hyp = 10000.f;					

								if (hyp < towers.at(i)->getRange() && towers.at(i)->getCanFire()) {

									if (hyp < targetDist) {

										targetDist = hyp;

										enemyPosition = testWave->getEnemy(j).getSprite().getPosition();

									} else 
										targetDist = targetDist;						

									Bullet* bullet = new Bullet("key.png", towers.at(i)->getPosition(), enemyPosition);

									bullets.push_back(bullet);

									towers.at(i)->setCanFire(false);
								}
							}
						}
					}

					if (base.getHP() <= 0) 
						pause = true;
			
				} else 
					gameover.drawScreen(window);			
			} 
				
		while (window.pollEvent(event))	{

			if (event.type == sf::Event::Closed) 
				window.close();
		}
	}
}
