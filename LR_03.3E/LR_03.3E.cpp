#include <iostream>
#include <Windows.h>
#include "Vector3D.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    cout << "Початкова кількість об'єктів: " << Object::getCount() << endl;

    Triad t1(1, 2, 3);
    cout << "Після створення t1: " << Object::getCount() << endl;

    Vector3D v1(t1);
    cout << "Після створення v1: " << Object::getCount() << endl;

    Vector3D v2;
    cout << "Введіть вектор v2:\n";
    cin >> v2;

    Vector3D v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    int scalar = v1 * v2;
    cout << "Скалярний добуток: " << scalar << endl;

    cout << "v1 перед інкрементом: " << v1 << endl;
    ++v1;
    cout << "++v1: " << v1 << endl;
    v1++;
    cout << "v1++: " << v1 << endl;

    cout << "Кінцева кількість об'єктів: " << Object::getCount() << endl;

    return 0;
}
