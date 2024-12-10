#include "Wave.h"

Wave::Wave() {}

//Wave::Wave(int size, float speed, string texture, sf::Vector2f startPos, float targetY) {
Wave::Wave(int size, float speed, string texture, Path path) {

	Size = size;
	RemainingUnits = size;

	for (int i = 0; i < size; i++) {

		Enemy* enemy = new Enemy(texture, speed, path);

		Enemies.push_back(enemy);
	}
}
void Wave::updateActiveEnemyPositions(Path path) {

	for (int i = 0; i < Size; i++) {

		if (Enemies.at(i)->getIsActive()) {

			if (path.getPoint(Enemies.at(i)->getPathIndex()).Dir == 'x') {

				if (Enemies.at(i)->getPrevX() + path.getPoint(Enemies.at(i)->getPathIndex()).Dist > Enemies.at(i)->getX()) {
				
					Enemies.at(i)->updateX();

				} else {

					Enemies.at(i)->incrementPathIndex();

					Enemies.at(i)->setPrevY();
				}
			
			} else {

				if (!Enemies.at(i)->getIsAboveMid() && Enemies.at(i)->getPrevY() - path.getPoint(Enemies.at(i)->getPathIndex()).Dist < Enemies.at(i)->getY()) {

					Enemies.at(i)->updateY();	

				} else  if (Enemies.at(i)->getIsAboveMid() && Enemies.at(i)->getPrevY() + path.getPoint(Enemies.at(i)->getPathIndex()).Dist > Enemies.at(i)->getY()) {
					
					Enemies.at(i)->updateY();

				} else {

					Enemies.at(i)->incrementPathIndex();

					Enemies.at(i)->setPrevX();
				}
			}
		}
	}
}
void Wave::updateEnemyActivity(Path path, sf::Sprite target) {

	//int amount = 0;

	for (int i = 0; i < Size; i++) {

		bool destroy = false;

		if (Enemies.at(i)->getIsActive()) {

			if (Enemies.at(i)->getHP() <= 0)
				destroy = true;

			if (target.getGlobalBounds().contains(Enemies.at(i)->getSprite().getPosition()))
				destroy = true;
				
			if (destroy) {

				Enemies.at(i)->setIsActive(false);

				RemainingUnits--;

				//amount += Enemies.at(i)->getValue();
			}
		}
	}	
	//return amount;
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
void Wave::setEnemyHP(int enemy, float damage) {
	Enemies[enemy]->setHP(damage);
}
int Wave::getRemainingUnits() {
	return RemainingUnits;
}
void Wave::resetWave(int size, float speed, string texture, Path path) {

	if (RemainingUnits <= 0) {

		Enemies.clear();

		Size = size;
		RemainingUnits = size;
		EnemyNum = 0;
		WaveSpeed = speed;

		for (int i = 0; i < size; i++) {

			Enemy* enemy = new Enemy(texture, speed, path);

			Enemies.push_back(enemy);
		}

		//for (int i = 0; i < Size; i++) {
		//	Enemies.at(i)->healHP();
		//	Enemies.at(i)->setIsActive(false);
		//	Enemies.at(i)->setPosition(position);
		//}
	}
}
