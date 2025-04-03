#pragma once

class ShapeBase {
public:
    virtual double surface_area() const = 0;
    virtual ~ShapeBase() {}
};