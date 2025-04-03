#pragma once
#include "IShape.h"

class Cube : public IShape {
    double side;
public:
    Cube(double s);
    double surface_area() const override;
};