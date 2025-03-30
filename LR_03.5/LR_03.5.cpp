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

    std::cout << "=== Створення книг ===" << std::endl;
    Book book1("Іван Іванов", "Програмування на C++", 2020, "Технічна преса", 25.99);
    Book book2("Марія Петрівна", "Структури даних", 2019, "Академічні книги", 32.50);
    Book book3("Олександр Сидоров", "Алгоритми", 2021, "Технічна преса", 28.75);
    Book book4("Олена Коваленко", "Системи баз даних", 2018, "Академічні книги", 35.00);

    std::cout << "Книга 1: " << book1 << std::endl;
    std::cout << "Книга 2: " << book2 << std::endl;
    std::cout << "Книга 3: " << book3 << std::endl;
    std::cout << "Книга 4: " << book4 << std::endl;

    std::cout << "\n=== Створення записів про книги ===" << std::endl;
    BookRecord record1(book1, "01-03-2025", "15-03-2025", false);
    BookRecord record2(book2, "05-03-2025", "19-03-2025", false);
    BookRecord record3(book3, "10-02-2025", "24-02-2025", true);
    BookRecord record4(book4, "15-03-2025", "29-03-2025", false);

    std::cout << "Запис 1: " << std::endl << record1 << std::endl;
    std::cout << "Запис 2: " << std::endl << record2 << std::endl;

    std::cout << "\n=== Створення абонентів ===" << std::endl;
    Subscriber sub1("Аліса Браун", 12345);
    sub1.addBook(record1);
    sub1.addBook(record2);

    Subscriber sub2("Боб Грін", 67890);
    sub2.addBook(record2);  
    sub2.addBook(record3);

    std::cout << "\n=== Створення боргу ===" << std::endl;
    Debt debt = sub1.generateDebt();
    std::cout << "Борг абонента: " << std::endl << debt << std::endl;

    return 0;
}