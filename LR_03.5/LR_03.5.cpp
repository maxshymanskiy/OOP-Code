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
            std::cout << "Помилка: Значення має бути між " << min << " і " << max << "\n";
        }
        else {
            std::cout << "Помилка: Введіть коректне число!\n";
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
            std::cout << "Помилка: Значення має бути між " << min << " і " << max << "\n";
        }
        else {
            std::cout << "Помилка: Введіть коректне число!\n";
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
        std::cout << "Помилка: Введіть дату у форматі ДД-ММ-РРРР\n";
    }
}

void displayMenu() {
    std::cout << "\n=== Бібліотечна система ===" << std::endl;
    std::cout << "1. Додати нового абонента" << std::endl;
    std::cout << "2. Додати книгу до абонента" << std::endl;
    std::cout << "3. Повернути книгу" << std::endl;
    std::cout << "4. Показати всіх абонентів" << std::endl;
    std::cout << "5. Пошук книг за автором" << std::endl;
    std::cout << "6. Пошук книг за видавництвом" << std::endl;
    std::cout << "7. Пошук книг за роком" << std::endl;
    std::cout << "8. Показати борги абонента" << std::endl;
    std::cout << "9. Об'єднати картки абонентів" << std::endl;
    std::cout << "10. Знайти перетин карток" << std::endl;
    std::cout << "11. Знайти різницю карток" << std::endl;
    std::cout << "0. Вийти" << std::endl;
    std::cout << "Виберіть опцію: ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Subscriber> subscribers;
    std::vector<Book> allBooks = {
        Book("Іван Франко", "Кам'яна душа", 1898, "Українська література", 150.0),
        Book("Леся Українка", "Лісова пісня", 1911, "Академія", 180.5),
        Book("Тарас Шевченко", "Кобзар", 1840, "Дніпро", 250.0),
        Book("Михайло Коцюбинський", "Тіні забутих предків", 1912, "Академія", 175.0),
        Book("Ольга Кобилянська", "Земля", 1902, "Українська література", 160.0)
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
            std::cout << "Абонента додано успішно!\n";
            break;
        }
        case 2: {
            if (subscribers.empty()) {
                std::cout << "Спочатку додайте абонентів!\n";
                break;
            }

            std::cout << "Доступні книги:\n";
            for (size_t i = 0; i < allBooks.size(); i++) {
                std::cout << i + 1 << ". " << allBooks[i] << "\n";
            }

            size_t subIndex = getSizeTInput("Виберіть номер абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            size_t bookIndex = getSizeTInput("Виберіть номер книги (1-" +
                std::to_string(allBooks.size()) + "): ", 1, allBooks.size()) - 1;

            std::string issueDate = getDateInput("Введіть дату видачі (ДД-ММ-РРРР): ");

            BookRecord record(allBooks[bookIndex], issueDate, "", false);
            subscribers[subIndex].addBook(record);
            std::cout << "Книгу додано успішно!\n";
            break;
        }
        case 3: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            size_t subIndex = getSizeTInput("Виберіть номер абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            auto& sub = subscribers[subIndex];
            auto dueBooks = sub.findDueBooks();
            if (dueBooks.empty()) {
                std::cout << "Немає книг для повернення!\n";
                break;
            }

            std::cout << "Книги до повернення:\n";
            for (size_t i = 0; i < dueBooks.size(); i++) {
                std::cout << i + 1 << ". " << dueBooks[i].getBook().getTitle() << "\n";
            }

            size_t bookIndex = getSizeTInput("Виберіть номер книги для повернення (1-" +
                std::to_string(dueBooks.size()) + "): ", 1, dueBooks.size()) - 1;

            std::string returnDate = getDateInput("Введіть дату повернення (ДД-ММ-РРРР): ");

            sub.returnBook(dueBooks[bookIndex].getBook());
            std::cout << "Книгу повернено успішно!\n";
            break;
        }
        case 4: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            std::cout << "Список абонентів:\n";
            for (size_t i = 0; i < subscribers.size(); i++) {
                std::cout << i + 1 << ".\n" << subscribers[i] << "\n";
            }
            break;
        }
        case 5: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            std::cout << "Введіть ім'я автора: ";
            std::string author;
            std::getline(std::cin, author);

            std::cout << "Результати пошуку:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByAuthor(author);
                if (!books.empty()) {
                    found = true;
                    std::cout << "Абонент: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "Книги цього автора не знайдено.\n";
            }
            break;
        }
        case 6: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            std::cout << "Введіть назву видавництва: ";
            std::string publisher;
            std::getline(std::cin, publisher);

            std::cout << "Результати пошуку:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByPublisher(publisher);
                if (!books.empty()) {
                    found = true;
                    std::cout << "Абонент: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "Книги цього видавництва не знайдено.\n";
            }
            break;
        }
        case 7: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            int year = getIntInput("Введіть рік видання: ");

            std::cout << "Результати пошуку:\n";
            bool found = false;
            for (size_t i = 0; i < subscribers.size(); i++) {
                auto books = subscribers[i].findBooksByYear(year);
                if (!books.empty()) {
                    found = true;
                    std::cout << "Абонент: " << subscribers[i].getName() << "\n";
                    for (const auto& book : books) {
                        std::cout << " - " << book.getBook().getTitle() << "\n";
                    }
                }
            }
            if (!found) {
                std::cout << "Книги за цей рік не знайдено.\n";
            }
            break;
        }
        case 8: {
            if (subscribers.empty()) {
                std::cout << "Немає абонентів!\n";
                break;
            }

            size_t subIndex = getSizeTInput("Виберіть номер абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Debt debt = subscribers[subIndex].generateDebt();
            std::cout << debt << "\n";
            break;
        }
        case 9: {
            if (subscribers.size() < 2) {
                std::cout << "Потрібно щонайменше 2 абоненти!\n";
                break;
            }

            size_t sub1 = getSizeTInput("Виберіть першого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("Виберіть другого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber united = subscribers[sub1] + subscribers[sub2];
            std::cout << "Об'єднана картка:\n" << united << "\n";
            subscribers.push_back(united);
            std::cout << "Об'єднану картку додано до системи!\n";
            break;
        }
        case 10: {
            if (subscribers.size() < 2) {
                std::cout << "Потрібно щонайменше 2 абоненти!\n";
                break;
            }

            size_t sub1 = getSizeTInput("Виберіть першого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("Виберіть другого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber intersection = subscribers[sub1] * subscribers[sub2];
            std::cout << "Перетин карток:\n" << intersection << "\n";
            subscribers.push_back(intersection);
            std::cout << "Результат додано до системи!\n";
            break;
        }
        case 11: {
            if (subscribers.size() < 2) {
                std::cout << "Потрібно щонайменше 2 абоненти!\n";
                break;
            }

            size_t sub1 = getSizeTInput("Виберіть першого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;
            size_t sub2 = getSizeTInput("Виберіть другого абонента (1-" +
                std::to_string(subscribers.size()) + "): ", 1, subscribers.size()) - 1;

            Subscriber difference = subscribers[sub1] - subscribers[sub2];
            std::cout << "Різниця карток:\n" << difference << "\n";
            subscribers.push_back(difference);
            std::cout << "Результат додано до системи!\n";
            break;
        }
        case 0:
            std::cout << "До побачення!\n";
            break;
        }
    } while (choice != 0);

    return 0;
    #include <limits>
}