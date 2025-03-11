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

bool Square::setSide(double newSide) {
    if (newSide >= 0) {
        side = newSide;
        return true;
    }
    else {
        side = 0;
        return false;
    }
}

bool Square::setAngle(double newAngle) {
    angle = fmod(newAngle, 360.0);
    if (angle < 0) angle += 360.0;
    return true;  // Always returns true since any angle can be normalized
}

bool Square::Init() {
    x = 0.0;
    y = 0.0;
    bool sideSet = setSide(1.0);
    bool angleSet = setAngle(0.0);
    return sideSet && angleSet;
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

bool Square::resize(double newSide) {
    return setSide(newSide);
}

bool Square::rotate(double delta) {
    return setAngle(angle + delta);
}

bool Square::promptAndResize() {
    return resize(readDouble("Enter new side: "));
}