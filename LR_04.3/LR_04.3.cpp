#include <iostream>
#include "Array.h"
#include "Money.h"
#include "String.h"
#include <typeinfo>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Array* sum1 = new Money(4);  // Максимум 4 цифри
    Array* sum2 = new Money(5);  // Максимум 5 цифр

    dynamic_cast<Money*>(sum1)->setDigits("1275");  // 12 грн 75 коп.
    dynamic_cast<Money*>(sum2)->setDigits("9550");  // 85 грн 50 коп.

    cout << "Тип: " << typeid(*sum1).name() << "\n";
    cout << "Сума 1: " << *dynamic_cast<Money*>(sum1) << "\n";

    cout << "Тип: " << typeid(*sum2).name() << "\n";
    cout << "Сума 2: " << *dynamic_cast<Money*>(sum2) << "\n";

    Array* totalSum = sum1->add(*sum2);
    cout << "Тип: " << typeid(*totalSum).name() << "\n";
    cout << "Сума 1 + Сума 2: " << *dynamic_cast<Money*>(totalSum) << "\n\n";

    Array* str1 = new String("Hello", 10);  // Рядок з максимальною довжиною 10
    Array* str2 = new String("World", 10);  // Рядок з максимальною довжиною 10

    cout << "Тип: " << typeid(*str1).name() << "\n";
    cout << "Рядок 1: " << *dynamic_cast<String*>(str1) << "\n";
    cout << "Довжина: " << dynamic_cast<String*>(str1)->length() << "\n\n";

    cout << "Тип: " << typeid(*str2).name() << "\n";
    cout << "Рядок 2: " << *dynamic_cast<String*>(str2) << "\n";
    cout << "Довжина: " << dynamic_cast<String*>(str2)->length() << "\n\n";

    Array* concatStr = str1->add(*str2);
    cout << "Тип: " << typeid(*concatStr).name() << "\n";
    cout << "Рядок 1 + Рядок 2: " << *dynamic_cast<String*>(concatStr) << "\n";
    cout << "Довжина: " << dynamic_cast<String*>(concatStr)->length() << "\n\n";

    cout << "Пошук 'or' у '" << *dynamic_cast<String*>(str2) << "': "
        << dynamic_cast<String*>(str2)->find("or") << "\n";

    dynamic_cast<String*>(str1)->insert(5, " beautiful");  // Вставка "beautiful"
    cout << "Після вставки: " << *dynamic_cast<String*>(str1) << "\n";

    dynamic_cast<String*>(str1)->remove(6, 9); // Видалення "beautiful"
    cout << "Після видалення: " << *dynamic_cast<String*>(str1) << "\n\n";

    delete sum1;
    delete sum2;
    delete totalSum;
    delete str1;
    delete str2;
    delete concatStr;

    return 0;
}


// TO-DO:

/*
1) Зробити підрядок і операцію видалення для неї в класі String;
2) Зрозуміти як працює перенесення чисел в роздярі Money при ввденні 9750+1275. Тобто як 
створюються поля в масиві;
3) Переробити insert та remove в класі String так, щоб вони були для підрядка;
4) 
*/