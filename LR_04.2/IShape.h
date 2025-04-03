#pragma once
#include <string>

class IShape {
public:
    virtual double surface_area() const = 0;
    virtual ~IShape() = default;
};
