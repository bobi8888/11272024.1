#pragma once

struct Point {
	char Dir;
	float Dist;
	Point(){}
	Point(char dir, float dist);
	char getDir();
	~Point(){}
};