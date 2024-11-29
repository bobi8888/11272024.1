#include "utils.h"
#include "Enemy.h"
#include "Path.h"
#include "Wave.h"

Wave::Wave(Enemy enemy) {
	for (int i = 0; i < 5; i++)
		Enemies[i] = enemy;
}
void Wave::updateActiveEnemyPositions(Path path) {

	for (int i = 0; i < 5; i++) {
		if (Enemies[i].getIsActive()) {
			char dir = path.getPoint(Enemies[i].getPathPositon()).Dir;

			if (dir == 'x') {

				if (path.getPoint(Enemies[i].getPathPositon()).Dist > Enemies[i].getX()) {
						Enemies[i].updateX();
				} else {
						Enemies[i].incrementPathPosition();
				}
			} else {

				if (path.getPoint(Enemies[i].getPathPositon()).Dist > Enemies[i].getY()) {
					Enemies[i].updateY();
				} else {
					Enemies[i].incrementPathPosition();
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
	return Enemies[enemy];
}
void Wave::activateNextEnemy() {
	Enemies[EnemyNum].setIsActive(true);
	EnemyNum++;
}
int Wave::getEnemyNum() {
	return EnemyNum;
}