#include "BigInteger.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    BigInteger num1, num2;

    cout << "Перша цифра:\n";
    num1.Read();

    cout << "Друга цифра:\n";
    num2.Read();

    cout << "\nПерше число: ";
    num1.Display();
    cout << "Друге число: ";
    num2.Display();

    cout << "\nРезультат перевірки:\n";
    if (num1 == num2)
        cout << "Числа рівні\n";
    else if (num1 < num2)
        cout << "Чмсло 1 менше за 2.\n";
    else
        cout << "Число 1 більше за 2.\n";

    return 0;
}