#include "array.h"
#include "book.h"
#include "bookrecord.h"
#include "debt.h"
#include "subscriber.h"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // 1. Створення книг
    std::cout << "=== Створення книг ===" << std::endl;
    Book book1("Іван Франко", "Кам'яна душа", 1898, "Українська література", 150.0);
    Book book2("Леся Українка", "Лісова пісня", 1911, "Академія", 180.5);
    Book book3("Тарас Шевченко", "Кобзар", 1840, "Дніпро", 250.0);
    Book book4("Михайло Коцюбинський", "Тіні забутих предків", 1912, "Академія", 175.0);
    Book book5("Ольга Кобилянська", "Земля", 1902, "Українська література", 160.0);

    std::cout << book1 << std::endl;
    std::cout << book2 << std::endl;
    std::cout << book3 << std::endl;
    std::cout << book4 << std::endl;
    std::cout << book5 << std::endl;

    // 2. Створення записів про книги
    std::cout << "\n=== Створення записів про книги ===" << std::endl;
    BookRecord record1(book1, "01-03-2023", "01-04-2023", false);
    BookRecord record2(book2, "05-03-2023", "05-04-2023", true);
    BookRecord record3(book3, "10-03-2023", "10-04-2023", false);
    BookRecord record4(book4, "15-03-2023", "15-04-2023", false);
    BookRecord record5(book5, "20-03-2023", "20-04-2023", false);

    std::cout << record1 << std::endl;
    std::cout << record2 << std::endl;

    // 3. Створення абонентів та їхніх карток
    std::cout << "\n=== Створення абонентів ===" << std::endl;
    Subscriber sub1("Петренко Іван", 1001);
    sub1.addBook(record1);
    sub1.addBook(record3);
    sub1.addBook(record5);

    Subscriber sub2("Коваленко Марія", 1002);
    sub2.addBook(record2);
    sub2.addBook(record3);
    sub2.addBook(book4);  // альтернативний спосіб додавання книги

    std::cout << "\n=== Картка абонента 1 ===" << std::endl;
    std::cout << sub1 << std::endl;

    std::cout << "\n=== Картка абонента 2 ===" << std::endl;
    std::cout << sub2 << std::endl;

    // 4. Операції з картками
    std::cout << "\n=== Операції з картками ===" << std::endl;

    // Об'єднання карток
    Subscriber united = sub1 + sub2;
    std::cout << "Об'єднана картка:" << std::endl;
    std::cout << united << std::endl;

    // Перетин карток
    Subscriber intersection = sub1.intersect(sub2);
    std::cout << "Перетин карток:" << std::endl;
    std::cout << intersection << std::endl;

    // Різниця карток
    Subscriber difference = sub1.difference(sub2);
    std::cout << "Різниця карток (sub1 - sub2):" << std::endl;
    std::cout << difference << std::endl;

    // 5. Пошукові операції
    std::cout << "\n=== Пошукові операції ===" << std::endl;

    // Пошук книг за автором
    std::cout << "Книги Тараса Шевченка у абонента 1:" << std::endl;
    Array shevchenkoBooks = sub1.findByAuthor("Тарас Шевченко");
    std::cout << shevchenkoBooks << std::endl;

    // Пошук книг за видавництвом
    std::cout << "Книги видавництва 'Академія' у абонента 2:" << std::endl;
    Array academyBooks = sub2.findByPublisher("Академія");
    std::cout << academyBooks << std::endl;

    // Пошук книг за роком видання
    std::cout << "Книги 1912 року видання у абонента 2:" << std::endl;
    Array year1912Books = sub2.findByYear(1912);
    std::cout << year1912Books << std::endl;

    // 6. Робота з боргами
    std::cout << "\n=== Робота з боргами ===" << std::endl;

    // Генерація боргу
    Debt debt1 = sub1.generateDebt();
    std::cout << "Борг абонента 1:" << std::endl;
    std::cout << debt1 << std::endl;

    // Вартість книг, що підлягають поверненню
    std::cout << "Загальна вартість книг до повернення: "
        << debt1.calculateTotalPrice() << " грн." << std::endl;

    // Повернення книги
    std::cout << "\nПовернення книги 'Кобзар'..." << std::endl;
    sub1.returnBook("Кобзар", "05-04-2023");

    Debt debtAfterReturn = sub1.generateDebt();
    std::cout << "Оновлений борг абонента 1:" << std::endl;
    std::cout << debtAfterReturn << std::endl;

    return 0;
}