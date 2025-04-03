#include "Sphere.h"

const double Sphere::PI = std::acos(-1.0);

Sphere::Sphere(double r) : radius(r) {}

double Sphere::surface_area() const {
    return 4 * PI * radius * radius;
}
