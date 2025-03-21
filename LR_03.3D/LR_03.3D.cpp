#include <iostream>
#include <Windows.h>
#include "Vector3D_public.h"
#include "Vector3D_private.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Vector3D_public v1(Triad(1, 2, 3));
    Vector3D_public v2;

    cout << "Введіть публічний вектор (x y z): ";
    cin >> v2;

    cout << "\nПублічний вектор 1: " << v1 << endl;
    cout << "Публічний вектор 2: " << v2 << endl;

    Vector3D_public сума_публічних = v1 + v2;
    cout << "Сума публічних векторів: " << сума_публічних << endl;
    cout << "Скалярний добуток: " << (v1 * v2) << endl;

    ++v1;
    cout << "Після ++v1: " << v1 << endl;

    Vector3D_private v3(Triad(4, 5, 6));
    Vector3D_private v4;

    cout << "\nВведіть приватний вектор (x y z): ";
    cin >> v4;

    cout << "\nПриватний вектор 3: " << v3 << endl;
    cout << "Приватний вектор 4: " << v4 << endl;

    Vector3D_private сума_приватних = v3 + v4;
    cout << "Сума приватних векторів: " << сума_приватних << endl;
    cout << "Скалярний добуток: " << (v3 * v4) << endl;

    --v3;
    cout << "Після --v3: " << v3 << endl;

    return 0;
}