#include "debt.h"

// Default constructor
Debt::Debt() {}

// Initialization constructor
Debt::Debt(const std::vector<BookRecord>& records) : dueBooksRecord(records) {}

// Add a book record
void Debt::addBookRecord(const BookRecord& record) {
    if (!record.isReturned()) {
        dueBooksRecord.push_back(record);
    }
}

// Get due books records
std::vector<BookRecord> Debt::getDueBooks() const {
    return dueBooksRecord;
}

// Calculate total debt value
double Debt::calculateTotalDebt() const {
    double total = 0.0;
    for (const auto& record : dueBooksRecord) {
        total += record.getBook().getPrice();
    }
    return total;
}

// Get number of due books
int Debt::getNumberOfDueBooks() const {
    return dueBooksRecord.size();
}

// String conversion
std::string Debt::toString() const {
    std::string result = "Debt Information:\n";
    result += "Number of Due Books: " + std::to_string(dueBooksRecord.size()) + "\n";
    result += "Total Debt Value: " + std::to_string(calculateTotalDebt()) + "\n";
    result += "Due Books:\n";

    for (size_t i = 0; i < dueBooksRecord.size(); i++) {
        result += std::to_string(i + 1) + ". " + dueBooksRecord[i].toString() + "\n";
    }

    return result;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Debt& debt) {
    os << debt.toString();
    return os;
}