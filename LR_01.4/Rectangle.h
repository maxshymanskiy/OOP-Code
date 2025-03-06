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
    void setWidth(double newWidth);
    void setHeight(double newHeight);
    void setAngle(double newAngle);

    void Init();
    void Read();
    void Display() const;
    std::string toString() const;

    void move(double dx, double dy);
    void resize(double newWidth, double newHeight);
    void rotate(double delta);
    void promptAndResize();
};