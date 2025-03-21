#include "Vector3D_public.h"

Vector3D_public::Vector3D_public() : Triad() {}
Vector3D_public::Vector3D_public(const Triad& triad) : Triad(triad) {}
Vector3D_public::Vector3D_public(const Vector3D_public& other) : Triad(other) {}

Vector3D_public& Vector3D_public::operator=(const Vector3D_public& other) {
    Triad::operator=(other);
    return *this;
}

std::istream& operator>>(std::istream& in, Vector3D_public& vec) {
    in >> static_cast<Triad&>(vec);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D_public& vec) {
    out << static_cast<const Triad&>(vec);
    return out;
}

Vector3D_public::operator std::string() const {
    return static_cast<std::string>(static_cast<const Triad&>(*this));
}

Vector3D_public operator+(const Vector3D_public& v1, const Vector3D_public& v2) {
    return Vector3D_public(static_cast<const Triad&>(v1) + static_cast<const Triad&>(v2));
}

int operator*(const Vector3D_public& v1, const Vector3D_public& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D_public& operator++(Vector3D_public& v) {
    ++static_cast<Triad&>(v);
    return v;
}

Vector3D_public operator++(Vector3D_public& v, int) {
    Vector3D_public temp(v);
    ++v;
    return temp;
}

Vector3D_public& operator--(Vector3D_public& v) {
    --static_cast<Triad&>(v);
    return v;
}

Vector3D_public operator--(Vector3D_public& v, int) {
    Vector3D_public temp(v);
    --v;
    return temp;
}