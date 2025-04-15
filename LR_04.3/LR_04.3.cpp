
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

    cout << "ДЕМОНСТРАЦІЯ РОБОТИ ПРОГРАМИ" << endl;
    cout << "============================" << endl;

    Array* sum1 = new Money(4);  // Максимум 4 цифри
    Array* sum2 = new Money(5);  // Максимум 5 цифр

    dynamic_cast<Money*>(sum1)->setDigits("1275");  // 12 грн 75 коп.
    dynamic_cast<Money*>(sum2)->setDigits("9550");  // 95 грн 50 коп.

    cout << "Тип: " << typeid(*sum1).name() << endl;
    cout << "Сума 1: " << *dynamic_cast<Money*>(sum1) << endl;

    cout << "Тип: " << typeid(*sum2).name() << endl;
    cout << "Сума 2: " << *dynamic_cast<Money*>(sum2) << endl;

    Array* totalSum = sum1->add(*sum2);
    cout << "Тип: " << typeid(*totalSum).name() << endl;
    cout << "Сума 1 + Сума 2: " << *dynamic_cast<Money*>(totalSum) << endl << endl;

    Array* str1 = new String("Hello", 20);  // Рядок з максимальною довжиною 20
    Array* str2 = new String("World", 20);  // Рядок з максимальною довжиною 20

    cout << "Тип: " << typeid(*str1).name() << endl;
    cout << "Рядок 1: " << *dynamic_cast<String*>(str1) << endl;
    cout << "Довжина: " << dynamic_cast<String*>(str1)->length() << endl << endl;

    cout << "Тип: " << typeid(*str2).name() << endl;
    cout << "Рядок 2: " << *dynamic_cast<String*>(str2) << endl;
    cout << "Довжина: " << dynamic_cast<String*>(str2)->length() << endl << endl;

    Array* concatStr = str1->add(*str2);
    cout << "Тип: " << typeid(*concatStr).name() << endl;
    cout << "Рядок 1 + Рядок 2: " << *dynamic_cast<String*>(concatStr) << endl;
    cout << "Довжина: " << dynamic_cast<String*>(concatStr)->length() << endl << endl;

    cout << "Пошук 'or' у '" << *dynamic_cast<String*>(str2) << "': "
        << dynamic_cast<String*>(str2)->find("or") << endl;

    dynamic_cast<String*>(str1)->insert(5, " beautiful");
    cout << "Після вставки: " << *dynamic_cast<String*>(str1) << endl;

    dynamic_cast<String*>(str1)->remove(6, 9); // Видалення "beautiful"
    cout << "Після видалення: " << *dynamic_cast<String*>(str1) << endl;

    String* str3 = new String("Hello World", 20);
    cout << "Рядок 3: " << *str3 << endl;
    str3->removeSubstring("World");
    cout << "Після видалення 'World': " << *str3 << endl;

    String* str4 = new String("Testing substring method", 30);
    cout << "Рядок 4: " << *str4 << endl;
    String* substr = str4->substring(8, 9);
    cout << "Підрядок (8, 9): " << *substr << endl << endl;

    // Додавання з переносом (приклад з TO-DO)
    Money* sum3 = new Money(4);
    Money* sum4 = new Money(4);
    sum3->setDigits("9750");  // 97 грн 50 коп.
    sum4->setDigits("1275");  // 12 грн 75 коп.
    cout << "Сума 3: " << *sum3 << endl;
    cout << "Сума 4: " << *sum4 << endl;

    Money* totalSum2 = dynamic_cast<Money*>(sum3->add(*sum4));
    cout << "Сума 3 + Сума 4: " << *totalSum2 << endl;
    cout << "Очікувано: 110 грн 25 коп" << endl << endl;

    // Звільнення пам'яті
    delete sum1;
    delete sum2;
    delete totalSum;
    delete str1;
    delete str2;
    delete concatStr;
    delete str3;
    delete str4;
    delete substr;
    delete sum3;
    delete sum4;
    delete totalSum2;

    cout << "Програма успішно завершена!" << endl;
    return 0;
}