#pragma once
#include "ShapeBase.h"
#include <cmath>

class Sphere : public ShapeBase {
    double radius;
    static const double PI; 

public:
    Sphere(double r);  
    double surface_area() const override;
};
