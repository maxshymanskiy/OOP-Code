#pragma once

class ShapeBase {
protected:
    double size;  
public:
    explicit ShapeBase(double s) : size(s) {}
    virtual double surface_area() const = 0;
};