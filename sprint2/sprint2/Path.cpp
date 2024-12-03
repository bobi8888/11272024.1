#include "utils.h"
#include "Path.h"

Path::Path(float x, float y, map <int, Point> pointsMap, sf::Vector2f goal) {
	Start = sf::Vector2f(x,y);
	PointsMap = pointsMap;
	Goal = goal;
}
void Path::rerollPath(int windowY, int numTurns) {
//x should remain 0
//y should be randomized, take into acount the size of the sprite so that the enemy doesn't partially appear on screen
//RNG method for #of direction changes
 int floor, range;
//needs a new start point
// random numb for y - sprite size, x will be 0
	floor = 50;
	range = windowY - floor;
	int newStartingY (floor + (rand() % range));
	int x = Goal.x;
	int y = abs(newStartingY - Goal.y);

	//int hyp = sqrt(pow(abs(Goal.x), 2) + pow(abs(newStartingY - Goal.y), 2));

//then get the a & b of the hyp for start to target triangle
// then a loop dividing the a & b based on x&yDiv, creating the points

	//int floor = 1;
	//int range = 6;
	//int randomNum = floor + (rand() % range);
	int xDiv, yDiv;

	if (numTurns % 2 == 0) {
		yDiv = (numTurns + 1) / 2;
		xDiv = yDiv + 1;
	}
	else {
		xDiv = (numTurns + 1) / 2;
		yDiv = xDiv;
	}
}
sf::Vector2f Path::getStart() {
	return Start;
}
Point Path::getPoint(int point) {
	return PointsMap[point];
}
//map<int, Point> Path::getPointsMap() {
//	return PointsMap;
//}
