#pragma once

#include <cmath>

class Vec2 {
public:
    float x, y;

    Vec2() : x(-99), y(-99) {}
    Vec2(float x, float y) : x(x), y(y) {}

    float Distance(Vec2 v) const {
        return static_cast<float>(sqrt(pow(v.x - x, 2) + pow(v.y - y, 2)));
    }

    bool operator==(const Vec2& v) const {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vec2& v) const {
        return !(*this == v);
    }

    Vec2 operator+(const Vec2& v) const {
        return Vec2(x + v.x, y + v.y);
    }

    Vec2 operator-(const Vec2& v) const {
        return Vec2(x - v.x, y - v.y);
    }

    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    Vec2& operator+=(const Vec2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vec2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vec2 Normalized() const {
        float length = static_cast<float>(sqrt(x * x + y * y));
        return length > 0 ? *this / length : Vec2(0, 0);
    }

    float Length() const {
        return static_cast<float>(sqrt(x * x + y * y));
    }
};
