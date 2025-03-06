#pragma once
#include <string>

class Circle {
private:
    double x, y, radius;
public:
    double getX() const;
    void setX(double newX);
    double getY() const;
    void setY(double newY);
    double getRadius() const;
    void setRadius(double newRadius);
    void Init();
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    void resize(double newRadius);
    void rotate(double angle);
};

