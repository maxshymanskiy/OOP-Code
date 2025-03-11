#include "Vector3D.h"

void Vector3D::Init(const Triad& t)
{
    setTriad(t);
}

void Vector3D::Display() const
{
    cout << "Vector3D: " << toString() << endl;
}

void Vector3D::Read()
{
    Triad t;
    t.Read();
    Init(t);
}

string Vector3D::toString() const {
    return triad.toString();
}

Vector3D add(const Vector3D& v1, const Vector3D& v2)
{
    Triad resultTriad;
    resultTriad.Init(
        v1.triad.getX() + v2.triad.getX(),
        v1.triad.getY() + v2.triad.getY(),
        v1.triad.getZ() + v2.triad.getZ()
    );

    Vector3D result;
    result.Init(resultTriad);
    return result;
}

int scalarProduct(const Vector3D& v1, const Vector3D& v2)
{
    return (v1.triad.getX() * v2.triad.getX() +
        v1.triad.getY() * v2.triad.getY() +
        v1.triad.getZ() * v2.triad.getZ());
}
