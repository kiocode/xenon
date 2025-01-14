#pragma once	

#include <cmath>

class Vec3 {
public:
	float x, y, z;

	Vec3() : x(-99), y(-99), z(-99) {}
	Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	float Distance(Vec3 v) {
		return static_cast<float>(sqrt(pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2)));
	}
};