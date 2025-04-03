//#include <iostream>
//#include "Array.h"
//#include "Money.h"
//#include "String.h"
//#include <Windows.h>
//
//int main() {
//	SetConsoleOutputCP(1251); 
//	SetConsoleCP(1251);
//	// Демонстрація Array
//    Money m1, m2;
//    std::cout << "Введіть суму m1: ";
//    std::cin >> m1;
//    std::cout << "Введіть суму m2: ";
//    std::cin >> m2;
//
//    Array* resultMoney = m1.add(m2);
//    std::cout << "Результат додавання: " << *dynamic_cast<Money*>(resultMoney) << std::endl;
//
//    // Демонстрація String
//    String s1("Hello, ", 10), s2("World!", 10);
//    Array* resultString = s1.add(s2);
//    std::cout << "Результат конкатенації: " << *dynamic_cast<String*>(resultString) << std::endl;
//
//    delete resultMoney;
//    delete resultString;
//    return 0;
//}


#include <iostream>
#include "Money.h"
#include "String.h"
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    std::cout << "=== Тестування класу Money ===" << std::endl;

    // 1. Створення грошових сум
    Money m1(100);  // 3 цифри гривень + 2 копійки
    Money m2(100);

    // 2. Введення даних
    std::cout << "Введіть першу суму (100 цифр, наприклад 12345): ";
    std::cin >> m1;  // 12345 → 123 грн 45 коп

    std::cout << "Введіть другу суму (100 цифр, наприклад 67890): ";
    std::cin >> m2;  // 67890 → 678 грн 90 коп

    // 3. Додавання сум
    Money* moneyResult = m1.add(m2);
    std::cout << "Результат додавання: " << *moneyResult << std::endl;
    delete moneyResult;

    // Очистка буфера вводу
    std::cin.ignore();

    std::cout << "\n=== Тестування класу String ===" << std::endl;

    // 1. Створення рядка
    String s("Hello", 10);  // Макс. довжина 10 символів
    std::cout << "Початковий рядок: " << s << std::endl;

    // 2. Пошук підрядка
    int pos = s.find("ell");
    std::cout << "Підрядок 'ell' на позиції: " << pos << std::endl;

    // 3. Видалення підрядка
    s.remove(1, 3);  // Видаляє "ell"
    std::cout << "Після видалення: " << s << std::endl;

    // 4. Вставка підрядка
    s.insert(1, "ola");  // Вставляє "ola" на позицію 1
    std::cout << "Після вставки: " << s << std::endl;

    // 5. Введення нового рядка
    String s2(15);
    std::cout << "Введіть новий рядок (до 15 символів): ";
    std::cin >> s2;
    std::cout << "Ви ввели: " << s2 << std::endl;

    return 0;
}