#include "book.h"

Book::Book() : author(""), title(""), year(0), publisher(""), price(0.0) {}

Book::Book(const std::string& a, const std::string& t, int y, const std::string& p, double pr)
    : Book() {
    if (!setAuthor(a)) {
        std::cout << "Помилка: Некоректний автор. Встановлено порожній рядок.\n";
    }
    if (!setTitle(t)) {
        std::cout << "Помилка: Некоректна назва. Встановлено порожній рядок.\n";
    }
    if (!setYear(y)) {
        year = 1900;  // Дефолтне значення для старих книг
        std::cout << "Попередження: Некоректний рік видання. Встановлено 1900.\n";
    }
    if (!setPublisher(p)) {
        std::cout << "Помилка: Некоректне видавництво. Встановлено порожній рядок.\n";
    }
    if (!setPrice(pr)) {
        setPrice(0.0);
        std::cout << "Помилка: Некоректна ціна. Встановлено 0.\n";
    }
}

Book::Book(const Book& other)
    : author(other.author), title(other.title), year(other.year),
    publisher(other.publisher), price(other.price) {
}

bool Book::setAuthor(const std::string& a) {
    if (a.empty()) return false;
    author = a;
    return true;
}

bool Book::setTitle(const std::string& t) {
    if (t.empty()) return false;
    title = t;
    return true;
}

bool Book::setYear(int y) {
    if (y == -1) {  // "NULL" для року
        year = -1;
        return true;
    }
    if (y <= 0 || y > 2025) {
        return false;
    }
    year = y;
    return true;
}

bool Book::setPublisher(const std::string& p) {
    if (p.empty()) return false;
    publisher = p;
    return true;
}

bool Book::setPrice(double p) {
    if (p < 0) return false;
    price = p;
    return true;
}

bool Book::operator==(const Book& other) const {
    return (author == other.author &&
        title == other.title &&
        year == other.year &&
        publisher == other.publisher);
}

std::string Book::toString() const {
    return "Книга: \"" + title + "\" авторства " + author + ", " +
        std::to_string(year) + " рік, видавництво " + publisher +
        ", Ціна: " + std::to_string(price);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    std::string tmp_author;
    std::cout << "Введіть автора: ";
    std::getline(is >> std::ws, tmp_author);
    book.setAuthor(tmp_author);

    std::string tmp_title;
    std::cout << "Введіть назву: ";
    std::getline(is, tmp_title);
    book.setTitle(tmp_title);

    int tmp_year;
    std::cout << "Введіть рік: ";
    is >> tmp_year;
    if (!book.setYear(tmp_year)) {
        book.setYear(2025);
        std::cout << "Помилка: Некоректний рік. Встановлено 2025.\n";
    }

    is.ignore(); // Очистка буфера після введення числа

    std::string tmp_pub;
    std::cout << "Введіть видавництво: ";
    std::getline(is >> std::ws, tmp_pub);
    book.setPublisher(tmp_pub);

    double tmp_price;
    std::cout << "Введіть ціну: ";
    is >> tmp_price;
    if (!book.setPrice(tmp_price)) {
        book.setPrice(0.0);
        std::cout << "Помилка: Некоректна ціна. Встановлено 0.\n";
    }

    return is;
}