#pragma once
#include <iostream>
using namespace std;

class Triad {
private:
    int x, y, z;
public:
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setZ(int z) { this->z = z; }

    void Init(int x, int y, int z);
    void addNumber(int number);
    void multiplyByNumber(int number);
    bool isEqual(const Triad& other) const;
    void Display() const;
    void Read();
};
 
