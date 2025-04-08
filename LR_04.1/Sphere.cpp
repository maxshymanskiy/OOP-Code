#include "Sphere.h"

const double Sphere::PI = std::acos(-1.0);

double Sphere::surface_area() const {
    return 4 * PI * size * size;
}