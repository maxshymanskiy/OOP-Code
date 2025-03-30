#pragma once

#include "bookrecord.h"
#include <vector>

// Debt class to represent books that need to be returned
class Debt {
private:
    std::vector<BookRecord> dueBooksRecord;

public:
    // Default constructor
    Debt();

    // Initialization constructor
    Debt(const std::vector<BookRecord>& records);

    // Add a book record
    void addBookRecord(const BookRecord& record);

    // Get due books records
    std::vector<BookRecord> getDueBooks() const;

    // Calculate total debt value
    double calculateTotalDebt() const;

    // Get number of due books
    int getNumberOfDueBooks() const;

    // String conversion
    std::string toString() const;

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Debt& debt);
};