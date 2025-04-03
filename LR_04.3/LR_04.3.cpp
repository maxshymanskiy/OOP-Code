#include <iostream>
#include "Array.h"
#include "Money.h"
#include "String.h"
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	// Демонстрація Array
    Money m1, m2;
    std::cout << "Введіть суму m1: ";
    std::cin >> m1;
    std::cout << "Введіть суму m2: ";
    std::cin >> m2;

    Array* resultMoney = m1.add(m2);
    std::cout << "Результат додавання: " << *dynamic_cast<Money*>(resultMoney) << std::endl;

    // Демонстрація String
    String s1("Hello, ", 10), s2("World!", 10);
    Array* resultString = s1.add(s2);
    std::cout << "Результат конкатенації: " << *dynamic_cast<String*>(resultString) << std::endl;

    delete resultMoney;
    delete resultString;
    return 0;
}