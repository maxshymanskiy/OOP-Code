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
    bool setSide(double newSide);  
    bool setAngle(double newAngle);  
    bool Init();  
    void Read();
    void Display() const;
    std::string toString() const;
    void move(double dx, double dy);
    bool resize(double newSide); 
    bool rotate(double delta);  
    bool promptAndResize(); 
};