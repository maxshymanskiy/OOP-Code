#include "Vector3D.h"

int Vector3D::Triad::triadCounter = 0;

Vector3D::Triad::Triad() : x(0), y(0), z(0) {
    ++triadCounter;
}

Vector3D::Triad::Triad(int x, int y, int z) : x(x), y(y), z(z) {
    ++triadCounter;
}

Vector3D::Triad::Triad(const Triad& other) : x(other.x), y(other.y), z(other.z) {
    ++triadCounter;
}

Vector3D::Triad::~Triad() {
    --triadCounter;
}

Vector3D::Triad operator+(const Vector3D::Triad& t1, const Vector3D::Triad& t2) {
    return Vector3D::Triad(
        t1.x + t2.x,
        t1.y + t2.y,
        t1.z + t2.z
    );
}

Vector3D::Triad operator*(const Vector3D::Triad& t, int scalar) {
    return Vector3D::Triad(
        t.x * scalar,
        t.y * scalar,
        t.z * scalar
    );
}

bool operator==(const Vector3D::Triad& t1, const Vector3D::Triad& t2) {
    return t1.x == t2.x && t1.y == t2.y && t1.z == t2.z;
}

Vector3D::Triad& operator++(Vector3D::Triad& t) {
    ++t.x; ++t.y; ++t.z;
    return t;
}

Vector3D::Triad operator++(Vector3D::Triad& t, int) {
    Vector3D::Triad temp(t);
    ++t;
    return temp;
}

Vector3D::Triad& operator--(Vector3D::Triad& t) {
    --t.x; --t.y; --t.z;
    return t;
}

Vector3D::Triad operator--(Vector3D::Triad& t, int) {
    Vector3D::Triad temp(t);
    --t;
    return temp;
}

std::istream& operator>>(std::istream& in, Vector3D::Triad& t) {
    std::cout << "Enter x, y, z: ";
    return in >> t.x >> t.y >> t.z;
}

std::ostream& operator<<(std::ostream& out, const Vector3D::Triad& t) {
    return out << "(" << t.x << ", " << t.y << ", " << t.z << ")";
}

/////////////////////////////////
int Vector3D::vector3DCounter = 0;

Vector3D::Vector3D() : triad() {
    ++vector3DCounter;
}

Vector3D::Vector3D(const Triad& t) : triad(t) {
    ++vector3DCounter;
}

Vector3D::Vector3D(const Vector3D& other) : triad(other.triad) {
    ++vector3DCounter;
}

Vector3D::~Vector3D() {
    --vector3DCounter;
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

std::istream& operator>>(std::istream& in, Vector3D& v) {
    return in >> v.triad;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
    return out << "Vector3D: " << v.triad;
}