#include <math.h>
#include "Circle.hpp"

Circle::Circle(double radius) 
    : radius(radius), area_value(M_PI * radius * radius), perimeter_value(2 * M_PI * radius) {}

const double* Circle::area() const {
    return &area_value;
};

const double* Circle::perimeter() const {
    return &perimeter_value;
};
