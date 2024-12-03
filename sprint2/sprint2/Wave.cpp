#include "utils.h"
#include "Wave.h"

Wave::Wave() {}

Wave::Wave(int waveSize, string texture, sf::Vector2f startPos) {

	for (int i = 0; i < waveSize; i++) {

		Enemy* enemy = new Enemy(texture, startPos);

		Enemies.push_back(enemy);
	}
}

void Wave::updateActiveEnemyPositions(Path path) {

	for (int i = 0; i < 5; i++) {
		if (Enemies[i]->getIsActive()) {
			char dir = path.getPoint(Enemies[i]->getPathPositon()).Dir;

			if (dir == 'x') {

				if (path.getPoint(Enemies[i]->getPathPositon()).Dist > Enemies[i]->getX()) {
						Enemies[i]->updateX();
				} else {
						Enemies[i]->incrementPathPosition();
				}
			} else {

				if (path.getPoint(Enemies[i]->getPathPositon()).Dist > Enemies[i]->getY()) {
					Enemies[i]->updateY();
				} else {
					Enemies[i]->incrementPathPosition();
				}
			}
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
	Enemies[EnemyNum]->setIsActive(true);
	EnemyNum++;
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

		if (Enemies[i]->isDestroyed()) {
			RemainingUnits--;
		}
	}
}
void Wave::resetWave() {
	if (RemainingUnits <= 0) {
		RemainingUnits = Size;
		EnemyNum = 0;

		for (int i = 0; i < Size; i++) {
			Enemies[i]->healHP();
		}
	}
}
