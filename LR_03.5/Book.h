#pragma once

#include <string>
#include <iostream>

class Book {
private:
    std::string author;
    std::string title;
    int year;
    std::string publisher;
    double price;

public:
    Book();
    Book(const std::string& a, const std::string& t, int y, const std::string& p, double pr);
    Book(const Book& other);

    std::string getAuthor() const;
    std::string getTitle() const;
    int getYear() const;
    std::string getPublisher() const;
    double getPrice() const;

    void setAuthor(const std::string& a);
    void setTitle(const std::string& t);
    void setYear(int y);
    void setPublisher(const std::string& p);
    void setPrice(double p);

    bool operator==(const Book& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};