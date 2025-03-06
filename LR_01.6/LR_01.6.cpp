#include <iostream>
#include "Vector3D.h"
using namespace std;

int main() {
    Vector3D v1, v2;

    cout << "Enter Vector 1:\n";
    v1.Read();
    cout << "Enter Vector 2:\n";
    v2.Read();

    Vector3D sum = add(v1, v2);
    cout << "Sum of vectors:\n";
    sum.Display();

    cout << "Scalar product: " << scalarProduct(v1, v2) << endl;

    return 0;
}