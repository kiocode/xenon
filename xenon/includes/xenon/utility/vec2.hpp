#pragma once

#include <cmath>

class Vec2 {
public:
	float x, y;

	Vec2() : x(-99), y(-99) {}
	Vec2(float x, float y) : x(x), y(y) {}

	float Distance(Vec2 v) {
		return static_cast<float>(sqrt(pow(v.x - x, 2) + pow(v.y - y, 2)));
	}
};
