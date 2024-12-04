#include "utils.h"
#include "Path.h"

//Path::Path(float x, float y, vector <Point*> pointsMap, sf::Vector2f goal) {
//	//randomize start?
//	Start = sf::Vector2f(x,y);
//	//generate PointsMap with rerollPath?
//	PointsMap = pointsMap;
//	//need an updateGoal method?
//	Goal = goal;
//}
Path::Path(int windowXY, sf::Vector2f goal) {

	WindowXY = windowXY;

	int floor = 50;
	int newStartingY(floor + (rand() % (windowXY - floor)));

	Start = sf::Vector2f(0, newStartingY);

	Goal = goal;

	generateNewPath();
}
void Path::randomizeStart() {

	int floor = 50;
	int newStartingY(floor + (rand() % (WindowXY - floor)));

	Start = sf::Vector2f(0, newStartingY);
}
void Path::setTurnsAndSegments() {
	
	int floor = 1, range = 4;

	TurnQty = (floor + (rand() % range));

	if (TurnQty % 2 == 0) {

		YSegments = (TurnQty + 1) / 2;
		XSegments = YSegments + 1;

	} else {

		XSegments = (TurnQty + 1) / 2;
		YSegments = XSegments;
	}
}
void Path::generateNewPath() {

	PointsMap.clear();

	randomizeStart();

	setTurnsAndSegments();

	int mapIndex = 0;
	int floor = 1;
	int divisor = 0;
	int xRange = 10, yRange = 10; 

	for (int i = 0; i < XSegments + YSegments; i++) {

		if (mapIndex % 2 == 0) {
			
			divisor = (floor + (rand() % xRange));

			xRange = xRange - divisor + 1;

			Point* xPoint = new Point('x', Goal.x * divisor / 10);
		
			PointsMap.push_back(xPoint);

		} else {

			divisor = (floor + (rand() % yRange));

			yRange = yRange - divisor + 1;

			Point* yPoint = new Point('y', Goal.y * divisor / 10);

			PointsMap.push_back(yPoint);
		}

		mapIndex++;
	}
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
