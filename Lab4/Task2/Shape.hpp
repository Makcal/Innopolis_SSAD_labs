#ifndef Shape_H
#define Shape_H

class Shape
{
public:
    virtual const double* area() const = 0;

    virtual const double* perimeter() const = 0;
};

#endif
