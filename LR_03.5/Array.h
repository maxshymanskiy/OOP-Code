#pragma once
#include <iostream>

const int MAX_ARRAY_SIZE = 100;

class Array {
protected:
    static const int MAX_SIZE = MAX_ARRAY_SIZE;
    int* elements;
    int size;

    bool rangeCheck(int index) const;

public:
    Array();
    Array(int newSize, int value = 0);
    Array(const Array& other);

    virtual ~Array();

    Array& operator=(const Array& other);
    int& operator[](int index);
    const int& operator[](int index) const;

    int getSize() const;
    void setSize(int newSize);

    friend std::ostream& operator<<(std::ostream& os, const Array& arr);
    friend std::istream& operator>>(std::istream& is, Array& arr);
};