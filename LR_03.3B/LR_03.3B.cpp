#include "Fraction.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "=== ���������� ����� Pair ===" << endl;

    cout << "������ �������� ��� ���� p1 (������: ����� �����):" << endl;
    Pair p1;
    cin >> p1;
    cout << "p1: " << p1 << endl;

    cout << "������ �������� ��� ���� p2 (������: ����� �����):" << endl;
    Pair p2;
    cin >> p2;
    cout << "p2: " << p2 << endl;

    cout << "\n�������� ��������� ��� Pair:" << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "���" : "�") << endl;
    cout << "p1 != p2: " << (p1 != p2 ? "���" : "�") << endl;
    cout << "p1 < p2: " << (p1 < p2 ? "���" : "�") << endl;
    cout << "p1 > p2: " << (p1 > p2 ? "���" : "�") << endl;
    cout << "p1 <= p2: " << (p1 <= p2 ? "���" : "�") << endl;
    cout << "p1 >= p2: " << (p1 >= p2 ? "���" : "�") << endl;

    cout << "\n=== ���������� ����� Fraction ===" << endl;

    cout << "������ ������ ���:" << endl;
    Fraction a;
    cout << "������ ���� �������: ";
    long whole;
    cin >> whole;
    a.setWhole(whole);

    cout << "������ ������� ������� (�� 5 ����): ";
    unsigned short frac;
    cin >> frac;
    a.setFractional(frac);

    cout << "������ ������ ���:" << endl;
    Fraction b;
    cout << "������ ���� �������: ";
    cin >> whole;
    b.setWhole(whole);

    cout << "������ ������� ������� (�� 5 ����): ";
    cin >> frac;
    b.setFractional(frac);

    cout << "������ ���: " << a.getWhole() << "." << a.getFractional() << endl;
    cout << "������ ���: " << b.getWhole() << "." << b.getFractional() << endl;

    cout << "\n�������� ��������� ��� Fraction:" << endl;
    cout << "a == b: " << (a == b ? "���" : "�") << endl;
    cout << "a != b: " << (a != b ? "���" : "�") << endl;
    cout << "a < b: " << (a < b ? "���" : "�") << endl;
    cout << "a > b: " << (a > b ? "���" : "�") << endl;

    Fraction c = a - b;
    cout << "��������� �������� (a - b): " << c.getWhole() << "." << c.getFractional() << endl;

    cout << "\n���������� ���������� �� ����������:" << endl;
    cout << "��������� �������� a: " << a.getWhole() << "." << a.getFractional() << endl;

    Fraction temp;
    temp = ++a;
    cout << "temp = ++a: " << endl;
    cout << "a = " << a.getWhole() << "." << a.getFractional()
        << ", temp = " << temp.getWhole() << "." << temp.getFractional() << endl;

    temp = --a;
    cout << "temp = --a: " << endl;
    cout << "a = " << a.getWhole() << "." << a.getFractional()
        << ", temp = " << temp.getWhole() << "." << temp.getFractional() << endl;

    temp = a++;
    cout << "temp = a++: " << endl;
    cout << "a = " << a.getWhole() << "." << a.getFractional()
        << ", temp = " << temp.getWhole() << "." << temp.getFractional() << endl;

    temp = a--;
    cout << "temp = a--: " << endl;
    cout << "a = " << a.getWhole() << "." << a.getFractional()
        << ", temp = " << temp.getWhole() << "." << temp.getFractional() << endl;

    return 0;
}