#pragma once

class ShapeBase abstract {
public:
    virtual double surface_area() const = 0;
    virtual ~ShapeBase() {}
};