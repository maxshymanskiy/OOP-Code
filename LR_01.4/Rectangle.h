// rectangle.h
#pragma once
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
    bool Init();
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    bool resize(double newWidth, double newHeight);
    void rotate(double delta);
    bool promptAndResize();
};