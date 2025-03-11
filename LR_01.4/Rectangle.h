// rectangle.h
#pragma once
#include "utilities.h"
#include <cmath>
#include <sstream>
#include <string>
class Rectangle {
private:
    double x, y, width, height, angle;
public:
    double getX() const;
    double getY() const;
    double getWidth() const;
    double getHeight() const;
    double getAngle() const;
    void setX(double newX);
    void setY(double newY);
    bool setWidth(double newWidth);
    bool setHeight(double newHeight);
    bool setAngle(double newAngle);

    bool Init(double newX, double newY, double newWidth, double newHeight, double newAngle);
    void Read();
    void Display() const;

    std::string toString() const;
    void move(double dx, double dy);
    bool resize(double newWidth, double newHeight);
    void rotate(double delta);
    bool promptAndResize();
};