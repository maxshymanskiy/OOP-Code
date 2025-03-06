#include "circle.h"
#include "utilities.h"
#include <sstream>

double Circle::getX() const { return x; }
void Circle::setX(double newX) { x = newX; }
double Circle::getY() const { return y; }
void Circle::setY(double newY) { y = newY; }

double Circle::getRadius() const { return radius; }
void Circle::setRadius(double newRadius) {
    radius = (newRadius > 0) ? newRadius : 1.0;
}

void Circle::Init() {
    x = y = 0.0;
    setRadius(1.0);
}

void Circle::Read() {
    x = readDouble("Enter x: ");
    y = readDouble("Enter y: ");
    setRadius(readDouble("Enter radius: "));
}

void Circle::Display() const {
    std::cout << toString() << "\n";
}

std::string Circle::toString() const {
    std::stringstream ss;
    ss << "Circle [x=" << x << ", y=" << y << ", r=" << radius << "]";
    return ss.str();
}

void Circle::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Circle::resize(double newRadius) {
    setRadius(newRadius);
}

void Circle::rotate(double) {}

void Circle::promptAndResize() {
    resize(readDouble("Enter new radius: "));
}