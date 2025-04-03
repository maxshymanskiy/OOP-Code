#include <iostream>
#include "Array.h"
#include "Money.h"
#include "String.h"
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	// ������������ Array
    Money m1, m2;
    std::cout << "������ ���� m1: ";
    std::cin >> m1;
    std::cout << "������ ���� m2: ";
    std::cin >> m2;

    Array* resultMoney = m1.add(m2);
    std::cout << "��������� ���������: " << *dynamic_cast<Money*>(resultMoney) << std::endl;

    // ������������ String
    String s1("Hello, ", 10), s2("World!", 10);
    Array* resultString = s1.add(s2);
    std::cout << "��������� ������������: " << *dynamic_cast<String*>(resultString) << std::endl;

    delete resultMoney;
    delete resultString;
    return 0;
}