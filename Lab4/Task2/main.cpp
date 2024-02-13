#include <iostream>
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

using namespace std;

int main()
{
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);

    Shape *shape = &rectangle;

    // Demonstrate static casting [1]
    Rectangle *rectPtr = static_cast<Rectangle*>(shape);

    // Demonstrate dynamic casting [2]
    if (typeid(*shape) == typeid(Circle)) {
        cout << "shape is a Circle" << endl;
    }
    else {
        cout << "shape is not a Circle" << endl;
    }

    // Demonstrate const casting [3]
    double* dp = const_cast<double*>(rectPtr->area());
    cout << "access via non-const pointer: " << *dp << endl;

    int intValue = 42;
    // Demonstrate reinterpret casting [4]
    double *d = reinterpret_cast<double*>(&intValue);
    cout << "int 42 represented as double is " << *d << endl;

    return 0;
}
