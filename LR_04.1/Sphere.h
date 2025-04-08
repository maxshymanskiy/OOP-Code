#pragma once
#include "ShapeBase.h"
#include <cmath>

class Sphere : public ShapeBase {
    static const double PI;
public:
    explicit Sphere(double r) : ShapeBase(r) {}
    double surface_area() const override;
};