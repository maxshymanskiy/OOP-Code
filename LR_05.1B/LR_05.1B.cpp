#include "Fraction.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Тестування винятків трьома способами передачі
    // 1. Стандартний виняток (на основі invalid_argument)
    try {
        cout << "Тест 1: Створення об'єкта з занадто великою дробовою частиною" << endl;
        Fraction f1(10, 100000); // Викличе std::invalid_argument
        cout << "f1: " << f1 << endl;
    }
    catch (const std::invalid_argument& e) {
        cout << "Відловлено std::invalid_argument: " << e.what() << endl;
    }

    // 2. Виняток-нащадок (передача за значенням)
    try {
        cout << "\nТест 2: Віднімання з переповненням (передача за значенням)" << endl;
        Fraction f1(10000, 12345);
        Fraction f2(-100, 0);
        Fraction result = f1 - f2; // Викличе FractionOverflowException
        cout << "Результат: " << result << endl;
    }
    catch (const FractionOverflowException& e) {
        cout << "Відловлено FractionOverflowException (за значенням): " << e.what() << endl;
    }

    // 3. Власний виняток з успадкуванням (передача за посиланням)
    try {
        cout << "\nТест 3: Віднімання з переповненням вниз (передача за посиланням)" << endl;
        Fraction f1(10000, 12345);
        Fraction f2(100, 0);
        Fraction result = f1 - f2; // Викличе FractionCustomException
        cout << "Результат: " << result << endl;
    }
    catch (const FractionCustomException& e) {
        cout << "Відловлено FractionCustomException (за посиланням): " << e.what() << endl;
    }

    // 4. Власний виняток без успадкування (передача за вказівником)
    try {
        cout << "\nТест 4: Віднімання з помилкою точності (передача за вказівником)" << endl;
        Fraction f1(1, 0);
        Fraction f2(0, 99999);
        Fraction result = f1 - f2; // Викличе FractionException*
        cout << "Результат: " << result << endl;
    }
    catch (FractionException* e) {
        cout << "Відловлено FractionException (за вказівником): " << e->getMessage() << endl;
        delete e; // Важливо звільнити пам'ять
    }

    // 5. Тестування інкременту з винятком
    try {
        cout << "\nТест 5: Інкремент з переповненням" << endl;
        Fraction f = Fraction(10000, 0);
        cout << "До інкременту: " << f << endl;
        ++f; // Викличе FractionOverflowException
        cout << "Після інкременту: " << f << endl;
    }
    catch (const FractionOverflowException& e) {
        cout << "Відловлено FractionOverflowException при інкременті: " << e.what() << endl;
    }

    // Стандартні операції з класом
    cout << "\n=== Робота з класом Fraction ===" << endl;

    try {
        // Створення об'єктів
        Fraction f1;                     // Конструктор без параметрів
        Fraction f2(123, 45678);         // Конструктор з параметрами
        cout << "f1 (без параметрів): " << f1 << endl;
        cout << "f2 (з параметрами): " << f2 << endl;

        // Введення з клавіатури
        cout << "\nВведіть першу фракцію:" << endl;
        Fraction a;
        try {
            cin >> a;
        }
        catch (const std::invalid_argument& e) {
            cout << "Помилка введення: " << e.what() << endl;
            a = Fraction(0, 0); // Значення за замовчуванням
        }

        cout << "Введіть другу фракцію:" << endl;
        Fraction b;
        try {
            cin >> b;
        }
        catch (const std::invalid_argument& e) {
            cout << "Помилка введення: " << e.what() << endl;
            b = Fraction(0, 0); // Значення за замовчуванням
        }

        cout << "Перша фракція: " << a << endl;
        cout << "Друга фракція: " << b << endl;

        // Операції порівняння
        cout << "\nОперації порівняння:" << endl;
        cout << "a == b: " << (a == b ? "true" : "false") << endl;
        cout << "a != b: " << (a != b ? "true" : "false") << endl;
        cout << "a < b: " << (a < b ? "true" : "false") << endl;
        cout << "a > b: " << (a > b ? "true" : "false") << endl;
        cout << "a <= b: " << (a <= b ? "true" : "false") << endl;
        cout << "a >= b: " << (a >= b ? "true" : "false") << endl;

        // Операція віднімання з обробкою винятків
        cout << "\nОперація віднімання:" << endl;
        try {
            Fraction c = a - b;
            cout << "a - b = " << c << endl;
        }
        catch (const FractionOverflowException& e) {
            cout << "Помилка віднімання: " << e.what() << endl;
        }
        catch (const FractionCustomException& e) {
            cout << "Помилка віднімання: " << e.what() << endl;
        }
        catch (FractionException* e) {
            cout << "Помилка віднімання: " << e->getMessage() << endl;
            delete e; // Важливо звільнити пам'ять
        }

        // Інкремент/декремент
        cout << "\nДемонстрація інкременту і декременту:" << endl;
        cout << "a початкове: " << a << endl;

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
            cout << "Помилка при операції інкременту: " << e.what() << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Невідловлена помилка: " << e.what() << endl;
    }
    catch (FractionException* e) {
        cout << "Невідловлена помилка: " << e->getMessage() << endl;
        delete e; // Важливо звільнити пам'ять
    }
    catch (...) {
        cout << "Невідловлена помилка невідомого типу!" << endl;
    }

    return 0;
}