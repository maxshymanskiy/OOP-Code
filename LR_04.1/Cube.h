#pragma once
#include "ShapeBase.h"

class Cube : public ShapeBase {
    double side;
public:
    Cube(double s);
    double surface_area() const override;
};