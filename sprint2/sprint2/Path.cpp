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

	B = goal.x;

	generateNewPath();
}
void Path::randomizeStart() {

	int floor = 60;

	int newStartingY(floor + (rand() % (WindowXY - floor)));

	Start = sf::Vector2f(0, newStartingY);

	A = abs(Goal.y - Start.y);

	B = Goal.x;
}
void Path::setTurnsAndSegments() {
	
	int floor = 2, range = 4;

	TurnQty = (floor + (rand() % range));

	if (TurnQty % 2 != 0) TurnQty++;

	YSegments = (TurnQty + 1) / 2;

	XSegments = YSegments + 1;
}
void Path::generateNewPath() {

	PointsMap.clear();

	randomizeStart();

	setTurnsAndSegments();

	int mapIndex = 0;

	B = B / XSegments;

	A = A / YSegments;

	for (int i = 0; i < XSegments + YSegments; i++) {

		if (mapIndex++ % 2 == 0) {

			Point* xPoint = new Point('x', B);
		
			PointsMap.push_back(xPoint);

		} else {

			Point* yPoint = new Point('y', A);

			PointsMap.push_back(yPoint);
		}
	}
}
sf::Vector2f Path::getStart() {
	return Start;
}
sf::Vector2f Path::getGoal() {
	return Goal;
}
Point* Path::getPoint(int point) {
	return PointsMap.at(point);
}
int Path::getMapSize() {
	return PointsMap.size();
}

