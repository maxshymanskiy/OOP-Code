#pragma once
#include "bookrecord.h"
#include <vector>

class Debt {
private:
    std::vector<BookRecord> dueBooksRecord;

public:
    Debt();
    Debt(const std::vector<BookRecord>& records);

	std::vector<BookRecord> getDueBooks() const { return dueBooksRecord; }
	int getNumberOfDueBooks() const { return dueBooksRecord.size(); }

	double calculateTotalDebt() const;
    void addBookRecord(const BookRecord& record);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Debt& debt);
};