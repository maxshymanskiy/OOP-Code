#include "debt.h"

Debt::Debt() {}
Debt::Debt(const std::vector<BookRecord>& records) : dueBooksRecord(records) {}

void Debt::addBookRecord(const BookRecord& record) {
    if (!record.isReturned()) {
        dueBooksRecord.push_back(record);
    }
}

double Debt::calculateTotalDebt() const {
    double total = 0.0;
    for (const auto& record : dueBooksRecord) {
        total += record.getBook().getPrice();
    }
    return total;
}

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

std::ostream& operator<<(std::ostream& os, const Debt& debt) {
    os << debt.toString();
    return os;
}