#include "Vector3D.h"

Vector3D::Vector3D() : Triad() {}
Vector3D::Vector3D(const Triad& triad) : Triad(triad) {}
Vector3D::Vector3D(const Vector3D& other) : Triad(other) {}

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        Triad::operator=(other);
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Vector3D& vec) {
    in >> static_cast<Triad&>(vec);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
    out << static_cast<const Triad&>(vec);
    return out;
}

Vector3D::operator std::string() const {
    return static_cast<std::string>(*this);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(static_cast<Triad>(v1) + static_cast<Triad>(v2));
}

int operator*(const Vector3D& v1, const Vector3D& v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

Vector3D& operator++(Vector3D& v) {
    ++static_cast<Triad&>(v);
    return v;
}

Vector3D operator++(Vector3D& v, int) {
    Vector3D temp(v);
    ++static_cast<Triad&>(v);
    return temp;
}

Vector3D& operator--(Vector3D& v) {
    --static_cast<Triad&>(v);
    return v;
}

Vector3D operator--(Vector3D& v, int) {
    Vector3D temp(v);
    --static_cast<Triad&>(v);
    return temp;
}