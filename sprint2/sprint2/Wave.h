#pragma once
#include "utils.h"
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
		//Wave(int size, float speed, string texture, sf::Vector2f startPos, float targetY);
		Wave(int size, float speed, string texture, Path path);
		void updateActiveEnemyPositions(Path path);
		void updateEnemyActivity(Path path, sf::Sprite target);
		int getSize();
		Enemy getEnemy(int enemy);
		void activateNextEnemy();
		int getEnemyNum();
		void setEnemyHP(int enemy, float damage);
		int getRemainingUnits();
		void resetWave(int size, float speed, string texture, Path path);
		~Wave(){}
};

