#include "array.h"
#include <iostream>

bool Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Error: Index " << index << " out of range [0, " << size - 1 << "]" << std::endl;
        return false;
    }
    return true;
}

Array::Array() : size(0) {
    elements = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        elements[i] = 0;
    }
}

Array::Array(int newSize, int value) {
    if (newSize <= 0 || newSize > MAX_SIZE) {
        std::cout << "Error: Invalid array size. Using default size 0." << std::endl;
        size = 0;
    }
    else {
        size = newSize;
    }

    elements = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        elements[i] = (i < size) ? value : 0;
    }
}

Array::Array(const Array& other) : size(other.size) {
    elements = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        elements[i] = other.elements[i];
    }
}

Array::~Array() {
    delete[] elements;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        size = other.size;
        for (int i = 0; i < MAX_SIZE; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

int& Array::operator[](int index) {
    if (!rangeCheck(index)) {
        exit(1);
    }
    return elements[index];
}

const int& Array::operator[](int index) const {
    if (!rangeCheck(index)) {
        exit(1);
    }
    return elements[index];
}

int Array::getSize() const {
    return size;
}

void Array::setSize(int newSize) {
    if (newSize <= 0 || newSize > MAX_SIZE) {
        std::cout << "Error: Invalid size. Size remains unchanged." << std::endl;
        return;
    }
    size = newSize;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << "Array [ ";
    for (int i = 0; i < arr.size; i++) {
        os << arr.elements[i] << " ";
    }
    os << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    std::cout << "Enter array size (max " << MAX_ARRAY_SIZE << "): ";
    int newSize;
    is >> newSize;
    if (newSize <= 0 || newSize > MAX_ARRAY_SIZE) {
        std::cout << "Error: Invalid array size. Using size 0." << std::endl;
        arr.size = 0;
        return is;
    }
    arr.size = newSize;

    std::cout << "Enter " << arr.size << " elements:" << std::endl;
    for (int i = 0; i < arr.size; i++) {
        std::cout << "Element " << i << ": ";
        is >> arr.elements[i];
    }
    return is;
}