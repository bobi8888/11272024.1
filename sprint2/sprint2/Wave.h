#pragma once
#include "Path.h"
#include "Enemy.h"

class Wave {
	private:
		vector <Enemy*> Enemies;
		int Size = 0;
		int RemainingUnits = 0;
		float WaveSpeed = 1; // smaller is faster
		int EnemyNum = 0; //what is this? used for?

	public:
		Wave();
		Wave(int size, float speed, string texture, sf::Vector2f startPos);
		void updateActiveEnemyPositions(Path path);
		void updateEnemyActivity(Path path);
		int getSize();
		Enemy getEnemy(int enemy);
		void activateNextEnemy();
		int getEnemyNum();
		void checkEnemyActivity(int enemy);
		void setEnemyHP(int enemy, float damage);
		int getRemainingUnits();
		void updateRemainingUnits();
		void resetWave(int size, float speed, string texture, sf::Vector2f startPos);
		~Wave(){}
};

