#include "Fraction.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // ���������� ������� ������ ��������� ��������
    // 1. ����������� ������� (�� ����� invalid_argument)
    try {
        cout << "���� 1: ��������� ��'���� � ������� ������� �������� ��������" << endl;
        Fraction f1(10, 100000); // ������� std::invalid_argument
        cout << "f1: " << f1 << endl;
    }
    catch (const std::invalid_argument& e) {
        cout << "³�������� std::invalid_argument: " << e.what() << endl;
    }

    // 2. �������-������� (�������� �� ���������)
    try {
        cout << "\n���� 2: ³������� � ������������� (�������� �� ���������)" << endl;
        Fraction f1(10000, 12345);
        Fraction f2(-100, 0);
        Fraction result = f1 - f2; // ������� FractionOverflowException
        cout << "���������: " << result << endl;
    }
    catch (const FractionOverflowException& e) {
        cout << "³�������� FractionOverflowException (�� ���������): " << e.what() << endl;
    }

    // 3. ������� ������� � ������������� (�������� �� ����������)
    try {
        cout << "\n���� 3: ³������� � ������������� ���� (�������� �� ����������)" << endl;
        Fraction f1(10000, 12345);
        Fraction f2(100, 0);
        Fraction result = f1 - f2; // ������� FractionCustomException
        cout << "���������: " << result << endl;
    }
    catch (const FractionCustomException& e) {
        cout << "³�������� FractionCustomException (�� ����������): " << e.what() << endl;
    }

    // 4. ������� ������� ��� ������������ (�������� �� ����������)
    try {
        cout << "\n���� 4: ³������� � �������� ������� (�������� �� ����������)" << endl;
        Fraction f1(1, 0);
        Fraction f2(0, 99999);
        Fraction result = f1 - f2; // ������� FractionException*
        cout << "���������: " << result << endl;
    }
    catch (FractionException* e) {
        cout << "³�������� FractionException (�� ����������): " << e->getMessage() << endl;
        delete e; // ������� �������� ���'���
    }

    // 5. ���������� ���������� � ��������
    try {
        cout << "\n���� 5: ��������� � �������������" << endl;
        Fraction f = Fraction(10000, 0);
        cout << "�� ����������: " << f << endl;
        ++f; // ������� FractionOverflowException
        cout << "ϳ��� ����������: " << f << endl;
    }
    catch (const FractionOverflowException& e) {
        cout << "³�������� FractionOverflowException ��� ���������: " << e.what() << endl;
    }

    // ��������� �������� � ������
    cout << "\n=== ������ � ������ Fraction ===" << endl;

    try {
        // ��������� ��'����
        Fraction f1;                     // ����������� ��� ���������
        Fraction f2(123, 45678);         // ����������� � �����������
        cout << "f1 (��� ���������): " << f1 << endl;
        cout << "f2 (� �����������): " << f2 << endl;

        // �������� � ���������
        cout << "\n������ ����� �������:" << endl;
        Fraction a;
        try {
            cin >> a;
        }
        catch (const std::invalid_argument& e) {
            cout << "������� ��������: " << e.what() << endl;
            a = Fraction(0, 0); // �������� �� �������������
        }

        cout << "������ ����� �������:" << endl;
        Fraction b;
        try {
            cin >> b;
        }
        catch (const std::invalid_argument& e) {
            cout << "������� ��������: " << e.what() << endl;
            b = Fraction(0, 0); // �������� �� �������������
        }

        cout << "����� �������: " << a << endl;
        cout << "����� �������: " << b << endl;

        // �������� ���������
        cout << "\n�������� ���������:" << endl;
        cout << "a == b: " << (a == b ? "true" : "false") << endl;
        cout << "a != b: " << (a != b ? "true" : "false") << endl;
        cout << "a < b: " << (a < b ? "true" : "false") << endl;
        cout << "a > b: " << (a > b ? "true" : "false") << endl;
        cout << "a <= b: " << (a <= b ? "true" : "false") << endl;
        cout << "a >= b: " << (a >= b ? "true" : "false") << endl;

        // �������� �������� � �������� �������
        cout << "\n�������� ��������:" << endl;
        try {
            Fraction c = a - b;
            cout << "a - b = " << c << endl;
        }
        catch (const FractionOverflowException& e) {
            cout << "������� ��������: " << e.what() << endl;
        }
        catch (const FractionCustomException& e) {
            cout << "������� ��������: " << e.what() << endl;
        }
        catch (FractionException* e) {
            cout << "������� ��������: " << e->getMessage() << endl;
            delete e; // ������� �������� ���'���
        }

        // ���������/���������
        cout << "\n������������ ���������� � ����������:" << endl;
        cout << "a ���������: " << a << endl;

        try {
            Fraction temp = ++a;
            cout << "temp = ++a: " << endl;
            cout << "a = " << a << ", temp = " << temp << endl;

            temp = a++;
            cout << "temp = a++: " << endl;
            cout << "a = " << a << ", temp = " << temp << endl;

            temp = --a;
            cout << "temp = --a: " << endl;
            cout << "a = " << a << ", temp = " << temp << endl;

            temp = a--;
            cout << "temp = a--: " << endl;
            cout << "a = " << a << ", temp = " << temp << endl;
        }
        catch (const FractionOverflowException& e) {
            cout << "������� ��� �������� ����������: " << e.what() << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "����������� �������: " << e.what() << endl;
    }
    catch (FractionException* e) {
        cout << "����������� �������: " << e->getMessage() << endl;
        delete e; // ������� �������� ���'���
    }
    catch (...) {
        cout << "����������� ������� ��������� ����!" << endl;
    }

    return 0;
}