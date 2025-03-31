#include "book.h"

Book::Book() : author(""), title(""), year(0), publisher(""), price(0.0) {}

Book::Book(const std::string& a, const std::string& t, int y, const std::string& p, double pr)
    : Book() {
    if (!setAuthor(a)) {
        std::cout << "�������: ����������� �����. ����������� ������� �����.\n";
    }
    if (!setTitle(t)) {
        std::cout << "�������: ���������� �����. ����������� ������� �����.\n";
    }
    if (!setYear(y)) {
        year = 1900;  // �������� �������� ��� ������ ����
        std::cout << "������������: ����������� �� �������. ����������� 1900.\n";
    }
    if (!setPublisher(p)) {
        std::cout << "�������: ���������� �����������. ����������� ������� �����.\n";
    }
    if (!setPrice(pr)) {
        setPrice(0.0);
        std::cout << "�������: ���������� ����. ����������� 0.\n";
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
    if (y == -1) {  // "NULL" ��� ����
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
    return "�����: \"" + title + "\" ��������� " + author + ", " +
        std::to_string(year) + " ��, ����������� " + publisher +
        ", ֳ��: " + std::to_string(price);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << book.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Book& book) {
    std::string tmp_author;
    std::cout << "������ ������: ";
    std::getline(is >> std::ws, tmp_author);
    book.setAuthor(tmp_author);

    std::string tmp_title;
    std::cout << "������ �����: ";
    std::getline(is, tmp_title);
    book.setTitle(tmp_title);

    int tmp_year;
    std::cout << "������ ��: ";
    is >> tmp_year;
    if (!book.setYear(tmp_year)) {
        book.setYear(2025);
        std::cout << "�������: ����������� ��. ����������� 2025.\n";
    }

    is.ignore(); // ������� ������ ���� �������� �����

    std::string tmp_pub;
    std::cout << "������ �����������: ";
    std::getline(is >> std::ws, tmp_pub);
    book.setPublisher(tmp_pub);

    double tmp_price;
    std::cout << "������ ����: ";
    is >> tmp_price;
    if (!book.setPrice(tmp_price)) {
        book.setPrice(0.0);
        std::cout << "�������: ���������� ����. ����������� 0.\n";
    }

    return is;
}