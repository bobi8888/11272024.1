#pragma once
#include "Point.h"

class Path {
	private:
		map <int, Point> PointsMap;
		sf::Vector2f Start;
		sf::Vector2f Goal;

	public:
		Path() {}
		Path(float x, float y, map <int, Point> point, sf::Vector2f goal);
		void rerollPath(int windowY, int numTurns);
		sf::Vector2f getStart();
		Point getPoint(int point);

		//map <int, Point> getPointsMap();
		~Path() {}
};

