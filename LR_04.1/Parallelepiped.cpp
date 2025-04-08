#include "Parallelepiped.h"

double Parallelepiped::surface_area() const {
    return 2 * (size * y + size * z + y * z);
}