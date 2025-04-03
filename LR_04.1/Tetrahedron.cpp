#include "Tetrahedron.h"
#include <cmath>

Tetrahedron::Tetrahedron(double edge) : a(edge) {}

double Tetrahedron::surface_area() const {
    return sqrt(3) * a * a;
}