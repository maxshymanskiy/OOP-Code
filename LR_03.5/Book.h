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

    std::string getAuthor() const { return author; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::string getPublisher() const { return publisher; }
    double getPrice() const { return price; }

    bool setAuthor(const std::string& a);
    bool setTitle(const std::string& t);
    bool setYear(int y);
    bool setPublisher(const std::string& p);
    bool setPrice(double p);

    bool operator==(const Book& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};