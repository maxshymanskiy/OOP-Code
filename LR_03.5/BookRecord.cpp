#include "BookRecord.h"
#include <iostream>

BookRecord::BookRecord() : book(), issueDate(""), returnDate(""), returned(false) {}

BookRecord::BookRecord(const Book& b, const std::string& issue, const std::string& ret, bool ret_status)
    : BookRecord() {
    if (!setBook(b)) {
        std::cout << "Попередження: Некоректна книга. Встановлено книгу за замовчуванням.\n";
    }
    if (!setIssueDate(issue)) {
        std::cout << "Попередження: Некоректна дата видачі. Встановлено порожній рядок.\n";
    }
    if (!setReturnDate(ret)) {
        std::cout << "Попередження: Некоректна дата повернення. Встановлено порожній рядок.\n";
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
    // Додаткова перевірка формату дати (DD-MM-YYYY)
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') {
        std::cout << "Попередження: Неправильний формат дати видачі. Очікується ДД-ММ-РРРР.\n";
        return false;
    }
    issueDate = date;
    return true;
}

bool BookRecord::setReturnDate(const std::string& date) {
    if (date.empty()) {
        // Для дати повернення можна дозволити пустий рядок, якщо книга ще не повернена
        if (!returned) {
            returnDate = "";
            return true;
        }
        return false;
    }
    // Перевірка формату дати
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') {
        std::cout << "Попередження: Неправильний формат дати повернення. Очікується ДД-ММ-РРРР.\n";
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
    return "Запис про книгу:\n" + book.toString() +
        "\nДата видачі: " + issueDate +
        "\nДата повернення: " + returnDate +
        "\nСтатус: " + (returned ? "Повернено" : "Не повернено");
}

std::ostream& operator<<(std::ostream& os, const BookRecord& record) {
    os << record.toString();
    return os;
}

std::istream& operator>>(std::istream& is, BookRecord& record) {
    std::cout << "Введіть інформацію про книгу:\n";
    is >> record.book;

    std::string issueDate;
    std::cout << "Введіть дату видачі (ДД-ММ-РРРР): ";
    is >> std::ws;
    std::getline(is, issueDate);
    if (!record.setIssueDate(issueDate)) {
        std::cout << "Попередження: Некоректна дата видачі.\n";
    }

    std::string returnDate;
    std::cout << "Введіть дату повернення (ДД-ММ-РРРР): ";
    std::getline(is, returnDate);
    if (!record.setReturnDate(returnDate)) {
        std::cout << "Попередження: Некоректна дата повернення.\n";
    }

    std::cout << "Книга повернена? (1 - Так, 0 - Ні): ";
    int status;
    is >> status;
    record.setReturned(status == 1);

    return is;
}