#include "square.h"
#include "utilities.h"
#include <cmath>
#include <sstream>

using namespace std;

double Square::getX() const { return x; }
double Square::getY() const { return y; }
double Square::getSide() const { return side; }
double Square::getAngle() const { return angle; }

void Square::setX(double newX) { x = newX; }
void Square::setY(double newY) { y = newY; }
void Square::setSide(double newSide) {
    side = (newSide > 0) ? newSide : 1.0;
}
void Square::setAngle(double newAngle) {
    angle = fmod(newAngle, 360.0);
    if (angle < 0) angle += 360.0;
}

void Square::Init() {
    x = y = 0.0;
    setSide(1.0);
    setAngle(0.0);
}

void Square::Read() {
    x = readDouble("Enter x: ");
    y = readDouble("Enter y: ");
    setSide(readDouble("Enter side: "));
    setAngle(readDouble("Enter angle: "));
}

void Square::Display() const {
    cout << toString() << "\n";
}

std::string Square::toString() const {
    std::stringstream ss;
    ss << "Square [x=" << x << ", y=" << y
        << ", side=" << side << ", angle=" << angle << "°]";
    return ss.str();
}

void Square::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Square::resize(double newSide) {
    setSide(newSide);
}

void Square::rotate(double delta) {
    setAngle(angle + delta);
}

void Square::promptAndResize() {
    resize(readDouble("Enter new side: "));
}