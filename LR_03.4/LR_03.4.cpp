#include "Factory.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Створити SymString\n";
    std::cout << "2. Створити HexString\n";
    std::cout << "3. Видалити об'єкт\n";
    std::cout << "4. Показати всі об'єкти\n";
    std::cout << "5. Виконати додавання (+)\n";
    std::cout << "6. Вийти\n";
    std::cout << "Виберіть опцію: ";
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Factory factory;
    int choice;
    std::string id, value, id1, id2;

    do {
        displayMenu();
        std::cin >> choice;
        clearInput();

        try {
            switch (choice) {
            case 1: {
                std::cout << "Введіть ID: ";
                std::getline(std::cin, id);
                std::cout << "Введіть значення: ";
                std::getline(std::cin, value);
                factory.createSymString(id, value);
                std::cout << "Об'єкт створено.\n";
                break;
            }
            case 2: {
                std::cout << "Введіть ID: ";
                std::getline(std::cin, id);
                std::cout << "Введіть шістнадцяткове значення: ";
                std::getline(std::cin, value);
                factory.createHexString(id, value);
                std::cout << "Об'єкт створено.\n";
                break;
            }
            case 3: {
                std::cout << "Введіть ID об'єкта: ";
                std::getline(std::cin, id);
                if (factory.deleteObject(id)) {
                    std::cout << "Об'єкт видалено.\n";
                }
                else {
                    std::cout << "Об'єкт не знайдено.\n";
                }
                break;
            }
            case 4: {
                factory.showAllObjects();
                break;
            }
            case 5: {
                std::cout << "Введіть ID першого об'єкта: ";
                std::getline(std::cin, id1);
                std::cout << "Введіть ID другого об'єкта: ";
                std::getline(std::cin, id2);

                SymString* obj1 = factory.findObject(id1);
                SymString* obj2 = factory.findObject(id2);

                if (obj1 && obj2) {
                    if (dynamic_cast<HexString*>(obj1) && dynamic_cast<HexString*>(obj2)) {
                        HexString result = *static_cast<HexString*>(obj1) + *static_cast<HexString*>(obj2);
                        std::cout << "Результат додавання: " << result.getValue() << "\n";
                    }
                    else {
                        SymString result = *obj1 + *obj2;
                        std::cout << "Результат конкатенації: " << result.getValue() << "\n";
                    }
                }
                else {
                    std::cout << "Один з об'єктів не знайдено.\n";
                }
                break;
            }
            case 6: {
                std::cout << "Завершення роботи...\n";
                break;
            }
            default: {
                std::cout << "Невірний вибір. Спробуйте знову.\n";
                break;
            }
            }
        }
        catch (const std::exception& e) {
            std::cout << "Помилка: " << e.what() << "\n";
        }
    } while (choice != 6);

    return 0;
}