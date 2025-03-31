#pragma once

#include "book.h"
#include <string>

class BookRecord {
private:
    Book book;
    std::string issueDate;
    std::string returnDate;
    bool returned;

public:
    BookRecord();
    BookRecord(const Book& b, const std::string& issue, const std::string& ret, bool ret_status = false);

    Book getBook() const { return book; }
    std::string getIssueDate() const { return issueDate; }
    std::string getReturnDate() const { return returnDate; }
    bool isReturned() const { return returned; }

    bool setBook(const Book& b);
    bool setIssueDate(const std::string& date);
    bool setReturnDate(const std::string& date);
    bool setReturned(bool status);

    bool operator==(const BookRecord& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const BookRecord& record);
    friend std::istream& operator>>(std::istream& is, BookRecord& record);
};