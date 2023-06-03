#include <algorithm>

#include "Triangle.hpp"

Triangle::Triangle() : a(0), b(0), c(0){}

Triangle::Triangle(double a_i, double b_i, double c_i) : a(a_i), b(b_i), c(c_i) {}

bool Triangle::isTriangle() const {
    return (a < b + c) && (b < a + c) && (c < a + b);
}

bool Triangle::isRightAngle() const {
    double maxSide = std::max({a, b, c});
    double sumOfSquares = a * a + b * b + c * c - maxSide * maxSide;
    return (maxSide * maxSide == sumOfSquares);
}

