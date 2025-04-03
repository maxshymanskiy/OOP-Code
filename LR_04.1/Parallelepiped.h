#pragma once
#include "ShapeBase.h"

class Parallelepiped : public ShapeBase {
    double x, y, z;
public:
    Parallelepiped(double x, double y, double z);
    double surface_area() const override;
};