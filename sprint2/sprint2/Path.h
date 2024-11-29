#pragma once
#include "Point.h"

class Path {
	private:
		map <int, Point> Coords;
		sf::Vector2f Start;
	public:
		Path() {}
		Path(float x, float y, map <int, Point> point);
		map <int, Point> getCoords();
		~Path() {}
};

