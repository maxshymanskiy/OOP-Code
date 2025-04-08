#pragma once
#include "ShapeBase.h"

class Parallelepiped : public ShapeBase {
    double y, z;  
public:
    Parallelepiped(double x, double y, double z) : ShapeBase(x), y(y), z(z) {}
    double surface_area() const override;
};