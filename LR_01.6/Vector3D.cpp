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
    while (true) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int x, y, z;
        if (ss >> x >> y >> z && ss.eof()) {
            Init(x, y, z);
            break;
        }
        cout << "Invalid input. Please enter three integers: ";
        cin.clear();
    }
}

void Vector3D::Triad::Display() const
{
    cout << toString();
}

std::string Vector3D::Triad::toString() const
{
    std::stringstream ss;
    ss << "(" << x << ", " << y << ", " << z << ")";
    return ss.str();
}

Vector3D::Triad& Vector3D::Triad::addNumber(int number)
{
    x += number;
    y += number;
    z += number;
    return *this;
}

Vector3D::Triad& Vector3D::Triad::multiplyByNumber(int number)
{
    x *= number;
    y *= number;
    z *= number;
    return *this;
}

bool Vector3D::Triad::isEqual(const Triad& other) const
{
    return x == other.x && y == other.y && z == other.z;
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
    cout << toString() << std::endl;
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
