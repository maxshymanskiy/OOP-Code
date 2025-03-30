#include "Factory.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n=== ���� ===\n";
    std::cout << "1. �������� SymString\n";
    std::cout << "2. �������� HexString\n";
    std::cout << "3. �������� ��'���\n";
    std::cout << "4. �������� �� ��'����\n";
    std::cout << "5. �������� ��������� (+)\n";
    std::cout << "6. �����\n";
    std::cout << "������� �����: ";
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
                std::cout << "������ ID: ";
                std::getline(std::cin, id);
                std::cout << "������ ��������: ";
                std::getline(std::cin, value);
                factory.createSymString(id, value);
                std::cout << "��'��� ��������.\n";
                break;
            }
            case 2: {
                std::cout << "������ ID: ";
                std::getline(std::cin, id);
                std::cout << "������ �������������� ��������: ";
                std::getline(std::cin, value);
                factory.createHexString(id, value);
                std::cout << "��'��� ��������.\n";
                break;
            }
            case 3: {
                std::cout << "������ ID ��'����: ";
                std::getline(std::cin, id);
                if (factory.deleteObject(id)) {
                    std::cout << "��'��� ��������.\n";
                }
                else {
                    std::cout << "��'��� �� ��������.\n";
                }
                break;
            }
            case 4: {
                factory.showAllObjects();
                break;
            }
            case 5: {
                std::cout << "������ ID ������� ��'����: ";
                std::getline(std::cin, id1);
                std::cout << "������ ID ������� ��'����: ";
                std::getline(std::cin, id2);

                SymString* obj1 = factory.findObject(id1);
                SymString* obj2 = factory.findObject(id2);

                if (obj1 && obj2) {
                    if (dynamic_cast<HexString*>(obj1) && dynamic_cast<HexString*>(obj2)) {
                        HexString result = *static_cast<HexString*>(obj1) + *static_cast<HexString*>(obj2);
                        std::cout << "��������� ���������: " << result.getValue() << "\n";
                    }
                    else {
                        SymString result = *obj1 + *obj2;
                        std::cout << "��������� ������������: " << result.getValue() << "\n";
                    }
                }
                else {
                    std::cout << "���� � ��'���� �� ��������.\n";
                }
                break;
            }
            case 6: {
                std::cout << "���������� ������...\n";
                break;
            }
            default: {
                std::cout << "������� ����. ��������� �����.\n";
                break;
            }
            }
        }
        catch (const std::exception& e) {
            std::cout << "�������: " << e.what() << "\n";
        }
    } while (choice != 6);

    return 0;
}