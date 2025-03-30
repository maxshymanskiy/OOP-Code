#pragma once

#include "book.h"
#include <string>

// BookRecord class to represent a borrowed book record
class BookRecord {
private:
    Book book;
    std::string issueDate;
    std::string returnDate;
    bool returned;

public:
    // Default constructor
    BookRecord();

    // Initialization constructor
    BookRecord(const Book& b, const std::string& issue, const std::string& ret, bool ret_status = false);

    // Getters
    Book getBook() const;
    std::string getIssueDate() const;
    std::string getReturnDate() const;
    bool isReturned() const;

    // Setters
    void setBook(const Book& b);
    void setIssueDate(const std::string& date);
    void setReturnDate(const std::string& date);
    void setReturned(bool status);

    // Equality operator
    bool operator==(const BookRecord& other) const;

    // String conversion
    std::string toString() const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const BookRecord& record);

    // Input operator
    friend std::istream& operator>>(std::istream& is, BookRecord& record);
};