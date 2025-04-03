#include "Cube.h"

Cube::Cube(double s) : side(s) {}

double Cube::surface_area() const {
    return 6 * side * side;
}