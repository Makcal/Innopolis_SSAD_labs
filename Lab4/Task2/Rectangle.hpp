#ifndef Rectangle_H
#define Rectangle_H

#include "Shape.hpp"

class Rectangle : public Shape
{
private:
    const double width, height, area_value, perimeter_value;

public:
    Rectangle(double width, double height);

    const double* area() const override;

    const double* perimeter() const override;
};

#endif
