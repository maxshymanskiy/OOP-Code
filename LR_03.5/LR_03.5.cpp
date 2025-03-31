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

    // 1. ��������� ����
    std::cout << "=== ��������� ���� ===" << std::endl;
    Book book1("���� ������", "���'��� ����", 1898, "��������� ���������", 150.0);
    Book book2("���� �������", "˳���� ����", 1911, "�������", 180.5);
    Book book3("����� ��������", "������", 1840, "�����", 250.0);
    Book book4("������� ������������", "ҳ� ������� ������", 1912, "�������", 175.0);
    Book book5("����� �����������", "�����", 1902, "��������� ���������", 160.0);

    std::cout << book1 << std::endl;
    std::cout << book2 << std::endl;
    std::cout << book3 << std::endl;
    std::cout << book4 << std::endl;
    std::cout << book5 << std::endl;

    // 2. ��������� ������ ��� �����
    std::cout << "\n=== ��������� ������ ��� ����� ===" << std::endl;
    BookRecord record1(book1, "01-03-2023", "01-04-2023", false);
    BookRecord record2(book2, "05-03-2023", "05-04-2023", true);
    BookRecord record3(book3, "10-03-2023", "10-04-2023", false);
    BookRecord record4(book4, "15-03-2023", "15-04-2023", false);
    BookRecord record5(book5, "20-03-2023", "20-04-2023", false);

    std::cout << record1 << std::endl;
    std::cout << record2 << std::endl;

    // 3. ��������� �������� �� ���� ������
    std::cout << "\n=== ��������� �������� ===" << std::endl;
    Subscriber sub1("�������� ����", 1001);
    sub1.addBook(record1);
    sub1.addBook(record3);
    sub1.addBook(record5);

    Subscriber sub2("��������� ����", 1002);
    sub2.addBook(record2);
    sub2.addBook(record3);
    sub2.addBook(book4);  // �������������� ����� ��������� �����

    std::cout << "\n=== ������ �������� 1 ===" << std::endl;
    std::cout << sub1 << std::endl;

    std::cout << "\n=== ������ �������� 2 ===" << std::endl;
    std::cout << sub2 << std::endl;

    // 4. �������� � ��������
    std::cout << "\n=== �������� � �������� ===" << std::endl;

    // ��'������� ������
    Subscriber united = sub1 + sub2;
    std::cout << "��'������ ������:" << std::endl;
    std::cout << united << std::endl;

    // ������� ������
    Subscriber intersection = sub1.intersect(sub2);
    std::cout << "������� ������:" << std::endl;
    std::cout << intersection << std::endl;

    // г����� ������
    Subscriber difference = sub1.difference(sub2);
    std::cout << "г����� ������ (sub1 - sub2):" << std::endl;
    std::cout << difference << std::endl;

    // 5. ������� ��������
    std::cout << "\n=== ������� �������� ===" << std::endl;

    // ����� ���� �� �������
    std::cout << "����� ������ �������� � �������� 1:" << std::endl;
    Array shevchenkoBooks = sub1.findByAuthor("����� ��������");
    std::cout << shevchenkoBooks << std::endl;

    // ����� ���� �� ������������
    std::cout << "����� ����������� '�������' � �������� 2:" << std::endl;
    Array academyBooks = sub2.findByPublisher("�������");
    std::cout << academyBooks << std::endl;

    // ����� ���� �� ����� �������
    std::cout << "����� 1912 ���� ������� � �������� 2:" << std::endl;
    Array year1912Books = sub2.findByYear(1912);
    std::cout << year1912Books << std::endl;

    // 6. ������ � �������
    std::cout << "\n=== ������ � ������� ===" << std::endl;

    // ��������� �����
    Debt debt1 = sub1.generateDebt();
    std::cout << "���� �������� 1:" << std::endl;
    std::cout << debt1 << std::endl;

    // ������� ����, �� ��������� ����������
    std::cout << "�������� ������� ���� �� ����������: "
        << debt1.calculateTotalPrice() << " ���." << std::endl;

    // ���������� �����
    std::cout << "\n���������� ����� '������'..." << std::endl;
    sub1.returnBook("������", "05-04-2023");

    Debt debtAfterReturn = sub1.generateDebt();
    std::cout << "��������� ���� �������� 1:" << std::endl;
    std::cout << debtAfterReturn << std::endl;

    return 0;
}