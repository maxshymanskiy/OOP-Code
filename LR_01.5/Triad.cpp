#include "Triad.h"

void Triad::Init(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Triad::Display() const {
    cout << "Triad: " << toString() << endl;
}

void Triad::Read() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;
    Init(a, b, c);
}

Triad& Triad::addNumber(int number) {
    x += number;
    y += number;
    z += number;
    return *this;
}

Triad& Triad::multiplyByNumber(int number) {
    x *= number;
    y *= number;
    z *= number;
    return *this; 
}

bool Triad::isEqual(const Triad& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

std::string Triad::toString() const {
    ostringstream oss;
    oss << "(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}