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

Vector3D Vector3D::operator+(const Vector3D& other) const {
    return Vector3D(Triad(
        triad.getX() + other.triad.getX(),
        triad.getY() + other.triad.getY(),
        triad.getZ() + other.triad.getZ()
    ));
}

int Vector3D::operator*(const Vector3D& other) const {
    return triad.getX() * other.triad.getX() +
        triad.getY() * other.triad.getY() +
        triad.getZ() * other.triad.getZ();
}
    
Vector3D& Vector3D::operator++() {
    ++triad;
    return *this;
}

Vector3D Vector3D::operator++(int) {
    Vector3D temp(*this);
    ++triad;
    return temp;
}

Vector3D& Vector3D::operator--() {
    --triad;
    return *this;
}

Vector3D Vector3D::operator--(int) {
    Vector3D temp(*this);
    --triad;
    return temp;
}