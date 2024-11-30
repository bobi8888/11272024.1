#pragma once
#include "Path.h"
#include "Enemy.h"

class Wave {
	private:
		Enemy Enemies[5];
		const int Size = 5;
		float WaveSpeed = 0.1;
		int EnemyNum = 0;
	public:
		Wave(){}
		Wave(Enemy enemy);
		void updateActiveEnemyPositions(Path path);
		int getSize();
		Enemy getEnemy(int enemy);
		void activateNextEnemy();
		int getEnemyNum();
		~Wave(){}
};

