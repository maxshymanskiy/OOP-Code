#include "BaseFraction.h"
#include "PublicFraction.h"
#include "PrivateFraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    /*cout << "===== ���������� ����� BaseFraction =====" << endl;
    BaseFraction bf1;
    BaseFraction bf2(123, 45678);
    cout << "bf1 (��� ���������): " << bf1 << endl;
    cout << "bf2 (� �����������): " << bf2 << endl;

    BaseFraction bf3 = bf2;
    BaseFraction bf4;
    bf4 = bf2;
    cout << "bf3 (���� bf2): " << bf3 << endl;
    cout << "bf4 (�������� bf2): " << bf4 << endl;

    cout << "\n===== ���������� ����� PublicFraction =====" << endl;
    PublicFraction pf1;
    PublicFraction pf2(123, 45678);
    cout << "pf1 (��� ���������): " << pf1 << endl;
    cout << "pf2 (� �����������): " << pf2 << endl;*/

    cout << "������ ������ ���:" << endl;
    PublicFraction a;
    cin >> a;
    cout << "������ ������ ���:" << endl;
    PublicFraction b;
    cin >> b;
    cout << "������ ���: " << a << endl;
    cout << "������ ���: " << b << endl;

    cout << "\n�������� ���������:" << endl;
    cout << "a == b: " << (a == b ? "������" : "�������") << endl;
    cout << "a != b: " << (a != b ? "������" : "�������") << endl;
    cout << "a < b: " << (a < b ? "������" : "�������") << endl;
    cout << "a > b: " << (a > b ? "������" : "�������") << endl;

    PublicFraction c = a - b;
    cout << "³�������(a, b): " << c << endl;

    cout << "\n���������� ���������� � ����������:" << endl;
    cout << "a ���������: " << a << endl;
    PublicFraction temp;
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

    /*cout << "\n===== ���������� ����� PrivateFraction =====" << endl;
    PrivateFraction pvf1;
    PrivateFraction pvf2(123, 45678);
    cout << "pvf1 (��� ���������): " << pvf1 << endl;
    cout << "pvf2 (� �����������): " << pvf2 << endl;

    cout << "\n������ ������ ��������� ���:" << endl;
    PrivateFraction pa;
    cin >> pa;
    cout << "������ ������ ��������� ���:" << endl;
    PrivateFraction pb;
    cin >> pb;
    cout << "������ ��������� ���: " << pa << endl;
    cout << "������ ��������� ���: " << pb << endl;

    cout << "\n�������� ���������:" << endl;
    cout << "pa == pb: " << (pa == pb ? "������" : "�������") << endl;
    cout << "pa != pb: " << (pa != pb ? "������" : "�������") << endl;
    cout << "pa < pb: " << (pa < pb ? "������" : "�������") << endl;
    cout << "pa > pb: " << (pa > pb ? "������" : "�������") << endl;*/

    //PrivateFraction pc = pa - pb;
    //cout << "³�������(pa, pb): " << pc << endl;

    //cout << "\n���������� ���������� � ����������:" << endl;
    //cout << "pa ���������: " << pa << endl;
    //PrivateFraction ptemp;
    //ptemp = ++pa;
    //cout << "ptemp = ++pa: " << endl;
    //cout << "pa = " << pa << ", ptemp = " << ptemp << endl;
    //ptemp = --pa;
    //cout << "ptemp = --pa: " << endl;
    //cout << "pa = " << pa << ", ptemp = " << ptemp << endl;
    //ptemp = pa++;
    //cout << "ptemp = pa++: " << endl;
    //cout << "pa = " << pa << ", ptemp = " << ptemp << endl;
    //ptemp = pa--;
    //cout << "ptemp = pa--: " << endl;
    //cout << "pa = " << pa << ", ptemp = " << ptemp << endl;

    return 0;
}