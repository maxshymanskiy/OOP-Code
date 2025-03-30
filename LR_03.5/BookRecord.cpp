#include "BookRecord.h"

BookRecord::BookRecord() : book(), issueDate(""), returnDate(""), returned(false) {}

BookRecord::BookRecord(const Book& b, const std::string& issue, const std::string& ret, bool ret_status)
    : book(b), issueDate(issue), returnDate(ret), returned(ret_status) {
}

Book BookRecord::getBook() const { return book; }
std::string BookRecord::getIssueDate() const { return issueDate; }
std::string BookRecord::getReturnDate() const { return returnDate; }
bool BookRecord::isReturned() const { return returned; }

void BookRecord::setBook(const Book& b) { book = b; }
void BookRecord::setIssueDate(const std::string& date) { issueDate = date; }
void BookRecord::setReturnDate(const std::string& date) { returnDate = date; }
void BookRecord::setReturned(bool status) { returned = status; }

bool BookRecord::operator==(const BookRecord& other) const {
    return (book == other.book &&
        issueDate == other.issueDate &&
        returnDate == other.returnDate);
}

std::string BookRecord::toString() const {
    return book.toString() +
        "\n  Issue Date: " + issueDate +
        "\n  Return Date: " + returnDate +
        "\n  Status: " + (returned ? "Returned" : "Not Returned");
}

std::ostream& operator<<(std::ostream& os, const BookRecord& record) {
    os << record.toString();
    return os;
}

std::istream& operator>>(std::istream& is, BookRecord& record) {
    std::cout << "Enter book information:" << std::endl;
    is >> record.book;

    std::cout << "Enter issue date (DD-MM-YYYY): ";
    is >> std::ws;
    std::getline(is, record.issueDate);

    std::cout << "Enter return date (DD-MM-YYYY): ";
    std::getline(is, record.returnDate);

    std::cout << "Is the book returned? (1 for Yes, 0 for No): ";
    int status;
    is >> status;
    record.returned = (status == 1);

    return is;
}