#include <iostream>
#include <Windows.h>
#include "Vector3D.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Vector3D v1, v2;
    cout << "������ ���������� ������� ������� (x y z): ";
    cin >> v1;
    cout << "������ ���������� ������� ������� (x y z): ";
    cin >> v2;

    cout << "\n������ �������:\n";
    cout << "v1: " << v1 << "\n";
    cout << "v2: " << v2 << "\n";

    Vector3D v3 = v1 + v2;
    cout << "\n���������� ��������:\n";
    cout << "v1 + v2: " << v3 << "\n";
    cout << "��������� ������� v1 * v2: " << v1 * v2 << "\n";

    return 0;
}