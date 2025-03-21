#include "Triad.h"

Triad::Triad() : x(0), y(0), z(0) {}
Triad::Triad(int x, int y, int z) : x(x), y(y), z(z) {}
Triad::Triad(const Triad& other) : x(other.x), y(other.y), z(other.z) {}

int Triad::getX() const { return x; }
int Triad::getY() const { return y; }
int Triad::getZ() const { return z; }

void Triad::setX(int x) { this->x = x; }
void Triad::setY(int y) { this->y = y; }
void Triad::setZ(int z) { this->z = z; }

Triad& Triad::operator=(const Triad& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Triad& triad) {
    std::cout << "Enter x, y, z: ";
    in >> triad.x >> triad.y >> triad.z;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Triad& triad) {
    out << "(" << triad.x << ", " << triad.y << ", " << triad.z << ")";
    return out;
}

Triad::operator std::string() const {
    std::stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

Triad operator+(const Triad& t, int number) {
    return Triad(t.x + number, t.y + number, t.z + number);
}

Triad operator+(int number, const Triad& t) {
    return Triad(number + t.x, number + t.y, number + t.z);
}

Triad& operator+=(Triad& t, int number) {
    t.x += number;
    t.y += number;
    t.z += number;
    return t;
}

Triad operator*(const Triad& t, int number) {
    return Triad(t.x * number, t.y * number, t.z * number);
}

Triad operator*(int number, const Triad& t) {
    return Triad(number * t.x, number * t.y, number * t.z);
}

Triad& operator*=(Triad& t, int number) {
    t.x *= number;
    t.y *= number;
    t.z *= number;
    return t;
}

bool operator==(const Triad& t1, const Triad& t2) {
    return (t1.x == t2.x && t1.y == t2.y && t1.z == t2.z);
}

Triad operator+(const Triad& t1, const Triad& t2) {
    return Triad(t1.x + t2.x, t1.y + t2.y, t1.z + t2.z);
}

Triad& operator++(Triad& t) {
    ++t.x;
    ++t.y;
    ++t.z;
    return t;
}

Triad operator++(Triad& t, int) {
    Triad temp = t;
    ++t.x;
    ++t.y;
    ++t.z;
    return temp;
}

Triad& operator--(Triad& t) {
    --t.x;
    --t.y;
    --t.z;
    return t;
}

Triad operator--(Triad& t, int) {
    Triad temp = t;
    --t.x;
    --t.y;
    --t.z;
    return temp;
}