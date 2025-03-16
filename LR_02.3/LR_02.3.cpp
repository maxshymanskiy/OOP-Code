#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Демонстрація створення об'єктів
    Fraction f1;
    Fraction f2(123, 45678);
    cout << "f1 (без аргументів): " << f1 << endl;
    cout << "f2 (з параметрами): " << f2 << endl;

    // Конструктор копіювання та присвоєння
    Fraction f3 = f2;
    Fraction f4;
    f4 = f2;
    cout << "f3 (копія f2): " << f3 << endl;
    cout << "f4 (присвоєно f2): " << f4 << endl;

    // Введення двох значень
    cout << "\nВведіть перше значення:" << endl;
    Fraction a;
    cin >> a;

    cout << "Введіть друге значення:" << endl;
    Fraction b;
    cin >> b;

    cout << "Перше значення: " << a << endl;
    cout << "Друге значення: " << b << endl;

    // Демонстрація порівняння та віднімання
    cout << "\nОперації порівняння:" << endl;
    cout << "a == b: " << (a == b ? "true" : "false") << endl;
    cout << "a != b: " << (a != b ? "true" : "false") << endl;
    cout << "a < b: " << (a < b ? "true" : "false") << endl;
    cout << "a > b: " << (a > b ? "true" : "false") << endl;

    Fraction c = Subtract(a, b);
    cout << "Subtract(a, b): " << c << endl;

    // Демонстрація інкрементів та декрементів
    cout << "\nДемонстрація інкрементів і декрементів:" << endl;
    cout << "a початкове: " << a << endl;

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

    return 0;
}