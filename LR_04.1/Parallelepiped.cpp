#include "Parallelepiped.h"

Parallelepiped::Parallelepiped(double x, double y, double z)
    : x(x), y(y), z(z) {
}

double Parallelepiped::surface_area() const {
    return 2 * (x * y + x * z + y * z);
}