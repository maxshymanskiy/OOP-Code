#pragma once
#include "ShapeBase.h"

class Tetrahedron : public ShapeBase {
public:
    explicit Tetrahedron(double edge) : ShapeBase(edge) {}
    double surface_area() const override;
};