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

    cout << "������ �������� ������ (x y z): ";
    cin >> v2;

    cout << "\n�������� ������ 1: " << v1 << endl;
    cout << "�������� ������ 2: " << v2 << endl;

    Vector3D_public ����_�������� = v1 + v2;
    cout << "���� �������� �������: " << ����_�������� << endl;
    cout << "��������� �������: " << (v1 * v2) << endl;

    ++v1;
    cout << "ϳ��� ++v1: " << v1 << endl;

    Vector3D_private v3(Triad(4, 5, 6));
    Vector3D_private v4;

    cout << "\n������ ��������� ������ (x y z): ";
    cin >> v4;

    cout << "\n��������� ������ 3: " << v3 << endl;
    cout << "��������� ������ 4: " << v4 << endl;

    Vector3D_private ����_��������� = v3 + v4;
    cout << "���� ��������� �������: " << ����_��������� << endl;
    cout << "��������� �������: " << (v3 * v4) << endl;

    --v3;
    cout << "ϳ��� --v3: " << v3 << endl;

    return 0;
}