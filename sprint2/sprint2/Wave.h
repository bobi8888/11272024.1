#pragma once
class Wave {
	private:
		int NumberOfEnemies = 5;
		float WaveSpeed = 0.1;
		Path WavePath;
		Enemy Enemies[0];
	public:
		Wave(){}
		
		~Wave(){}
};

