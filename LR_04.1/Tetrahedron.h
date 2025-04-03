#pragma once
#include "ShapeBase.h"

class Tetrahedron : public ShapeBase {
    double a;
public:
    Tetrahedron(double edge);
    double surface_area() const override;
};