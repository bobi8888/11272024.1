#include "utils.h"
#include "Wave.h"

Wave::Wave() {}

Wave::Wave(int size, float speed, string texture, sf::Vector2f startPos, float midY) {

	Size = size;
	RemainingUnits = size;

	for (int i = 0; i < size; i++) {

		Enemy* enemy = new Enemy(texture, startPos, speed, midY);

		Enemies.push_back(enemy);
	}
}
void Wave::updateActiveEnemyPositions(Path path) {

	for (int i = 0; i < Size; i++) {

		if (Enemies.at(i)->getIsActive()) {

			if (path.getPoint(Enemies.at(i)->getPathIndex())->Dir == 'x') {

				//previous x + path->dist > getX()
				//if (path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getX()) {
				if (Enemies.at(i)->getPrevX() + path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getX()) {
				
					//if above or below target, pass isAbove bool to updateX()?
					//Enemies.at(i)->updateX();
					Enemies.at(i)->updateX();

				}
				else {
					Enemies.at(i)->incrementPathIndex();
					//save the previous y position?
					Enemies.at(i)->setPrevY();
					//cout << Enemies.at(i)->getPrevY() << "\n";
				}
			
			} else {
				//i believe here is the area that needs to check if the sprite is above or below the target

				//if (isAboveGoal) {

					if (Enemies.at(i)->getPrevY() + path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getY()) {
						Enemies.at(i)->updateY();
					}

				//}
				//else {

				//}

				if (Enemies.at(i)->getPrevY() + path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getY()) {

					Enemies.at(i)->updateY();	
					
					//save previous x position?
				}
				else {
					Enemies.at(i)->incrementPathIndex();
					Enemies.at(i)->setPrevX();
					//cout << Enemies.at(i)->getPrevX() << "\n";
				}
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
void Wave::resetWave(int size, float speed, string texture, sf::Vector2f startPos, float midY) {

	if (RemainingUnits <= 0) {

		cout << "Wave destroyed";

		Enemies.clear();

		Size = size;
		RemainingUnits = size;
		EnemyNum = 0;
		WaveSpeed = speed;

		for (int i = 0; i < size; i++) {

			Enemy* enemy = new Enemy(texture, startPos, speed, midY);

			Enemies.push_back(enemy);
		}

		//for (int i = 0; i < Size; i++) {
		//	Enemies.at(i)->healHP();
		//	Enemies.at(i)->setIsActive(false);
		//	Enemies.at(i)->setPosition(position);
		//}
	}
}
