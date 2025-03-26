#include "Vector3D.h"

Vector3D::Vector3D(int x, int y, int z) : Triad(x, y, z) {}
Vector3D::Vector3D(const Triad& triad) : Triad(triad) {}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) {
    return Vector3D(lhs.getX() + rhs.getX(),
        lhs.getY() + rhs.getY(),
        lhs.getZ() + rhs.getZ());
}

int operator*(const Vector3D& lhs, const Vector3D& rhs) {
    return lhs.getX() * rhs.getX() +
        lhs.getY() * rhs.getY() +
        lhs.getZ() * rhs.getZ();
}

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        Triad::operator=(other);
    }
    return *this;
}

std::string Vector3D::to_string() const {
    std::stringstream ss;
    ss << "<" << getX() << ", " << getY() << ", " << getZ() << ">";
    return ss.str();
}

Vector3D::operator std::string() const {
    return to_string();
}

std::istream& operator>>(std::istream& in, Vector3D& vec) {
    int x, y, z;
    in >> x >> y >> z;
    vec.setX(x);
    vec.setY(y);
    vec.setZ(z);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
    out << static_cast<std::string>(vec);
    return out;
}