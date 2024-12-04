#pragma once
#include "Point.h"

class Path {
	private:
		vector <Point*> PointsMap;
		sf::Vector2f Start;
		sf::Vector2f Goal;
		int WindowXY = 0;
		int TurnQty = 0;
		int XSegments = 0, YSegments = 0;

	public:
		Path() {}
		//Path(float x, float y, vector <Point*> point, sf::Vector2f goal);
		Path(int windowXY, sf::Vector2f goal);

		void randomizeStart();
		void setTurnsAndSegments();
		void generateNewPath();
		sf::Vector2f getStart();
		sf::Vector2f getGoal();
		Point* getPoint(int point);
		int getMapSize();
		vector <Point*> getMap();
		~Path() {}
};

