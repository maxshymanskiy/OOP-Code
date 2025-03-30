#include "book.h"

Book::Book() : author(""), title(""), year(0), publisher(""), price(0.0) {}

Book::Book(const std::string& a, const std::string& t, int y, const std::string& p, double pr)
    : author(a), title(t), publisher(p) {
    if (y <= 0) {
        std::cout << "Error: Invalid year. Setting to current year." << std::endl;
        year = 2025;
    }
    else {
        year = y;
    }

    if (pr < 0) {
        std::cout << "Error: Invalid price. Setting to 0." << std::endl;
        price = 0.0;
    }
    else {
        price = pr;
    }
}

Book::Book(const Book& other)
    : author(other.author), title(other.title), year(other.year),
    publisher(other.publisher), price(other.price) {
}

std::string Book::getAuthor() const { return author; }
std::string Book::getTitle() const { return title; }
int Book::getYear() const { return year; }
std::string Book::getPublisher() const { return publisher; }
double Book::getPrice() const { return price; }

void Book::setAuthor(const std::string& a) { author = a; }
void Book::setTitle(const std::string& t) { title = t; }

void Book::setYear(int y) {
    if (y <= 0) {
        std::cout << "Error: Invalid year." << std::endl;
        return;
    }
    year = y;
}

void Book::setPublisher(const std::string& p) { publisher = p; }

void Book::setPrice(double p) {
    if (p < 0) {
        std::cout << "Error: Invalid price." << std::endl;
        return;
    }
    price = p;
}

bool Book::operator==(const Book& other) const {
    return (author == other.author &&
        title == other.title &&
        year == other.year &&
        publisher == other.publisher);
}

std::string Book::toString() const {
    return "Book: \"" + title + "\" by " + author + ", " +
        std::to_string(year) + ", " + publisher + ", Price: " +
        std::to_string(price);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    std::cout << "Enter author: ";
    std::getline(is >> std::ws, book.author);

    std::cout << "Enter title: ";
    std::getline(is, book.title);

    std::cout << "Enter year: ";
    is >> book.year;
    if (book.year <= 0) {
        std::cout << "Error: Invalid year. Setting to current year." << std::endl;
        book.year = 2025;
    }

    std::cout << "Enter publisher: ";
    std::getline(is >> std::ws, book.publisher);

    std::cout << "Enter price: ";
    is >> book.price;
    if (book.price < 0) {
        std::cout << "Error: Invalid price. Setting to 0." << std::endl;
        book.price = 0.0;
    }

    return is;
}