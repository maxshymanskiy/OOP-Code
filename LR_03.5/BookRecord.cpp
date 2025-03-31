#include "BookRecord.h"
#include <iostream>

BookRecord::BookRecord() : book(), issueDate(""), returnDate(""), returned(false) {}

BookRecord::BookRecord(const Book& b, const std::string& issue, const std::string& ret, bool ret_status)
    : BookRecord() {
    if (!setBook(b)) {
        std::cout << "������������: ���������� �����. ����������� ����� �� �������������.\n";
    }
    if (!setIssueDate(issue)) {
        std::cout << "������������: ���������� ���� ������. ����������� ������� �����.\n";
    }
    if (!setReturnDate(ret)) {
        std::cout << "������������: ���������� ���� ����������. ����������� ������� �����.\n";
    }
    setReturned(ret_status);
}

bool BookRecord::setBook(const Book& b) {
    book = b;
    return true;
}

bool BookRecord::setIssueDate(const std::string& date) {
    if (date.empty()) {
        return false;
    }
    // ��������� �������� ������� ���� (DD-MM-YYYY)
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') {
        std::cout << "������������: ������������ ������ ���� ������. ��������� ��-��-����.\n";
        return false;
    }
    issueDate = date;
    return true;
}

bool BookRecord::setReturnDate(const std::string& date) {
    if (date.empty()) {
        // ��� ���� ���������� ����� ��������� ������ �����, ���� ����� �� �� ���������
        if (!returned) {
            returnDate = "";
            return true;
        }
        return false;
    }
    // �������� ������� ����
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') {
        std::cout << "������������: ������������ ������ ���� ����������. ��������� ��-��-����.\n";
        return false;
    }
    returnDate = date;
    return true;
}
bool BookRecord::setReturned(bool status) {
    returned = status;
    return true;
}

bool BookRecord::operator==(const BookRecord& other) const {
    return (book == other.book &&
        issueDate == other.issueDate &&
        returnDate == other.returnDate);
}

std::string BookRecord::toString() const {
    return "����� ��� �����:\n" + book.toString() +
        "\n���� ������: " + issueDate +
        "\n���� ����������: " + returnDate +
        "\n������: " + (returned ? "���������" : "�� ���������");
}

std::ostream& operator<<(std::ostream& os, const BookRecord& record) {
    os << record.toString();
    return os;
}

std::istream& operator>>(std::istream& is, BookRecord& record) {
    std::cout << "������ ���������� ��� �����:\n";
    is >> record.book;

    std::string issueDate;
    std::cout << "������ ���� ������ (��-��-����): ";
    is >> std::ws;
    std::getline(is, issueDate);
    if (!record.setIssueDate(issueDate)) {
        std::cout << "������������: ���������� ���� ������.\n";
    }

    std::string returnDate;
    std::cout << "������ ���� ���������� (��-��-����): ";
    std::getline(is, returnDate);
    if (!record.setReturnDate(returnDate)) {
        std::cout << "������������: ���������� ���� ����������.\n";
    }

    std::cout << "����� ���������? (1 - ���, 0 - ͳ): ";
    int status;
    is >> status;
    record.setReturned(status == 1);

    return is;
}