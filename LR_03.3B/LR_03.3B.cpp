#include "Fraction.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "=== Тестування класу Pair ===" << endl;

    cout << "Введіть значення для пари p1 (формат: перше друге):" << endl;
    Pair p1;
    cin >> p1;
    cout << "p1: " << p1 << endl;

    cout << "Введіть значення для пари p2 (формат: перше друге):" << endl;
    Pair p2;
    cin >> p2;
    cout << "p2: " << p2 << endl;

    cout << "\nОперації порівняння для Pair:" << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "так" : "ні") << endl;
    cout << "p1 != p2: " << (p1 != p2 ? "так" : "ні") << endl;
    cout << "p1 < p2: " << (p1 < p2 ? "так" : "ні") << endl;
    cout << "p1 > p2: " << (p1 > p2 ? "так" : "ні") << endl;
    cout << "p1 <= p2: " << (p1 <= p2 ? "так" : "ні") << endl;
    cout << "p1 >= p2: " << (p1 >= p2 ? "так" : "ні") << endl;

    cout << "\n=== Тестування класу Fraction ===" << endl;

    cout << "Введіть перший дріб:" << endl;
    Fraction a;
    cout << "Введіть цілу частину: ";
    long whole;
    cin >> whole;
    a.setWhole(whole);

    cout << "Введіть дробову частину (до 5 цифр): ";
    unsigned short frac;
    cin >> frac;
    a.setFractional(frac);

    cout << "Введіть другий дріб:" << endl;
    Fraction b;
    cout << "Введіть цілу частину: ";
    cin >> whole;
    b.setWhole(whole);

    cout << "Введіть дробову частину (до 5 цифр): ";
    cin >> frac;
    b.setFractional(frac);

    cout << "Перший дріб: " << a.getWhole() << "." << a.getFractional() << endl;
    cout << "Другий дріб: " << b.getWhole() << "." << b.getFractional() << endl;

    cout << "\nОперації порівняння для Fraction:" << endl;
    cout << "a == b: " << (a == b ? "так" : "ні") << endl;
    cout << "a != b: " << (a != b ? "так" : "ні") << endl;
    cout << "a < b: " << (a < b ? "так" : "ні") << endl;
    cout << "a > b: " << (a > b ? "так" : "ні") << endl;

    Fraction c = a - b;
    cout << "Результат віднімання (a - b): " << c.getWhole() << "." << c.getFractional() << endl;

    cout << "\nТестування інкременту та декременту:" << endl;
    cout << "Початкове значення a: " << a.getWhole() << "." << a.getFractional() << endl;

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