#include "Vector3D.h"

Vector3D::Vector3D(int x, int y, int z) 
    : Triad(x, y, z) {}
Vector3D::Vector3D(const Triad& triad) 
    : Triad(triad) {}

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(
        getX() + other.getX(),
        getY() + other.getY(),
        getZ() + other.getZ()
    );
}

int Vector3D::operator*(const Vector3D& other) const {  
    return getX() * other.getX() +
        getY() * other.getY() +
        getZ() * other.getZ();
}

//Triad createAndModifyTriad(const Triad& triad) {
//    Triad modified = triad + 10;
//    return modified * 2;
//}