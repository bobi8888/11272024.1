#pragma once
#include "Point.h"

class Path {
	private:
		map <int, Point> PointsMap;
		sf::Vector2f Start;
	public:
		Path() {}
		Path(float x, float y, map <int, Point> point);
		sf::Vector2f getStart();
		map <int, Point> getPointsMap();
		Point getPoint(int point);
		~Path() {}
};

