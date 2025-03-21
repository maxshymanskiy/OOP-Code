#include "BaseFraction.h"
#include "PublicFraction.h"
#include "PrivateFraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    /*cout << "===== Тестування класу BaseFraction =====" << endl;
    BaseFraction bf1;
    BaseFraction bf2(123, 45678);
    cout << "bf1 (без параметрів): " << bf1 << endl;
    cout << "bf2 (з параметрами): " << bf2 << endl;

    BaseFraction bf3 = bf2;
    BaseFraction bf4;
    bf4 = bf2;
    cout << "bf3 (копія bf2): " << bf3 << endl;
    cout << "bf4 (присвоєно bf2): " << bf4 << endl;

    cout << "\n===== Тестування класу PublicFraction =====" << endl;
    PublicFraction pf1;
    PublicFraction pf2(123, 45678);
    cout << "pf1 (без параметрів): " << pf1 << endl;
    cout << "pf2 (з параметрами): " << pf2 << endl;*/

    cout << "Введіть перший дріб:" << endl;
    PublicFraction a;
    cin >> a;
    cout << "Введіть другий дріб:" << endl;
    PublicFraction b;
    cin >> b;
    cout << "Перший дріб: " << a << endl;
    cout << "Другий дріб: " << b << endl;

    cout << "\nОперації порівняння:" << endl;
    cout << "a == b: " << (a == b ? "істина" : "хибність") << endl;
    cout << "a != b: " << (a != b ? "істина" : "хибність") << endl;
    cout << "a < b: " << (a < b ? "істина" : "хибність") << endl;
    cout << "a > b: " << (a > b ? "істина" : "хибність") << endl;

    PublicFraction c = a - b;
    cout << "Віднімання(a, b): " << c << endl;

    cout << "\nТестування інкременту і декременту:" << endl;
    cout << "a початкове: " << a << endl;
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

    /*cout << "\n===== Тестування класу PrivateFraction =====" << endl;
    PrivateFraction pvf1;
    PrivateFraction pvf2(123, 45678);
    cout << "pvf1 (без параметрів): " << pvf1 << endl;
    cout << "pvf2 (з параметрами): " << pvf2 << endl;

    cout << "\nВведіть перший приватний дріб:" << endl;
    PrivateFraction pa;
    cin >> pa;
    cout << "Введіть другий приватний дріб:" << endl;
    PrivateFraction pb;
    cin >> pb;
    cout << "Перший приватний дріб: " << pa << endl;
    cout << "Другий приватний дріб: " << pb << endl;

    cout << "\nОперації порівняння:" << endl;
    cout << "pa == pb: " << (pa == pb ? "істина" : "хибність") << endl;
    cout << "pa != pb: " << (pa != pb ? "істина" : "хибність") << endl;
    cout << "pa < pb: " << (pa < pb ? "істина" : "хибність") << endl;
    cout << "pa > pb: " << (pa > pb ? "істина" : "хибність") << endl;*/

    //PrivateFraction pc = pa - pb;
    //cout << "Віднімання(pa, pb): " << pc << endl;

    //cout << "\nТестування інкременту і декременту:" << endl;
    //cout << "pa початкове: " << pa << endl;
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