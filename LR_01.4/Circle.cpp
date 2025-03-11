#include "circle.h"
#include "utilities.h"
#include <sstream>

double Circle::getX() const { return x; }
void Circle::setX(double newX) { x = newX; }
double Circle::getY() const { return y; }
void Circle::setY(double newY) { y = newY; }
double Circle::getRadius() const { return radius; }

bool Circle::setRadius(double newRadius) {
    if (newRadius >= 0) {
        radius = newRadius;
        return true;
    }
    else {
        radius = 0;
        return false;
    }
}

bool Circle::Init() {
    x = 0.0;
    y = 0.0;
    return setRadius(1.0);
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

bool Circle::rotate(double angle) {
    return true;
}

bool Circle::resize(double newRadius) {
    return setRadius(newRadius);
}

bool Circle::promptAndResize() {
    return resize(readDouble("Enter new radius: "));
}