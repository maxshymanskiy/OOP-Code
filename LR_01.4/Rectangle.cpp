#include "rectangle.h"
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

bool Rectangle::Init(double newX, double newY, double newWidth, double newHeight, double newAngle) {
    if (!setWidth(newWidth) || !setHeight(newHeight) || !setAngle(newAngle)) {
        return false;  
    }

    x = newX;
    y = newY;
    return true;
}

void Rectangle::Read() {
    double newX, newY, newWidth, newHeight, newAngle;

    do {
        newX = readDouble("Enter x: ");
        newY = readDouble("Enter y: ");
        newWidth = readDouble("Enter width: ");
        newHeight = readDouble("Enter height: ");
        newAngle = readDouble("Enter angle: ");

        if (!Init(newX, newY, newWidth, newHeight, newAngle)) {
            cout << "Invalid input. Please try again.\n";
        }

    } while (!Init(newX, newY, newWidth, newHeight, newAngle)); 

    cout << "Rectangle initialized successfully!\n";
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