#include "Square.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Square::getX() const { return x; }
void Square::setX(double newX) { x = newX; }
double Square::getY() const { return y; }
void Square::setY(double newY) { y = newY; }
double Square::getSide() const { return side; }
void Square::setSide(double s) { side = s; }
double Square::getAngle() const { return angle; }
void Square::setAngle(double a) { angle = a; }

void Square::Init() {
    x = y = angle = 0.0;
    side = 1.0;
}

void Square::Read() {
    cout << "x: "; cin >> x;
    cout << "y: "; cin >> y;
    cout << "side: "; cin >> side;
    cout << "angle: "; cin >> angle;
}

void Square::Display() const {
    cout << "Square: (" << x << ", " << y << "), side " << side
        << ", angle " << angle << "°\n";
}

string Square::toString() const {
    return "Square [x=" + to_string(x) + ", y=" + to_string(y)
        + ", s=" + to_string(side) + ", θ=" + to_string(angle) + "]";
}

void Square::move(double dx, double dy) {
    x += dx;
    y += dy;
}

void Square::resize(double s) {
    side = s;
}

void Square::rotate(double delta) {
    angle = fmod(angle + delta, 360.0);
    if (angle < 0) angle += 360.0;
}