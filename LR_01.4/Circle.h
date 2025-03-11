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
    bool setRadius(double newRadius);
    bool Init();
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    bool resize(double newRadius);  
    bool rotate(double angle);      
    bool promptAndResize();        
};