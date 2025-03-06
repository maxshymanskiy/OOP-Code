#include "Triad.h"
#include <iostream>

void Triad::Init(int x, int y, int z) {
    setX(x);
    setY(y);
    setZ(z);
}

void Triad::addNumber(int number) {
    x += number;
    y += number;
    z += number;
}

void Triad::multiplyByNumber(int number) {
    x *= number;
    y *= number;
    z *= number;
}

bool Triad::isEqual(const Triad& other) const {
    return x == other.x && y == other.y && z == other.z;
}

void Triad::Display() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

void Triad::Read() {
    std::cout << "Enter x, y, z: ";
    std::cin >> x >> y >> z;
}