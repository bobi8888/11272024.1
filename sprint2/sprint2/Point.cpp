#include "utils.h"
#include "Point.h"

Point::Point(char dir, float dist) {
	Dir = dir;
	Dist = dist;
}
char Point::getDir() {
	return Dir;
}