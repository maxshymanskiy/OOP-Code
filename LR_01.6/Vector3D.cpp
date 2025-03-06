#include "Vector3D.h"
#include <sstream>

void Vector3D::Triad::Init(int x, int y, int z) 
{
    setX(x);
    setY(y);
    setZ(z);
}

void Vector3D::Triad::Read() 
{
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;
}

void Vector3D::Triad::Display() const 
{
    cout << "(" << x << ", " << y << ", " << z << ")";
}

std::string Vector3D::Triad::toString() const 
{
    std::stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

void Vector3D::Init(const Triad& t) 
{
    triad = t;
}

void Vector3D::Read() 
{
    Triad t;
    t.Read();
    Init(t);
}

void Vector3D::Display() const 
{
    cout << "Vector3D: ";
    triad.Display();
    cout << std::endl;
}

std::string Vector3D::toString() const 
{
    return "Vector3D: " + triad.toString();
}

Vector3D add(const Vector3D& v1, const Vector3D& v2) 
{
    Vector3D::Triad t1 = v1.triad;
    Vector3D::Triad t2 = v2.triad;
    Vector3D::Triad result;
    result.Init(
        t1.getX() + t2.getX(),
        t1.getY() + t2.getY(),
        t1.getZ() + t2.getZ()
    );
    Vector3D vecResult;
    vecResult.Init(result);
    return vecResult;
}

int scalarProduct(const Vector3D& v1, const Vector3D& v2) 
{
    return (v1.triad.getX() * v2.triad.getX() +
        v1.triad.getY() * v2.triad.getY() +
        v1.triad.getZ() * v2.triad.getZ());
}