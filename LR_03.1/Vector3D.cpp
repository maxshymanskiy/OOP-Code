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

Vector3D::operator std::string() const {
    std::stringstream ss;
    ss << "<" << getX() << ", " << getY() << ", " << getZ() << ">";
    return ss.str();
}

std::istream& operator>>(std::istream& in, Vector3D& vec) {
    in >> vec.x >> vec.y >> vec.z;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
    out << static_cast<std::string>(vec);
    return out;
}


//Triad createAndModifyTriad(const Triad& triad) {
//    Triad modified = triad + 10;
//    return modified * 2;
//}