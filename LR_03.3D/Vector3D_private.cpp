#include "Vector3D_private.h"

Vector3D_private::Vector3D_private() : Triad() {}
Vector3D_private::Vector3D_private(const Triad& triad) : Triad(triad) {}
Vector3D_private::Vector3D_private(const Vector3D_private& other) : Triad(other) {}

int Vector3D_private::getX() const { return Triad::getX(); }
int Vector3D_private::getY() const { return Triad::getY(); }
int Vector3D_private::getZ() const { return Triad::getZ(); }

void Vector3D_private::setX(int x) { Triad::setX(x); }
void Vector3D_private::setY(int y) { Triad::setY(y); }
void Vector3D_private::setZ(int z) { Triad::setZ(z); }

Vector3D_private& Vector3D_private::operator=(const Vector3D_private& other) {
    Triad::operator=(other);
    return *this;
}

std::istream& operator>>(std::istream& in, Vector3D_private& vec) {
    Triad triad;
    in >> triad;
    vec = Vector3D_private(triad);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3D_private& vec) {
    out << "(" << vec.getX() << ", " << vec.getY() << ", " << vec.getZ() << ")";
    return out;
}

Vector3D_private::operator std::string() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

Vector3D_private operator+(const Vector3D_private& v1, const Vector3D_private& v2) {
    return Vector3D_private(Triad(v1.getX() + v2.getX(),
        v1.getY() + v2.getY(),
        v1.getZ() + v2.getZ()));
}

int operator*(const Vector3D_private& v1, const Vector3D_private& v2) {
    return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

Vector3D_private& operator++(Vector3D_private& v) {
    v.setX(v.getX() + 1);
    v.setY(v.getY() + 1);
    v.setZ(v.getZ() + 1);
    return v;
}

Vector3D_private operator++(Vector3D_private& v, int) {
    Vector3D_private temp(v);
    ++v;
    return temp;
}

Vector3D_private& operator--(Vector3D_private& v) {
    v.setX(v.getX() - 1);
    v.setY(v.getY() - 1);
    v.setZ(v.getZ() - 1);
    return v;
}

Vector3D_private operator--(Vector3D_private& v, int) {
    Vector3D_private temp(v);
    --v;
    return temp;
}