#pragma once
#include "Point.h"

class Path {
	private:
		//change this from a map to a vector?
		//allocate memory for an array?
		vector <Point*> PointsMap;
		//map <int, Point*> PointsMap;
		sf::Vector2f Start;
		sf::Vector2f Goal;

	public:
		Path() {}
		Path(float x, float y, vector <Point*> point, sf::Vector2f goal);
		void rerollPath(int windowY, int numTurns);
		sf::Vector2f getStart();
		Point* getPoint(int point);
		int getMapSize();
		vector <Point*> getMap();
		//map <int, Point> getPointsMap();
		~Path() {}
};

