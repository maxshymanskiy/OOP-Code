#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Vector3D 
{
public:
    class Triad 
    {
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
        void Read();
        void Display() const;
        std::string toString() const;
    };

private:
    Triad triad;

public:
    void Init(const Triad& t);
    void Read();
    void Display() const;
    std::string toString() const;

    Triad getTriad() const { return triad; }
    void setTriad(const Triad& t) { triad = t; }

    friend int scalarProduct(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D add(const Vector3D& v1, const Vector3D& v2);
};