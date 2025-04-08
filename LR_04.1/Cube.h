#pragma once
#include "ShapeBase.h"

class Cube : public ShapeBase {
public:
    explicit Cube(double s) : ShapeBase(s) {}
    double surface_area() const override;
};