#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "��������� ������� ��'����: " << Object::getCounter() << endl;

    {
        Fraction f1;
        cout << "ϳ��� ��������� f1, ������� ��'����: " << Object::getCounter() << endl;

        Fraction f2(123, 45678);
        cout << "ϳ��� ��������� f2, ������� ��'����: " << Object::getCounter() << endl;

        cout << "f1 (�� �������������): " << f1 << endl;
        cout << "f2 (�������������): " << f2 << endl;

        Fraction f3 = f2;
        cout << "ϳ��� ��������� f3, ������� ��'����: " << Object::getCounter() << endl;

        Fraction f4;
        f4 = f2;
        cout << "ϳ��� ��������� f4, ������� ��'����: " << Object::getCounter() << endl;

        cout << "f3 (���� f2): " << f3 << endl;
        cout << "f4 (�������� f2): " << f4 << endl;

        cout << "\n������ ������ ���:" << endl;
        Fraction a;
        cin >> a;
        cout << "������ ������ ���:" << endl;
        Fraction b;
        cin >> b;
        cout << "������ ���: " << a << endl;
        cout << "������ ���: " << b << endl;

        cout << "\n�������� ���������:" << endl;
        cout << "a == b: " << (a == b ? "������" : "�����") << endl;
        cout << "a != b: " << (a != b ? "������" : "�����") << endl;
        cout << "a < b: " << (a < b ? "������" : "�����") << endl;
        cout << "a > b: " << (a > b ? "������" : "�����") << endl;

        Fraction c = a - b;
        cout << "³�������(a, b): " << c << endl;

        cout << "\n������������ ���������� �� ����������� ��������:" << endl;
        cout << "a ��������: " << a << endl;

        Fraction temp;
        temp = ++a;
        cout << "temp = ++a: " << endl;
        cout << "a = " << a << ", temp = " << temp << endl;

        temp = --a;
        cout << "temp = --a: " << endl;
        cout << "a = " << a << ", temp = " << temp << endl;

        temp = a++;
        cout << "temp = a++: " << endl;
        cout << "a = " << a << ", temp = " << temp << endl;

        temp = a--;
        cout << "temp = a--: " << endl;
        cout << "a = " << a << ", temp = " << temp << endl;

        cout << "������� ������� ��'����: " << Object::getCounter() << endl;
    }

    cout << "ϳ��� �������� ��� ��������� �����, ������� ��'����: " << Object::getCounter() << endl;

    return 0;
}