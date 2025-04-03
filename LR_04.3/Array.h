#pragma once
#include <iostream>

class Array {
protected:
    unsigned char* array;
    int size;
    static const int MAX_SIZE = 256;

public:
    Array(int size, unsigned char initVal = 0);
    virtual ~Array();
    int getSize() const;
    virtual Array* add(const Array& other) const;
    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

protected:
    void rangeCheck(int index) const;
};