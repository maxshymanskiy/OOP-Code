#pragma once

#include "array.h"
#include "bookrecord.h"
#include "debt.h"
#include <vector>
#include <string>

class Subscriber : public Array {
private:
    std::string name;
    int libraryId;
    std::vector<BookRecord> borrowedBooks;

public:
    Subscriber();
    Subscriber(const std::string& n, int id);
    Subscriber(const Subscriber& other);

	std::string getName() const { return name; }
	int getLibraryId() const { return libraryId; }
	std::vector<BookRecord> getBorrowedBooks() const { return borrowedBooks; }

    bool setName(const std::string& n);
    bool setLibraryId(int id);

    void addBook(const BookRecord& record);
    bool removeBook(const Book& book);
    bool returnBook(const Book& book);

    std::vector<BookRecord> findDueBooks() const;
    std::vector<BookRecord> findBooksByAuthor(const std::string& author) const;
    std::vector<BookRecord> findBooksByPublisher(const std::string& publisher) const;
    std::vector<BookRecord> findBooksByYear(int year) const;

    double calculateTotalCostOfDueBooks() const;
    Debt generateDebt() const;

    Subscriber operator+(const Subscriber& other) const;  // Об'єднання
    Subscriber operator*(const Subscriber& other) const;  // Перетин
    Subscriber operator-(const Subscriber& other) const;  // Різниця

    Subscriber& operator=(const Subscriber& other);  // Присвоєння

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Subscriber& subscriber);
    friend std::istream& operator>>(std::istream& is, Subscriber& subscriber);
};