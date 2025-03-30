#include "subscriber.h"

// Default constructor
Subscriber::Subscriber() : Array(), name(""), libraryId(0) {}

// Initialization constructor
Subscriber::Subscriber(const std::string& n, int id) : Array(), name(n) {
    if (id <= 0) {
        std::cout << "Error: Invalid library ID. Setting to 0." << std::endl;
        libraryId = 0;
    }
    else {
        libraryId = id;
    }
}

// Copy constructor
Subscriber::Subscriber(const Subscriber& other)
    : Array(other), name(other.name), libraryId(other.libraryId),
    borrowedBooks(other.borrowedBooks) {
}

// Getters
std::string Subscriber::getName() const { return name; }
int Subscriber::getLibraryId() const { return libraryId; }
std::vector<BookRecord> Subscriber::getBorrowedBooks() const { return borrowedBooks; }

// Setters
void Subscriber::setName(const std::string& n) { name = n; }

void Subscriber::setLibraryId(int id) {
    if (id <= 0) {
        std::cout << "Error: Invalid library ID." << std::endl;
        return;
    }
    libraryId = id;
}

// Add a book to the borrowed list
void Subscriber::addBook(const BookRecord& record) {
    borrowedBooks.push_back(record);
}

// Remove a book from the borrowed list
bool Subscriber::removeBook(const Book& book) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (it->getBook() == book) {
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false;
}

// Mark a book as returned
bool Subscriber::returnBook(const Book& book) {
    for (auto& record : borrowedBooks) {
        if (record.getBook() == book && !record.isReturned()) {
            record.setReturned(true);
            return true;
        }
    }
    return false;
}

// Find books due for return
std::vector<BookRecord> Subscriber::findDueBooks() const {
    std::vector<BookRecord> dueBooks;
    for (const auto& record : borrowedBooks) {
        if (!record.isReturned()) {
            dueBooks.push_back(record);
        }
    }
    return dueBooks;
}

// Search books by author
std::vector<BookRecord> Subscriber::findBooksByAuthor(const std::string& author) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getAuthor() == author) {
            result.push_back(record);
        }
    }
    return result;
}

// Search books by publisher
std::vector<BookRecord> Subscriber::findBooksByPublisher(const std::string& publisher) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getPublisher() == publisher) {
            result.push_back(record);
        }
    }
    return result;
}

// Search books by year
std::vector<BookRecord> Subscriber::findBooksByYear(int year) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getYear() == year) {
            result.push_back(record);
        }
    }
    return result;
}

// Calculate total cost of books to be returned
double Subscriber::calculateTotalCostOfDueBooks() const {
    double total = 0.0;
    for (const auto& record : borrowedBooks) {
        if (!record.isReturned()) {
            total += record.getBook().getPrice();
        }
    }
    return total;
}

// Generate Debt object
Debt Subscriber::generateDebt() const {
    return Debt(findDueBooks());
}

// Union operation (merge two subscriber cards)
Subscriber Subscriber::unionCards(const Subscriber& s1, const Subscriber& s2) {
    Subscriber result(s1.name + " & " + s2.name, s1.libraryId);

    // Copy all books from first subscriber
    for (const auto& record : s1.borrowedBooks) {
        result.addBook(record);
    }

    // Add books from second subscriber without duplicates
    for (const auto& record : s2.borrowedBooks) {
        bool isDuplicate = false;
        for (const auto& existingRecord : result.borrowedBooks) {
            if (existingRecord.getBook() == record.getBook()) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result.addBook(record);
        }
    }

    return result;
}

// Intersection operation
Subscriber Subscriber::intersectionCards(const Subscriber& s1, const Subscriber& s2) {
    Subscriber result(s1.name + " ∩ " + s2.name, s1.libraryId);

    // Add only books that are in both subscribers
    for (const auto& record1 : s1.borrowedBooks) {
        for (const auto& record2 : s2.borrowedBooks) {
            if (record1.getBook() == record2.getBook()) {
                result.addBook(record1);
                break;
            }
        }
    }

    return result;
}

// Difference operation
Subscriber Subscriber::differenceCards(const Subscriber& s1, const Subscriber& s2) {
    Subscriber result(s1.name + " - " + s2.name, s1.libraryId);

    // Add books from first subscriber that are not in second subscriber
    for (const auto& record1 : s1.borrowedBooks) {
        bool found = false;
        for (const auto& record2 : s2.borrowedBooks) {
            if (record1.getBook() == record2.getBook()) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.addBook(record1);
        }
    }

    return result;
}

// Union operator
Subscriber Subscriber::operator+(const Subscriber& other) const {
    return unionCards(*this, other);
}

// Intersection operator
Subscriber Subscriber::operator*(const Subscriber& other) const {
    return intersectionCards(*this, other);
}

// Difference operator
Subscriber Subscriber::operator-(const Subscriber& other) const {
    return differenceCards(*this, other);
}

// Assignment operator
Subscriber& Subscriber::operator=(const Subscriber& other) {
    if (this != &other) {
        Array::operator=(other);
        name = other.name;
        libraryId = other.libraryId;
        borrowedBooks = other.borrowedBooks;
    }
    return *this;
}

// String conversion
std::string Subscriber::toString() const {
    std::string result = "Subscriber: " + name + "\n";
    result += "Library ID: " + std::to_string(libraryId) + "\n";
    result += "Borrowed Books (" + std::to_string(borrowedBooks.size()) + "):\n";

    for (size_t i = 0; i < borrowedBooks.size(); i++) {
        result += std::to_string(i + 1) + ". " + borrowedBooks[i].toString() + "\n";
    }

    return result;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Subscriber& subscriber) {
    os << subscriber.toString();
    return os;
}

// Input operator
std::istream& operator>>(std::istream& is, Subscriber& subscriber) {
    std::cout << "Enter subscriber name: ";
    is >> std::ws;
    std::getline(is, subscriber.name);

    std::cout << "Enter library ID: ";
    is >> subscriber.libraryId;
    if (subscriber.libraryId <= 0) {
        std::cout << "Error: Invalid library ID. Setting to 0." << std::endl;
        subscriber.libraryId = 0;
    }

    std::cout << "Enter number of borrowed books: ";
    int numBooks;
    is >> numBooks;
    if (numBooks < 0) {
        std::cout << "Error: Invalid number of books. Setting to 0." << std::endl;
        numBooks = 0;
    }

    subscriber.borrowedBooks.clear();
    for (int i = 0; i < numBooks; i++) {
        std::cout << "Enter information for book " << i + 1 << ":" << std::endl;
        BookRecord record;
        is >> record;
        subscriber.borrowedBooks.push_back(record);
    }

    return is;
}