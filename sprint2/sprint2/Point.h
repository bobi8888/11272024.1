#pragma once

struct Point {
	char Dir;
	float Dist = 0.f;
	Point(){}
	Point(char dir, float dist);
	char getDir();
	~Point(){}
};