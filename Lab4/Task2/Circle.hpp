#ifndef Circle_H
#define Circle_H

#include "Shape.hpp"

class Circle : public Shape
{
private:
    const double radius, area_value, perimeter_value;

public:
    Circle(double radius);

    const double* area() const override;

    const double* perimeter() const override;
};

#endif
