#pragma once
#include "Triad.h"

class Vector3D_public : public Triad {
public:
    Vector3D_public();
    Vector3D_public(const Triad& triad);
    Vector3D_public(const Vector3D_public& other);

    Vector3D_public& operator=(const Vector3D_public& other);

    friend std::istream& operator>>(std::istream& in, Vector3D_public& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D_public& vec);

    operator std::string() const;

    friend Vector3D_public operator+(const Vector3D_public& v1, const Vector3D_public& v2);
    friend int operator*(const Vector3D_public& v1, const Vector3D_public& v2);

    friend Vector3D_public& operator++(Vector3D_public& v);
    friend Vector3D_public operator++(Vector3D_public& v, int);
    friend Vector3D_public& operator--(Vector3D_public& v);
    friend Vector3D_public operator--(Vector3D_public& v, int);
};