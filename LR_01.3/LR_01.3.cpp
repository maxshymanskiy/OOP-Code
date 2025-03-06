#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Fraction f1, f2;

    cout << "Enter data for Fraction 1:\n";
    f1.Read();

    cout << "Enter data for Fraction 2:\n";
    f2.Read();

    cout << "Fraction 1: ";
    f1.Display();
    cout << "Fraction 2: ";
    f2.Display();

    Fraction result = Subtract(f1, f2);
    cout << "Result of subtraction: ";
    result.Display();

    cout << "\nComparison Results:\n";

    if (f1 == f2) {
        cout << "Fraction 1 is equal to Fraction 2 (==).\n";
    }
    else {
        cout << "Fraction 1 is not equal to Fraction 2 (!=).\n";
    }

    if (f1 != f2) {
        cout << "Fraction 1 is not equal to Fraction 2 (!=).\n";
    }

    if (f1 < f2) {
        cout << "Fraction 1 is less than Fraction 2 (<).\n";
    }

    if (f1 > f2) {
        cout << "Fraction 1 is greater than Fraction 2 (>).\n";
    }

    if (f1 <= f2) {
        cout << "Fraction 1 is less than or equal to Fraction 2 (<=).\n";
    }

    if (f1 >= f2) {
        cout << "Fraction 1 is greater than or equal to Fraction 2 (>=).\n";
    }

    return 0;
}