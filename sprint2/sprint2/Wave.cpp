#include "utils.h"
#include "Wave.h"

Wave::Wave() {}

Wave::Wave(int size, float speed, string texture, sf::Vector2f startPos) {

	Size = size;
	RemainingUnits = size;

	for (int i = 0; i < size; i++) {

		Enemy* enemy = new Enemy(texture, startPos, speed);

		Enemies.push_back(enemy);
	}
}
void Wave::updateActiveEnemyPositions(Path path) {

	for (int i = 0; i < Size; i++) {

		if (Enemies.at(i)->getIsActive()) {

			if (path.getPoint(Enemies.at(i)->getPathIndex())->Dir == 'x') {

				if (path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getX()) 
					Enemies.at(i)->updateX();
				else 
					Enemies.at(i)->incrementPathIndex();
			
			} else {

				if (path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getY()) 
					Enemies.at(i)->updateY();				
				else
					Enemies.at(i)->incrementPathIndex();
			}
		}
	}
}
void Wave::updateEnemyActivity(Path path) {

	for (int i = 0; i < Size; i++) {

		if (path.getMapSize() == Enemies.at(i)->getPathIndex() && Enemies.at(i)->getIsActive()) {
		
			Enemies.at(i)->setIsActive(false);
		
			RemainingUnits--;
		}
	}	
}
int Wave::getSize()
{
	return Size;
}
Enemy Wave::getEnemy(int enemy) {
	return *Enemies[enemy];
}
void Wave::activateNextEnemy() {
	Enemies[EnemyNum++]->setIsActive(true);
}
int Wave::getEnemyNum() {
	return EnemyNum;
}
void Wave::checkEnemyActivity(int enemy) {
	Enemies[enemy]->hpCheckForActivity();
}
void Wave::setEnemyHP(int enemy, float damage) {
	Enemies[enemy]->setHP(damage);
}
int Wave::getRemainingUnits() {
	return RemainingUnits;
}
void Wave::updateRemainingUnits() {

	for (int i = 0; i < Size; i++) {

		if (Enemies.at(i)->isDestroyed())
			RemainingUnits--;		
	}
}
void Wave::resetWave(int size, float speed, string texture, sf::Vector2f startPos) {

	if (RemainingUnits <= 0) {

		cout << "Wave destroyed";

		Enemies.clear();

		Size = size;
		RemainingUnits = size;
		EnemyNum = 0;
		WaveSpeed = speed;

		for (int i = 0; i < size; i++) {

			Enemy* enemy = new Enemy(texture, startPos, speed);

			Enemies.push_back(enemy);
		}

		//for (int i = 0; i < Size; i++) {
		//	Enemies.at(i)->healHP();
		//	Enemies.at(i)->setIsActive(false);
		//	Enemies.at(i)->setPosition(position);
		//}
	}
}
