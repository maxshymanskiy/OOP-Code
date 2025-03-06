#include "Rectangle.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Rectangle::getX() const { return x; }
void Rectangle::setX(double newX) { x = newX; }
double Rectangle::getY() const { return y; }
void Rectangle::setY(double newY) { y = newY; }
double Rectangle::getWidth() const { return width; }
void Rectangle::setWidth(double w) { width = w; }
double Rectangle::getHeight() const { return height; }
void Rectangle::setHeight(double h) { height = h; }
double Rectangle::getAngle() const { return angle; }
void Rectangle::setAngle(double a) { angle = a; }

void Rectangle::Init() {
    x = y = angle = 0.0;
    width = height = 1.0;
}

void Rectangle::Read() {
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    cout << "width: "; cin >> width;
    cout << "height: "; cin >> height;
    cout << "angle: "; cin >> angle;
}

void Rectangle::Display() const {
    cout << "Rectangle: (" << x << ", " << y << "), "
        << width << "x" << height << ", angle " << angle << "°\n";
}

string Rectangle::toString() const {
    return "Rectangle [x=" + to_string(x) + ", y=" + to_string(y)
        + ", w=" + to_string(width) + ", h=" + to_string(height)
        + ", θ=" + to_string(angle) + "]";
}

void Rectangle::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Rectangle::resize(double w, double h) {
    width = w;
    height = h;
}

void Rectangle::rotate(double delta) {
    angle = fmod(angle + delta, 360.0);
    if (angle < 0) angle += 360.0;
}