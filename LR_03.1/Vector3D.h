#pragma once
#include "Triad.h"

class Vector3D : public Triad {
public:
    Vector3D(int x = 0, int y = 0, int z = 0);
    Vector3D(const Triad& triad);

    friend Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs);
    friend int operator*(const Vector3D& lhs, const Vector3D& rhs);

    Vector3D& operator=(const Vector3D& other);

    std::string to_string() const;
    operator std::string() const;

    friend std::istream& operator>>(std::istream& in, Vector3D& vec);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);
};