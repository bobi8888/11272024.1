#pragma once
#include "Path.h"
#include "Enemy.h"

class Wave {
	private:
		vector <Enemy*> Enemies;
		int Size = 5;
		int RemainingUnits = Size;
		float WaveSpeed = 1; // smaller is faster
		int EnemyNum = 0;

	public:
		Wave();
		Wave(int waveSize, string texture, sf::Vector2f startPos);
		void updateActiveEnemyPositions(Path path);
		int getSize();
		Enemy getEnemy(int enemy);
		void activateNextEnemy();
		int getEnemyNum();
		void checkEnemyActivity(int enemy);
		void setEnemyHP(int enemy, float damage);
		int getRemainingUnits();
		void updateRemainingUnits();
		void resetWave();
		~Wave(){}
};

