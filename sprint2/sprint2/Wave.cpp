#include "utils.h"
#include "Wave.h"

Wave::Wave() {}

Wave::Wave(int waveSize, string texture, sf::Vector2f startPos) {

	for (int i = 0; i < waveSize; i++) {

		Enemy* enemy = new Enemy(texture, startPos);

		Enemies.push_back(enemy);
	}
}
//refactor this keep it DRY
void Wave::updateActiveEnemyPositions(Path path) {


	for (int i = 0; i < 5; i++) {

		if (Enemies.at(i)->getIsActive()) {
			char dir = path.getPoint(Enemies.at(i)->getPathIndex())->Dir;

			if (dir == 'x') {

				if (path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getX()) {
						Enemies.at(i)->updateX();
				} else {

						Enemies.at(i)->incrementPathIndex();

						if (path.getMapSize() == Enemies.at(i)->getPathIndex()) {
							Enemies.at(i)->setIsActive(false);
						}
				}
			} else {

				if (path.getPoint(Enemies.at(i)->getPathIndex())->Dist > Enemies.at(i)->getY()) {
					Enemies.at(i)->updateY();
				} else {

					Enemies.at(i)->incrementPathIndex();

					if (path.getMapSize() == Enemies.at(i)->getPathIndex()) {
						Enemies.at(i)->setIsActive(false);
					}
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
	Enemies[EnemyNum++]->setIsActive(true);
	//EnemyNum++;
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

		if (Enemies.at(i)->isDestroyed()) {
			RemainingUnits--;
		}
	}
}
void Wave::resetWave() {
	if (RemainingUnits <= 0) {

		RemainingUnits = Size;
		EnemyNum = 0;
		cout << "destroy Wave";

		for (int i = 0; i < Size; i++) {
			Enemies.at(i)->healHP();
		}
	}
}
