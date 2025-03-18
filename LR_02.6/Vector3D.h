#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Vector3D {
public:
    class Triad {
    public:
        Triad();
        Triad(int x, int y, int z);
        Triad(const Triad& other);
        ~Triad();

        int getX() const { return x; }
        int getY() const { return y; }
        int getZ() const { return z; }

        static int getTriadCount() { return triadCounter; }

        friend Triad operator+(const Triad& t1, const Triad& t2);
        friend Triad operator*(const Triad& t, int scalar);
        friend bool operator==(const Triad& t1, const Triad& t2);
        friend Triad& operator++(Triad& t);
        friend Triad operator++(Triad& t, int);
        friend Triad& operator--(Triad& t);
        friend Triad operator--(Triad& t, int);
        friend std::istream& operator>>(std::istream& in, Triad& t);
        friend std::ostream& operator<<(std::ostream& out, const Triad& t);

    private:
        int x, y, z;
        static int triadCounter;
    };

    Vector3D();
    Vector3D(const Triad& t);
    Vector3D(const Vector3D& other);
    ~Vector3D();

    static int getVector3DCount() { return vector3DCounter; }

    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
    friend int operator*(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D& operator++(Vector3D& v);
    friend Vector3D operator++(Vector3D& v, int);
    friend Vector3D& operator--(Vector3D& v);
    friend Vector3D operator--(Vector3D& v, int);
    friend std::istream& operator>>(std::istream& in, Vector3D& v);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& v);

private:
    Triad triad;
    static int vector3DCounter;
};
