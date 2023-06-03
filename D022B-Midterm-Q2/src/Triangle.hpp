#pragma once

#include <stdio.h>

class Triangle {
private:
    double a, b, c;


public:
    Triangle();                                     // Default constructor
    Triangle(double a_i, double b_i, double c_i);   // Constructor
    bool isTriangle() const;                        // Returns true if a, b, c form a triangle
    bool isRightAngle() const;                      // Returns true if a, b, c form a right angle triangle
};
