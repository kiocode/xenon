#pragma once

#include <cmath>

class Vec2 {
public:
	double x, y;

	Vec2() : x(-99), y(-99) {}
	Vec2(double x, double y) : x(x), y(y) {}

	double Distance(Vec2 v) {
		return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2));
	}
};
