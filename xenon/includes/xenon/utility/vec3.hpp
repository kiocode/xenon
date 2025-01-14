#pragma once

#include <cmath>

class Vec3 {
public:
    float x, y, z;

    Vec3() : x(-99), y(-99), z(-99) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    float Distance(Vec3 v) const {
        return static_cast<float>(sqrt(pow(v.x - x, 2) + pow(v.y - y, 2) + pow(v.z - z, 2)));
    }

    bool operator==(const Vec3& v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vec3& v) const {
        return !(*this == v);
    }

    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator/(float scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    Vec3& operator+=(const Vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3& operator-=(const Vec3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vec3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3 Normalized() const {
        float length = Length();
        return length > 0 ? *this / length : Vec3(0, 0, 0);
    }

    float Length() const {
        return static_cast<float>(sqrt(x * x + y * y + z * z));
    }
};
