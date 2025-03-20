#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Початкова кількість об'єктів: " << Object::getCounter() << endl;

    {
        Fraction f1;
        cout << "Після створення f1, кількість об'єктів: " << Object::getCounter() << endl;

        Fraction f2(123, 45678);
        cout << "Після створення f2, кількість об'єктів: " << Object::getCounter() << endl;

        cout << "f1 (за замовчуванням): " << f1 << endl;
        cout << "f2 (ініціалізований): " << f2 << endl;

        Fraction f3 = f2;
        cout << "Після створення f3, кількість об'єктів: " << Object::getCounter() << endl;

        Fraction f4;
        f4 = f2;
        cout << "Після створення f4, кількість об'єктів: " << Object::getCounter() << endl;

        cout << "f3 (копія f2): " << f3 << endl;
        cout << "f4 (присвоєно f2): " << f4 << endl;

        cout << "\nВведіть перший дріб:" << endl;
        Fraction a;
        cin >> a;
        cout << "Введіть другий дріб:" << endl;
        Fraction b;
        cin >> b;
        cout << "Перший дріб: " << a << endl;
        cout << "Другий дріб: " << b << endl;

        cout << "\nОперації порівняння:" << endl;
        cout << "a == b: " << (a == b ? "істина" : "хибно") << endl;
        cout << "a != b: " << (a != b ? "істина" : "хибно") << endl;
        cout << "a < b: " << (a < b ? "істина" : "хибно") << endl;
        cout << "a > b: " << (a > b ? "істина" : "хибно") << endl;

        Fraction c = a - b;
        cout << "Віднімання(a, b): " << c << endl;

        cout << "\nДемонстрація префіксних та постфіксних операцій:" << endl;
        cout << "a спочатку: " << a << endl;

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

        cout << "Поточна кількість об'єктів: " << Object::getCounter() << endl;
    }

    cout << "Після знищення всіх локальних дробів, кількість об'єктів: " << Object::getCounter() << endl;

    return 0;
}