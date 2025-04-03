#pragma once
#include "IShape.h"

class Tetrahedron : public IShape {
    double a;
public:
    Tetrahedron(double edge);
    double surface_area() const override;
};