#pragma once
#include <string>

class Square {
private:
    double x, y, side, angle;
public:
    double getX() const;
    void setX(double newX);
    double getY() const;
    void setY(double newY);
    double getSide() const;
    void setSide(double newSide);
    double getAngle() const;
    void setAngle(double newAngle);
    void Init();
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    void resize(double newSide);
    void rotate(double delta);
};
