#include "utils.h"
#include "Path.h"

Path::Path(float x, float y, map <int, Point> coords) {
	Start = sf::Vector2f(x,y);
	Coords = coords;
}

map<int, Point> Path::getCoords() {
	return Coords;
}
