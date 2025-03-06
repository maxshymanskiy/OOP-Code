#include "Circle.h"
#include <iostream>
#include <string>
using namespace std;

double Circle::getX() const { return x; }
void Circle::setX(double newX) { x = newX; }
double Circle::getY() const { return y; }
void Circle::setY(double newY) { y = newY; }
double Circle::getRadius() const { return radius; }
void Circle::setRadius(double newRadius) { radius = newRadius; }

void Circle::Init() {
    x = y = 0.0;
    radius = 1.0;
}

void Circle::Read() {
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    cout << "radius: "; cin >> radius;
}

void Circle::Display() const {
    cout << "Circle: (" << x << ", " << y << "), radius " << radius << endl;
}

string Circle::toString() const {
    return "Circle [x=" + to_string(x) + ", y=" + to_string(y)
        + ", r=" + to_string(radius) + "]";
}

void Circle::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Circle::resize(double newRadius) {
    radius = newRadius;
}

void Circle::rotate(double) {}