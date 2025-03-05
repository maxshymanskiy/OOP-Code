#include "BigInteger.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    BigInteger num1, num2;

    cout << "≤н≥ц≥ал≥зац≥€ першого числа:\n";
    num1.Read();

    cout << "≤н≥ц≥ал≥зац≥€ другого числа:\n";
    num2.Read();

    cout << "\n¬веден≥ числа:\n";
    cout << "ѕерше число: ";
    num1.Display();
    cout << "ƒруге число: ";
    num2.Display();

    cout << "\n–езультат перев≥рки:\n";
    if (num1 == num2)
        cout << "„исла р≥вн≥\n";
    else if (num1 < num2)
        cout << "„исло 1 менше за 2.\n";
    else
        cout << "„исло 1 б≥льше за 2.\n";

    return 0;
}