#pragma once
class Wave {
	private:
		float WaveSpeed = 0.1;
		//Path WavePath;
		const int Size = 5;
		Enemy Enemies[5];

	public:
		Wave(){}
		Wave(Enemy enemy);
		void updateEnemyPositions(Path path);
		int getSize();
		Enemy getEnemy(int enemy);
		~Wave(){}
};

