// rectangle.cpp
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

bool Rectangle::setWidth(double newWidth) {
    if (newWidth >= 0) {
        width = newWidth;
        return true;
    }
    else {
        width = 0;
        return false;
    }
}

bool Rectangle::setHeight(double newHeight) {
    if (newHeight >= 0) {
        height = newHeight;
        return true;
    }
    else {
        height = 0;
        return false;
    }
}

bool Rectangle::setAngle(double newAngle) {
    angle = fmod(newAngle, 360.0);
    if (angle < 0)
        angle += 360.0;
    return true;  
}

bool Rectangle::Init() {
    x = 0.0;
    y = 0.0;
    bool widthSet = setWidth(1.0);
    bool heightSet = setHeight(1.0);
    bool angleSet = setAngle(0.0);

    return widthSet && heightSet && angleSet;
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

bool Rectangle::resize(double newWidth, double newHeight) {
    bool widthSet = setWidth(newWidth);
    bool heightSet = setHeight(newHeight);
    return widthSet && heightSet;
}

void Rectangle::rotate(double delta) {
    setAngle(angle + delta);
}

bool Rectangle::promptAndResize() {
    return resize(readDouble("Enter new width: "), readDouble("Enter new height: "));
}