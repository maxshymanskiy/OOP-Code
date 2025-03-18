#include "BigInteger.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    BigInteger num1, num2;

    cout << "������������ ������� �����:\n";
    num1.Read();

    cout << "������������ ������� �����:\n";
    num2.Read();

    cout << "\n������� �����:\n";
    cout << "����� �����: ";
    num1.Display();
    cout << "����� �����: ";
    num2.Display();

    cout << "\n���������� ��������:\n";

    if (num1 == num2) {
        cout << "����� ���� (==)\n";
    }
    else {
        cout << "����� �� ���� (!=)\n";

        if (num1 < num2) {
            cout << "����� ����� ����� �� ����� (<)\n";
        }
        else {
            cout << "����� ����� ����� �� ����� (>)\n";
        }
    }

    return 0;
}