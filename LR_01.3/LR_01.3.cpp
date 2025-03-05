#include "Fraction.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() 
{

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Fraction a, b;

    cout << "=== ¬веденн€ першого дробу ===\n";
    a.Read();

    cout << "\n=== ¬веденн€ другого дробу ===\n";
    b.Read();

    cout << "\n–езультати:\n";
    cout << "ƒр≥б 1: " << a.toString() << endl;
    cout << "ƒр≥б 2: " << b.toString() << endl;

    Fraction c = a.Subtract(b);
    cout << "–≥зниц€: " << c.toString() << endl;

    if (a == b) cout << "ƒроби р≥вн≥\n";
    else if (a < b) cout << "ƒр≥б 1 менший\n";
    else cout << "ƒр≥б 1 б≥льший\n";

    return 0;
}