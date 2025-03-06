#pragma once
#include <string>

class Rectangle {
private:
    double x, y, width, height, angle;
public:
    double getX() const;
    void setX(double newX);
    double getY() const;
    void setY(double newY);
    double getWidth() const;
    void setWidth(double w);
    double getHeight() const;
    void setHeight(double h);
    double getAngle() const;
    void setAngle(double a);
    void Init();
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    void resize(double w, double h);
    void rotate(double delta);
};
