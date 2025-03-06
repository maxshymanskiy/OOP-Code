#pragma once
#include <string>

class Square {
private:
    double x, y, side, angle;
public:
    double getX() const;
    double getY() const;
    double getSide() const;
    double getAngle() const;

    void setX(double newX);
    void setY(double newY);
    void setSide(double newSide);
    void setAngle(double newAngle);

    void Init();
    void Read();
    void Display() const;
    std::string toString() const;

    void move(double dx, double dy);
    void resize(double newSide);
    void rotate(double delta);
    void promptAndResize();
};