#include "Vector3D.h"

Vector3D::Vector3D() : triad() {}
Vector3D::Vector3D(const Triad& triad) : triad(triad) {}
Vector3D::Vector3D(const Vector3D& other) : triad(other.triad) {}

Triad Vector3D::getTriad() const { return triad; }
void Vector3D::setTriad(const Triad& triad) { this->triad = triad; }

Vector3D& Vector3D::operator=(const Vector3D& other) {
    if (this != &other) {
        triad = other.triad;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Vector3D& vec) {
    in >> vec.triad;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
    out << vec.triad;
    return out;
}

Vector3D::operator std::string() const {
    return static_cast<std::string>(triad);
}

Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1.triad + v2.triad);
}

int operator*(const Vector3D& v1, const Vector3D& v2) {
    return v1.triad.getX() * v2.triad.getX() +
        v1.triad.getY() * v2.triad.getY() +
        v1.triad.getZ() * v2.triad.getZ();
}

Vector3D& operator++(Vector3D& v) {
    ++v.triad;
    return v;
}

Vector3D operator++(Vector3D& v, int) {
    Vector3D temp(v);
    ++v.triad;
    return temp;
}

Vector3D& operator--(Vector3D& v) {
    --v.triad;
    return v;
}

Vector3D operator--(Vector3D& v, int) {
    Vector3D temp(v);
    --v.triad;
    return temp;
}