#include "rectangle.h"
#include "utilities.h"
#include <cmath>
#include <sstream>

using namespace std;

double Rectangle::getX() const { return x; }
double Rectangle::getY() const { return y; }
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }
double Rectangle::getAngle() const { return angle; }

void Rectangle::setX(double newX) { x = newX; }
void Rectangle::setY(double newY) { y = newY; }
void Rectangle::setWidth(double newWidth) {
    width = (newWidth > 0) ? newWidth : 1.0;
}
void Rectangle::setHeight(double newHeight) {
    height = (newHeight > 0) ? newHeight : 1.0;
}
void Rectangle::setAngle(double newAngle) {
    angle = fmod(newAngle, 360.0);  // fmod of 5.3 / 2 is 1.300000 
    if (angle < 0)                  // (Returns the floating-point remainder of 
        angle += 360.0;             // numer/denom (rounded towards zero):
}

void Rectangle::Init() {
    x = y = 0.0;
    setWidth(1.0);
    setHeight(1.0);
    setAngle(0.0);
}

void Rectangle::Read() {
    x = readDouble("Enter x: ");
    y = readDouble("Enter y: ");
    setWidth(readDouble("Enter width: "));
    setHeight(readDouble("Enter height: "));
    setAngle(readDouble("Enter angle: "));
}

void Rectangle::Display() const {
    cout << toString() << "\n";
}

std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << "Rectangle [x=" << x << ", y=" << y
        << ", width=" << width << ", height=" << height
        << ", angle=" << angle << "°]";
    return ss.str();
}

void Rectangle::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Rectangle::resize(double newWidth, double newHeight) {
    setWidth(newWidth);
    setHeight(newHeight);
}

void Rectangle::rotate(double delta) {
    setAngle(angle + delta);
}

void Rectangle::promptAndResize() {
    double w = readDouble("Enter new width: ");
    double h = readDouble("Enter new height: ");
    resize(w, h);
}