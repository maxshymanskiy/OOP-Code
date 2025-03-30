#include <iostream>
#include <Windows.h>
#include "B1.h"
#include "B2.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "D4.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    B1 b1(10);
    B2 b2(20);
    D1 d1(30, 40, 50);
    D2 d2(60, 70, 80, 90);
    D3 d3(100, 110, 120, 130, 140);
    D4 d4(150, 160, 170, 180, 190);

    std::cout << "Розмір B1: " << sizeof(B1) << std::endl;
    b1.show();

    std::cout << "\nРозмір B2: " << sizeof(B2) << std::endl;
    b2.show();

    std::cout << "\nРозмір D1: " << sizeof(D1) << std::endl;
    d1.show();

    std::cout << "\nРозмір D2: " << sizeof(D2) << std::endl;
    d2.show();

    std::cout << "\nРозмір D3: " << sizeof(D3) << std::endl;
    d3.show();

    std::cout << "\nРозмір D4: " << sizeof(D4) << std::endl;
    d4.show();

    return 0;
}