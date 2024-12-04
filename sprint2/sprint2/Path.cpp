#include "utils.h"
#include "Path.h"

Path::Path(float x, float y, vector <Point*> pointsMap, sf::Vector2f goal) {
	Start = sf::Vector2f(x,y);
	PointsMap = pointsMap;
	Goal = goal;
}
void Path::rerollPath(int windowY, int numTurns) {

	int floor = 50;
	int range = windowY - floor;
	int newStartingY (floor + (rand() % range));
	int x = Goal.x;
	int y = abs(newStartingY - Goal.y);
	int xDivs, yDivs;

	if (numTurns % 2 == 0) {
		yDivs = (numTurns + 1) / 2;
		xDivs = yDivs + 1;
	}
	else {
		xDivs = (numTurns + 1) / 2;
		yDivs = xDivs;
	}

	vector <Point*> nextWavePoints;
	//float remainingX = 1.f, remainingY = 1.f;
	//float xSection, ySection;
	int mapIndex = 0;
	floor = 1;
	int xRange = 10, yRange = 10, randomInt, xDist, yDist;

	for (int i = 0; i < xDivs + yDivs; i++) {

		if (mapIndex % 2 == 0) {

			randomInt = (1 + (rand() % xRange));
			//xSection = (float) randomInt / 10;

			//remainingX = remainingX - xSection;
			xRange = xRange - randomInt + 1;

			//int xDist = x * xSection;
			xDist = x * randomInt / 10;

			Point* xPoint = new Point('x', xDist);
		
			nextWavePoints[mapIndex] = xPoint;

			mapIndex++;
		}
		else {
			randomInt = (1 + (rand() % yRange));
			yRange = yRange - randomInt + 1;
			yDist = y * randomInt / 10;
			Point* yPoint = new Point('y', yDist);
			nextWavePoints[mapIndex] = yPoint;
			mapIndex++;
		}
	}

	PointsMap = nextWavePoints;
}
sf::Vector2f Path::getStart() {
	return Start;
}
Point* Path::getPoint(int point) {
	return PointsMap.at(point);
}
int Path::getMapSize() {
	return PointsMap.size();
}
vector <Point*> Path::getMap() {
	return PointsMap;
}
//map<int, Point> Path::getPointsMap() {
//	return PointsMap;
//}
