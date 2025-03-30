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

    std::cout << "=== ��������� ���� ===" << std::endl;
    Book book1("���� ������", "������������� �� C++", 2020, "������� �����", 25.99);
    Book book2("���� �������", "��������� �����", 2019, "�������� �����", 32.50);
    Book book3("��������� �������", "���������", 2021, "������� �����", 28.75);
    Book book4("����� ���������", "������� ��� �����", 2018, "�������� �����", 35.00);

    std::cout << "����� 1: " << book1 << std::endl;
    std::cout << "����� 2: " << book2 << std::endl;
    std::cout << "����� 3: " << book3 << std::endl;
    std::cout << "����� 4: " << book4 << std::endl;

    std::cout << "\n=== ��������� ������ ��� ����� ===" << std::endl;
    BookRecord record1(book1, "01-03-2025", "15-03-2025", false);
    BookRecord record2(book2, "05-03-2025", "19-03-2025", false);
    BookRecord record3(book3, "10-02-2025", "24-02-2025", true);
    BookRecord record4(book4, "15-03-2025", "29-03-2025", false);

    std::cout << "����� 1: " << std::endl << record1 << std::endl;
    std::cout << "����� 2: " << std::endl << record2 << std::endl;

    std::cout << "\n=== ��������� �������� ===" << std::endl;
    Subscriber sub1("���� �����", 12345);
    sub1.addBook(record1);
    sub1.addBook(record2);

    Subscriber sub2("��� ���", 67890);
    sub2.addBook(record2);  
    sub2.addBook(record3);

    std::cout << "\n=== ��������� ����� ===" << std::endl;
    Debt debt = sub1.generateDebt();
    std::cout << "���� ��������: " << std::endl << debt << std::endl;

    return 0;
}