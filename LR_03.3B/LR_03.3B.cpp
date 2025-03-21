#include "Fraction.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //cout << "=== ���������� ����� Pair ===" << endl;
    //cout << "������ �������� ��� ���� p1 (������: ����� �����):" << endl;
    //Pair p1;
    //cin >> p1;
    //cout << "p1: " << p1 << endl;
    //cout << "������ �������� ��� ���� p2 (������: ����� �����):" << endl;
    //Pair p2;
    //cin >> p2;
    //cout << "p2: " << p2 << endl;
    //cout << "\n�������� ��������� ��� Pair:" << endl;
    //cout << "p1 == p2: " << (p1 == p2 ? "���" : "�") << endl;
    //cout << "p1 != p2: " << (p1 != p2 ? "���" : "�") << endl;
    //cout << "p1 < p2: " << (p1 < p2 ? "���" : "�") << endl;
    //cout << "p1 > p2: " << (p1 > p2 ? "���" : "�") << endl;
    //cout << "p1 <= p2: " << (p1 <= p2 ? "���" : "�") << endl;
    //cout << "p1 >= p2: " << (p1 >= p2 ? "���" : "�") << endl;
    //cout << "\n=== ���������� ����� Fraction ===" << endl;

    long whole1, whole2;
    unsigned short frac1, frac2;

    cout << "Enter first fraction (whole part and fractional part): ";
    cin >> whole1 >> frac1;
    Fraction f1(whole1, frac1);

    cout << "Enter second fraction (whole part and fractional part): ";
    cin >> whole2 >> frac2;
    Fraction f2(whole2, frac2);

    Fraction result = f1 - f2;
    cout << "Result of subtraction: " << string(result) << endl;

    cout << "Incrementing first fraction: " << string(++f1) << endl;
    cout << "Decrementing second fraction: " << string(--f2) << endl;

    return 0;
}