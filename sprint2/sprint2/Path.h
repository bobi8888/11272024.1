#pragma once
#include "Point.h"

class Path {
	private:
		//vector <Point*> Points;
		vector <Point> Points;
		sf::Vector2f Start;
		sf::Vector2f Goal;
		int WindowXY = 0;
		int TurnQty = 0;
		int XSegments = 1, YSegments = 1;
		int A = 1, B = 1;

	public:
		Path() {}
		Path(int windowXY, sf::Vector2f goal);

		void randomizeStart();
		void setTurnsAndSegments();
		void generateNewPath();
		sf::Vector2f getStart();
		sf::Vector2f getGoal();
		Point getPoint(int point);
		int getMapSize();
		~Path() {}
};
