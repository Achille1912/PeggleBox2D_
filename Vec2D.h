#pragma once

#include <string>
#include <iostream>
#include <cmath>

namespace PGG
{
template <class T>
struct Vec2D
{
    // attributes
    T x = 0;
    T y = 0;

    // constructors
    Vec2D() : x(0), y(0) {}
    Vec2D(T _x, T _y) : x(_x), y(_y) {}
    Vec2D(const Vec2D& v) : x(v.x), y(v.y) {}

    // methods
    T mag() const { return T(std::sqrt(x * x + y * y)); }
    T mag2() const { return x * x + y * y; }
    Vec2D  norm() const { T r = 1 / mag(); return Vec2D(x * r, y * r); }
    Vec2D  perp() const { return Vec2D(-y, x); }
    Vec2D  floor() const { return Vec2D(std::floor(x), std::floor(y)); }
    Vec2D  ceil() const { return Vec2D(std::ceil(x), std::ceil(y)); }
    Vec2D  max(const Vec2D& v) const { return Vec2D(std::max(x, v.x), std::max(y, v.y)); }
    Vec2D  min(const Vec2D& v) const { return Vec2D(std::min(x, v.x), std::min(y, v.y)); }
    Vec2D  cart() { return { std::cos(y) * x, std::sin(y) * x }; }
    Vec2D  polar() { return { mag(), std::atan2(y, x) }; }
    T dot(const Vec2D& rhs) const { return this->x * rhs.x + this->y * rhs.y; }
    T cross(const Vec2D& rhs) const { return this->x * rhs.y - this->y * rhs.x; }

    // string
    const std::string str() const { return std::string("(") + std::to_string(this->x) + "," + std::to_string(this->y) + ")"; }
    friend std::ostream& operator << (std::ostream& os, const Vec2D& rhs) { os << rhs.str(); return os; }

    // operator overloads
    Vec2D& operator=(const Vec2D& v) = default;
    Vec2D  operator +  (const Vec2D& rhs) const { return Vec2D(this->x + rhs.x, this->y + rhs.y); }
    Vec2D  operator -  (const Vec2D& rhs) const { return Vec2D(this->x - rhs.x, this->y - rhs.y); }
    Vec2D  operator *  (const T& rhs)     const { return Vec2D(this->x * rhs, this->y * rhs); }
    Vec2D  operator *  (const Vec2D& rhs) const { return Vec2D(this->x * rhs.x, this->y * rhs.y); }
    Vec2D  operator /  (const T& rhs)     const { return Vec2D(this->x / rhs, this->y / rhs); }
    Vec2D  operator /  (const Vec2D& rhs) const { return Vec2D(this->x / rhs.x, this->y / rhs.y); }
    Vec2D& operator += (const Vec2D& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
    Vec2D& operator -= (const Vec2D& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
    Vec2D& operator *= (const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
    Vec2D& operator /= (const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }
    Vec2D& operator *= (const Vec2D& rhs) { this->x *= rhs.x; this->y *= rhs.y; return *this; }
    Vec2D& operator /= (const Vec2D& rhs) { this->x /= rhs.x; this->y /= rhs.y; return *this; }
    Vec2D  operator +  () const { return { +x, +y }; }
    Vec2D  operator -  () const { return { -x, -y }; }
    bool operator == (const Vec2D& rhs) const { return (this->x == rhs.x && this->y == rhs.y); }
    bool operator != (const Vec2D& rhs) const { return (this->x != rhs.x || this->y != rhs.y); }

    // casting operators
    operator Vec2D<int32_t>() const { return { static_cast<int32_t>(this->x), static_cast<int32_t>(this->y) }; }
    operator Vec2D<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; }
    operator Vec2D<double>() const { return { static_cast<double>(this->x), static_cast<double>(this->y) }; }
};

template<class T> inline Vec2D<T> operator * (const float& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs * (float)rhs.x), (T)(lhs * (float)rhs.y));
}
template<class T> inline Vec2D<T> operator * (const double& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs * (double)rhs.x), (T)(lhs * (double)rhs.y));
}
template<class T> inline Vec2D<T> operator * (const int& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs * (int)rhs.x), (T)(lhs * (int)rhs.y));
}
template<class T> inline Vec2D<T> operator / (const float& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs / (float)rhs.x), (T)(lhs / (float)rhs.y));
}
template<class T> inline Vec2D<T> operator / (const double& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs / (double)rhs.x), (T)(lhs / (double)rhs.y));
}
template<class T> inline Vec2D<T> operator / (const int& lhs, const Vec2D<T>& rhs)
{
    return Vec2D<T>((T)(lhs / (int)rhs.x), (T)(lhs / (int)rhs.y));
}

typedef Vec2D<float> Vec2Df;
}
