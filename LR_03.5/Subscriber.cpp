#include "subscriber.h"

Subscriber::Subscriber() {
    setName("Невідомо");
    setLibraryId(0); // 0 - спеціальне значення для "не встановлено"
}

Subscriber::Subscriber(const std::string& n, int id) {
    if (!setName(n)) {
        std::cerr << "Попередження: Неприпустиме ім'я у конструкторі. Використовується значення за замовчуванням.\n";
        setName("Невідомо");
    }

    if (!setLibraryId(id)) {
        std::cerr << "Попередження: Неприпустимий бібліотечний ID. Використовується 0.\n";
        libraryId = 0;
    }
}

Subscriber::Subscriber(const Subscriber& other)
    : Array(other), name(other.name), libraryId(other.libraryId),
    borrowedBooks(other.borrowedBooks) {
}


bool Subscriber::setName(const std::string& n) {
    if (n.empty()) {
        std::cerr << "Помилка: Ім'я не може бути порожнім\n";
        return false;
    }
    name = n;
    return true;
}

bool Subscriber::setLibraryId(int id) {
    if (id <= 0) {
        std::cerr << "Помилка: Бібліотечний ID має бути додатнім числом\n";
        return false;
    }
    libraryId = id;
    return true;
}


void Subscriber::addBook(const BookRecord& record) {
    borrowedBooks.push_back(record);
}

bool Subscriber::removeBook(const Book& book) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (it->getBook() == book) {
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false;
}

bool Subscriber::returnBook(const Book& book) {
    for (auto& record : borrowedBooks) {
        if (record.getBook() == book && !record.isReturned()) {
            record.setReturned(true);
            return true;
        }
    }
    return false;
}

std::vector<BookRecord> Subscriber::findDueBooks() const {
    std::vector<BookRecord> dueBooks;
    for (const auto& record : borrowedBooks) {
        if (!record.isReturned()) {
            dueBooks.push_back(record);
        }
    }
    return dueBooks;
}

std::vector<BookRecord> Subscriber::findBooksByAuthor(const std::string& author) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getAuthor() == author) {
            result.push_back(record);
        }
    }
    return result;
}

std::vector<BookRecord> Subscriber::findBooksByPublisher(const std::string& publisher) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getPublisher() == publisher) {
            result.push_back(record);
        }
    }
    return result;
}

std::vector<BookRecord> Subscriber::findBooksByYear(int year) const {
    std::vector<BookRecord> result;
    for (const auto& record : borrowedBooks) {
        if (record.getBook().getYear() == year) {
            result.push_back(record);
        }
    }
    return result;
}

double Subscriber::calculateTotalCostOfDueBooks() const {
    double total = 0.0;
    for (const auto& record : borrowedBooks) {
        if (!record.isReturned()) {
            total += record.getBook().getPrice();
        }
    }
    return total;
}

Debt Subscriber::generateDebt() const {
    return Debt(findDueBooks());
}

Subscriber Subscriber::operator+(const Subscriber& other) const {
    Subscriber result(*this); 
    result.name = this->name + " & " + other.name; 

    // Додаємо книги з other, якщо вони ще не є в результаті
    for (const auto& record : other.borrowedBooks) {
        bool isDuplicate = false;
        for (const auto& existing : result.borrowedBooks) {
            if (existing.getBook() == record.getBook()) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            result.borrowedBooks.push_back(record);
        }
    }
    return result;
}

// Оператор перетину (*)
Subscriber Subscriber::operator*(const Subscriber& other) const {
    Subscriber result;
    result.name = this->name + " ∩ " + other.name;

    // Додаємо тільки спільні книги
    for (const auto& record1 : this->borrowedBooks) {
        for (const auto& record2 : other.borrowedBooks) {
            if (record1.getBook() == record2.getBook()) {
                result.borrowedBooks.push_back(record1);
                break;
            }
        }
    }
    return result;
}

// Оператор різниці (-)
Subscriber Subscriber::operator-(const Subscriber& other) const {
    Subscriber result(*this);
    result.name = this->name + " - " + other.name;

    // Видаляємо книги, які є в other
    auto& books = result.borrowedBooks;
    books.erase(
        std::remove_if(books.begin(), books.end(),
            [&other](const BookRecord& record) {
                for (const auto& otherRecord : other.borrowedBooks) {
                    if (record.getBook() == otherRecord.getBook()) {
                        return true;
                    }
                }
                return false;
            }),
        books.end()
    );
    return result;
}

// Оператор присвоєння (=)
Subscriber& Subscriber::operator=(const Subscriber& other) {
    if (this != &other) {
        Array::operator=(other);
        name = other.name;
        libraryId = other.libraryId;
        borrowedBooks = other.borrowedBooks;
    }
    return *this;
}

std::string Subscriber::toString() const {
    std::string result = "Subscriber: " + name + "\n";
    result += "Library ID: " + std::to_string(libraryId) + "\n";
    result += "Borrowed Books (" + std::to_string(borrowedBooks.size()) + "):\n";

    for (size_t i = 0; i < borrowedBooks.size(); i++) {
        result += std::to_string(i + 1) + ". " + borrowedBooks[i].toString() + "\n";
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Subscriber& subscriber) {
    os << subscriber.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Subscriber& subscriber) {
    std::cout << "Введіть ім'я передплатника: ";
    is >> std::ws;
    std::getline(is, subscriber.name);

    std::cout << "Введіть бібліотечний ID: ";
    is >> subscriber.libraryId;
    if (subscriber.libraryId <= 0) {
        std::cout << "Помилка: Неприпустимий бібліотечний ID. Встановлюється 0." << std::endl;
        subscriber.libraryId = 0;
    }

    std::cout << "Введіть кількість позичених книг: ";
    int numBooks;
    is >> numBooks;
    if (numBooks < 0) {
        std::cout << "Помилка: Неприпустима кількість книг. Встановлюється 0." << std::endl;
        numBooks = 0;
    }

    subscriber.borrowedBooks.clear();
    for (int i = 0; i < numBooks; i++) {
        std::cout << "Введіть інформацію про книгу " << i + 1 << ":" << std::endl;
        BookRecord record;
        is >> record;
        subscriber.borrowedBooks.push_back(record);
    }

    return is;
}