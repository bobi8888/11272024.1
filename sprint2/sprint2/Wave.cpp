#include "utils.h"
#include "Enemy.h"
#include "Path.h"
#include "Wave.h"

Wave::Wave(Enemy enemy) {
	for (int i = 0; i < 5; i++)
		Enemies[i] = enemy;
}

void Wave::updateEnemyPositions(Path path) {

	for (int i = 0; i < 5; i++) {

		char dir = path.getPoint(Enemies->getPathPositon()).Dir;

		if (dir == 'x') {
			Enemies[i].updateX();
		}
		else {
			Enemies[i].updateY();
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
