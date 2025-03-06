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

    cout << "\n–езультати пор≥вн€нь:\n";

    if (num1 == num2) {
        cout << "„исла р≥вн≥ (==)\n";
    }
    else {
        cout << "„исла не р≥вн≥ (!=)\n";

        if (num1 < num2) {
            cout << "ѕерше число менше за друге (<)\n";
        }
        else {
            cout << "ѕерше число б≥льше за друге (>)\n";
        }
    }

    return 0;
}