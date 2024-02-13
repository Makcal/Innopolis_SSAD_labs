#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
    : width(width), height(height), area_value(width * height), perimeter_value(width + height) { }

const double* Rectangle::area() const {
    return &area_value;
};

const double* Rectangle::perimeter() const {
    return &perimeter_value;
};
