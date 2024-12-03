#include "utils.h"
#include "Path.h"

Path::Path(float x, float y, map <int, Point> pointsMap) {
	Start = sf::Vector2f(x,y);
	PointsMap = pointsMap;
}
void Path::rerollPath() {
//x should remain 0
//y should be randomized, take into acount the size of the sprite so that the enemy doesn't partially appear on screen
//RNG method for #of direction changes

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
