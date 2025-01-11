#pragma once	

#include <cmath>

class Vec3 {
public:
	double x, y, z;

	Vec3() : x(-99), y(-99) {}
	Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

	double Distance(Vec3 v) {
		return sqrt(pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2));
	}
};