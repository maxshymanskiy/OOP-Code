#include "array.h"
#include "book.h"
#include "bookrecord.h"
#include "debt.h"
#include "subscriber.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int getIntInput(const std::string& prompt, int min = INT_MIN, int max = INT_MAX) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore();
                return value;
            }
            std::cout << "�������: �������� �� ���� �� " << min << " � " << max << "\n";
        }
        else {
            std::cout << "�������: ������ �������� �����!\n";
            clearInputBuffer();
        }
    }
}

size_t getSizeTInput(const std::string& prompt, size_t min = 0, size_t max = SIZE_MAX) {
    size_t value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore();
                return value;
            }
            std::cout << "�������: �������� �� ���� �� " << min << " � " << max << "\n";
        }
        else {
            std::cout << "�������: ������ �������� �����!\n";
            clearInputBuffer();
        }
    }
}

std::string getDateInput(const std::string& prompt) {
    std::string date;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, date);

        if (date.length() == 10 && date[2] == '-' && date[5] == '-') {
            return date;
        }
        std::cout << "�������: ������ ���� � ������ ��-��-����\n";
    }
}

void displayMenu() {
    std::cout << "\n=== ���������� ������� ===" << std::endl;
    std::cout << "1. ������ ������ ��������" << std::endl;
    std::cout << "2. ������ ����� �� ��������" << std::endl;
    std::cout << "3. ��������� �����" << std::endl;
    std::cout << "4. �������� ��� ��������" << std::endl;
    std::cout << "5. ����� ���� �� �������" << std::endl;
    std::cout << "6. ����� ���� �� ������������" << std::endl;
    std::cout << "7. ����� ���� �� �����" << std::endl;
    std::cout << "8. �������� ����� ��������" << std::endl;
    std::cout << "9. ��'������ ������ ��������" << std::endl;
    std::cout << "10. ������ ������� ������" << std::endl;
    std::cout << "11. ������ ������ ������" << std::endl;
    std::cout << "0. �����" << std::endl;
    std::cout << "������� �����: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Subscriber> subscribers;
    std::vector<Book> allBooks = {
        Book("���� ������", "���'��� ����", 1898, "��������� ���������", 150.0),
        Book("���� �������", "˳���� ����", 1911, "�������", 180.5),
        Book("����� ��������", "������", 1840, "�����", 250.0),
        Book("������� ������������", "ҳ� ������� ������", 1912, "�������", 175.0),
        Book("����� �����������", "�����", 1902, "��������� ���������", 160.0)
    };

    int choice;
    do {
        displayMenu();
        choice = getIntInput("", 0, 11);

        switch (choice) {
        case 1: {
            Subscriber newSub;
            std::cin >> newSub;
            subscribers.push_back(newSub);
            std::cout << "�������� ������ ������!\n";
            break;
        }
        case 2: {
            if (subscribers.empty()) {
                std::cout << "�������� ������� ��������!\n";
                break;
            }

            std::cout << "������� �����:\n";
            for (size_t i = 0; i < allBooks.size(); i++) {
                std::cout << i + 1 << ". " << allBooks[i] << "\n";
            }

            size_t subIndex = getSizeTInput("������� ����� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            size_t bookIndex = getSizeTInput("������� ����� ����� (1-" +
                std::to_string(allBooks.size()) + "): ", 1, allBooks.size()) - 1;

            std::string issueDate = getDateInput("������ ���� ������ (��-��-����): ");

            BookRecord record(allBooks[bookIndex], issueDate, "", false);
            subscribers[subIndex].addBook(record);
            std::cout << "����� ������ ������!\n";
            break;
        }
        case 3: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            size_t subIndex = getSizeTInput("������� ����� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            auto& sub = subscribers[subIndex];
            auto dueBooks = sub.findDueBooks();
            if (dueBooks.empty()) {
                std::cout << "���� ���� ��� ����������!\n";
                break;
            }

            std::cout << "����� �� ����������:\n";
            for (size_t i = 0; i < dueBooks.size(); i++) {
                std::cout << i + 1 << ". " << dueBooks[i].getBook().getTitle() << "\n";
            }

            size_t bookIndex = getSizeTInput("������� ����� ����� ��� ���������� (1-" +
                std::to_string(dueBooks.size()) + "): ", 1, dueBooks.size()) - 1;

            std::string returnDate = getDateInput("������ ���� ���������� (��-��-����): ");

            sub.returnBook(dueBooks[bookIndex].getBook());
            std::cout << "����� ��������� ������!\n";
            break;
        }
        case 4: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            std::cout << "������ ��������:\n";
            for (size_t i = 0; i < subscribers.size(); i++) {
                std::cout << i + 1 << ".\n" << subscribers[i] << "\n";
            }
            break;
        }
        case 5: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            std::cout << "������ ��'� ������: ";
            std::string author;
            std::getline(std::cin, author);

            std::cout << "���������� ������:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByAuthor(author);
                if (!books.empty()) {
                    found = true;
                    std::cout << "�������: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "����� ����� ������ �� ��������.\n";
            }
            break;
        }
        case 6: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            std::cout << "������ ����� �����������: ";
            std::string publisher;
            std::getline(std::cin, publisher);

            std::cout << "���������� ������:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByPublisher(publisher);
                if (!books.empty()) {
                    found = true;
                    std::cout << "�������: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "����� ����� ����������� �� ��������.\n";
            }
            break;
        }
        case 7: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            int year = getIntInput("������ �� �������: ");

            std::cout << "���������� ������:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByYear(year);
                if (!books.empty()) {
                    found = true;
                    std::cout << "�������: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "����� �� ��� �� �� ��������.\n";
            }
            break;
        }
        case 8: {
            if (subscribers.empty()) {
                std::cout << "���� ��������!\n";
                break;
            }

            size_t subIndex = getSizeTInput("������� ����� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Debt debt = subscribers[subIndex].generateDebt();
            std::cout << debt << "\n";
            break;
        }
        case 9: {
            if (subscribers.size() < 2) {
                std::cout << "������� ���������� 2 ��������!\n";
                break;
            }

            size_t sub1 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber united = subscribers[sub1] + subscribers[sub2];
            std::cout << "��'������ ������:\n" << united << "\n";
            subscribers.push_back(united);
            std::cout << "��'������ ������ ������ �� �������!\n";
            break;
        }
        case 10: {
            if (subscribers.size() < 2) {
                std::cout << "������� ���������� 2 ��������!\n";
                break;
            }

            size_t sub1 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber intersection = subscribers[sub1] * subscribers[sub2];
            std::cout << "������� ������:\n" << intersection << "\n";
            subscribers.push_back(intersection);
            std::cout << "��������� ������ �� �������!\n";
            break;
        }
        case 11: {
            if (subscribers.size() < 2) {
                std::cout << "������� ���������� 2 ��������!\n";
                break;
            }

            size_t sub1 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("������� ������� �������� (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber difference = subscribers[sub1] - subscribers[sub2];
            std::cout << "г����� ������:\n" << difference << "\n";
            subscribers.push_back(difference);
            std::cout << "��������� ������ �� �������!\n";
            break;
        }
        case 0:
            std::cout << "�� ���������!\n";
            break;
        }
    } while (choice != 0);

    return 0;
    #include <limits>
}