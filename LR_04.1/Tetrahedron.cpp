#include "Tetrahedron.h"
#include <cmath>

double Tetrahedron::surface_area() const {
    return sqrt(3) * size * size;
}