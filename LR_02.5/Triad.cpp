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

Triad Triad::operator+(int number) const {
    return Triad(x + number, y + number, z + number);
}

Triad& Triad::operator+=(int number) {
    x += number;
    y += number;
    z += number;
    return *this;
}

Triad Triad::operator*(int number) const {
    return Triad(x * number, y * number, z * number);
}

Triad& Triad::operator*=(int number) {
    x *= number;
    y *= number;
    z *= number;
    return *this;
}

bool Triad::operator==(const Triad& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

Triad& Triad::operator++() {
    ++x;
    ++y;
    ++z;
    return *this;
}

Triad Triad::operator++(int) {
    Triad temp(*this);
    ++(*this);
    return temp;
}

Triad& Triad::operator--() {
    --x;
    --y;
    --z;
    return *this;
}

Triad Triad::operator--(int) {
    Triad temp(*this);
    --(*this);
    return temp;
}