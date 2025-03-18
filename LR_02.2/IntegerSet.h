#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>

class IntegerSet {
private:
    int* elements;  // Динамічний масив елементів
    size_t size;     // Поточна кількість елементів
    size_t capacity; // Загальна ємність масиву

    bool contains(int elem) const;
    void resize(size_t newCapacity);

public:
    const int* getElements() const;
    size_t getSize() const;
    size_t getCapacity() const;

    void addElement(int elem);
    void removeElement(int elem);

    IntegerSet();
    IntegerSet(const int* arr, size_t n);
    IntegerSet(const IntegerSet& other);

    ~IntegerSet();

    IntegerSet& operator=(const IntegerSet& other);

    friend bool operator<=(const IntegerSet& a, const IntegerSet& b);
    friend bool operator>=(const IntegerSet& a, const IntegerSet& b);
    friend bool operator==(const IntegerSet& a, const IntegerSet& b);
    friend bool operator!=(const IntegerSet& a, const IntegerSet& b);

    friend bool operator^(int elem, const IntegerSet& set);

    friend std::ostream& operator<<(std::ostream& os, const IntegerSet& set);
    friend std::istream& operator>>(std::istream& is, IntegerSet& set);

    operator std::string() const;
};