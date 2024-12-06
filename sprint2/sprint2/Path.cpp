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

	int floor = 60;
	int newStartingY(floor + (rand() % (WindowXY - floor)));

	Start = sf::Vector2f(0, newStartingY);
	cout << "new starting Y: " << newStartingY << "\n";
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
	int floor = 1;
	int divisor = 0;
	int xRange = 9, yRange = 9; 

	//int j = 0;
	//while (j < 500) {
	//	j++;
	//	divisor = floor + (rand() % xRange);
	//	cout << divisor << " : ";
	//	if (divisor == 9) cout << "!!!";
	//}

	for (int i = 0; i < XSegments + YSegments; i++) {

		if (mapIndex++ % 2 == 0) {
			
			divisor =  floor + (rand() % xRange);

			xRange = xRange - divisor + 1;

			Point* xPoint = new Point('x', Goal.x * (float) divisor * 0.1);
		
			PointsMap.push_back(xPoint);

		} else {

			divisor = floor + (rand() % yRange);

			yRange = yRange - divisor + 1;

			float point;

			//Point* yPoint = new Point('y', Start.y - (abs(Goal.y - Start.y) * divisor * 0.1));

			if (Start.y > Goal.y) 
				point = Start.y - (abs(Goal.y - Start.y) * divisor * 0.1);
			else 
				point = Start.y + (abs(Goal.y - Start.y) * divisor * 0.1);

			Point* yPoint = new Point('y', point);

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

