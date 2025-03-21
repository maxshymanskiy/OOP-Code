#include <iostream>
#include <Windows.h>
#include "Vector3D.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    cout << "��������� ������� ��'����: " << Object::getCount() << endl;

    Triad t1(1, 2, 3);
    cout << "ϳ��� ��������� t1: " << Object::getCount() << endl;

    Vector3D v1(t1);
    cout << "ϳ��� ��������� v1: " << Object::getCount() << endl;

    Vector3D v2;
    cout << "������ ������ v2:\n";
    cin >> v2;

    Vector3D v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    int scalar = v1 * v2;
    cout << "��������� �������: " << scalar << endl;

    cout << "v1 ����� �����������: " << v1 << endl;
    ++v1;
    cout << "++v1: " << v1 << endl;
    v1++;
    cout << "v1++: " << v1 << endl;

    cout << "ʳ����� ������� ��'����: " << Object::getCount() << endl;

    return 0;
}
