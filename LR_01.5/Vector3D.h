#pragma once
#include "Triad.h"

class Vector3D {
private:
    Triad triad;
public:
    Triad getTriad() const { return triad; }
    void setTriad(const Triad& t) { triad = t; }
    void Init(const Triad& t);
    void Display() const;
    void Read();
    std::string toString() const;

    friend int scalarProduct(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D add(const Vector3D& v1, const Vector3D& v2);
};
