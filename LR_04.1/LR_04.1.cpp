#include <iostream>
#include <typeinfo>  
#include "Cube.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"
#include "Sphere.h"
using namespace std;

int main()
{
    ShapeBase* cube = new Cube(5.0);
    ShapeBase* box = new Parallelepiped(2.0, 3.0, 4.0);
    ShapeBase* pyramid = new Tetrahedron(6.0);
    ShapeBase* ball = new Sphere(3.0);

    cout << "Type: " << typeid(*cube).name() << "\n";
    cout << "Cube:\nSurface area: " << cube->surface_area() << "\n\n";

    cout << "Type: " << typeid(*box).name() << "\n";
    cout << "Parallelepiped:\nSurface area: " << box->surface_area() << "\n\n";

    cout << "Type: " << typeid(*pyramid).name() << "\n";
    cout << "Tetrahedron:\nSurface area: " << pyramid->surface_area() << "\n\n";

    cout << "Type: " << typeid(*ball).name() << "\n";
    cout << "Sphere:\nSurface area: " << ball->surface_area() << "\n\n";

    delete cube;
    delete box;
    delete pyramid;
    delete ball;

    return 0;
}
