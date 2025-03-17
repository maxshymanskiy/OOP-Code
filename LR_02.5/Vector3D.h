#pragma once
#include "Triad.h"

class Vector3D {
private:
    Triad triad;

public:
    Vector3D();
    Vector3D(const Triad& triad);
    Vector3D(const Vector3D& other);

    Triad getTriad() const;
    void setTriad(const Triad& triad);

    Vector3D& operator=(const Vector3D& other);

    friend std::istream& operator>>(std::istream& in, Vector3D& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);

    operator std::string() const;

    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
    friend int operator*(const Vector3D& v1, const Vector3D& v2);

    friend Vector3D& operator++(Vector3D& v);
    friend Vector3D operator++(Vector3D& v, int);
    friend Vector3D& operator--(Vector3D& v);
    friend Vector3D operator--(Vector3D& v, int);
};