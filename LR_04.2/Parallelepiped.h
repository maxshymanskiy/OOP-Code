#pragma once
#include "IShape.h"

class Parallelepiped : public IShape {
    double x, y, z;
public:
    Parallelepiped(double x, double y, double z);
    double surface_area() const override;
};