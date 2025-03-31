#pragma once
#include "bookrecord.h"
#include <vector>
#include <string>

class Debt {
private:
    std::vector<BookRecord> dueBooksRecord;

public:
    Debt();
    Debt(const std::vector<BookRecord>& records);

    void addBookRecord(const BookRecord& record);
    double calculateTotalDebt() const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Debt& debt);
};