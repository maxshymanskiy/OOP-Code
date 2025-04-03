#pragma once
#include "IShape.h"
#include <cmath>

class Sphere : public IShape {
    double radius;
    static const double PI;

public:
    Sphere(double r);
    double surface_area() const override;
};

