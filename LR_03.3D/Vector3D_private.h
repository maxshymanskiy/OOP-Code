#pragma once
#include "Triad.h"

class Vector3D_private : private Triad {
public:
    Vector3D_private();
    Vector3D_private(const Triad& triad);
    Vector3D_private(const Vector3D_private& other);

    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);

    Vector3D_private& operator=(const Vector3D_private& other);

    friend std::istream& operator>>(std::istream& in, Vector3D_private& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D_private& vec);

    operator std::string() const;

    friend Vector3D_private operator+(const Vector3D_private& v1, const Vector3D_private& v2);
    friend int operator*(const Vector3D_private& v1, const Vector3D_private& v2);

    friend Vector3D_private& operator++(Vector3D_private& v);
    friend Vector3D_private operator++(Vector3D_private& v, int);
    friend Vector3D_private& operator--(Vector3D_private& v);
    friend Vector3D_private operator--(Vector3D_private& v, int);
};