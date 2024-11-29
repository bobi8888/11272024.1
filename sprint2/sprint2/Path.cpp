#include "utils.h"
#include "Path.h"

Path::Path(float x, float y, map <int, Point> pointsMap) {
	Start = sf::Vector2f(x,y);
	PointsMap = pointsMap;
}
sf::Vector2f Path::getStart() {
	return Start;
}
map<int, Point> Path::getPointsMap() {
	return PointsMap;
}
Point Path::getPoint(int point) {
	return PointsMap[point];
}
