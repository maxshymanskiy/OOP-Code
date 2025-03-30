#pragma once

#include "array.h"
#include "bookrecord.h"
#include "debt.h"
#include <vector>
#include <string>

// Subscriber class to represent a library subscriber
class Subscriber : public Array {
private:
    std::string name;
    int libraryId;
    std::vector<BookRecord> borrowedBooks;

public:
    // Default constructor
    Subscriber();

    // Initialization constructor
    Subscriber(const std::string& n, int id);

    // Copy constructor
    Subscriber(const Subscriber& other);

    // Getters
    std::string getName() const;
    int getLibraryId() const;
    std::vector<BookRecord> getBorrowedBooks() const;

    // Setters
    void setName(const std::string& n);
    void setLibraryId(int id);

    // Add a book to the borrowed list
    void addBook(const BookRecord& record);

    // Remove a book from the borrowed list
    bool removeBook(const Book& book);

    // Mark a book as returned
    bool returnBook(const Book& book);

    // Find books due for return
    std::vector<BookRecord> findDueBooks() const;

    // Search books by author
    std::vector<BookRecord> findBooksByAuthor(const std::string& author) const;

    // Search books by publisher
    std::vector<BookRecord> findBooksByPublisher(const std::string& publisher) const;

    // Search books by year
    std::vector<BookRecord> findBooksByYear(int year) const;

    // Calculate total cost of books to be returned
    double calculateTotalCostOfDueBooks() const;

    // Generate Debt object
    Debt generateDebt() const;

    // Union operation (merge two subscriber cards)
    static Subscriber unionCards(const Subscriber& s1, const Subscriber& s2);

    // Intersection operation
    static Subscriber intersectionCards(const Subscriber& s1, const Subscriber& s2);

    // Difference operation
    static Subscriber differenceCards(const Subscriber& s1, const Subscriber& s2);

    // Union operator
    Subscriber operator+(const Subscriber& other) const;

    // Intersection operator
    Subscriber operator*(const Subscriber& other) const;

    // Difference operator
    Subscriber operator-(const Subscriber& other) const;

    // Assignment operator
    Subscriber& operator=(const Subscriber& other);

    // String conversion
    std::string toString() const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Subscriber& subscriber);

    // Input operator
    friend std::istream& operator>>(std::istream& is, Subscriber& subscriber);
};