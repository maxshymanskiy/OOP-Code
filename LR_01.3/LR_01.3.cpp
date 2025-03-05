#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Fraction a, b;

    cout << "=== �������� ������� ����� ===\n";
    a.Read();

    cout << "\n=== �������� ������� ����� ===\n";
    b.Read();

    cout << "\n����������:\n";
    cout << "��� 1: " << a.toString() << endl;
    cout << "��� 2: " << b.toString() << endl;

    Fraction c = a.Subtract(b);
    cout << "г�����: " << c.toString() << endl;

    if (a == b) cout << "����� ���\n";
    else if (a < b) cout << "��� 1 ������\n";
    else cout << "��� 1 ������\n";

    return 0;
}