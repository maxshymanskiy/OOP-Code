#include "array.h"
#include <iostream>
#include <sstream>

bool Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Помилка: Індекс " << index << " за межами діапазону [0, " << size - 1 << "]" << std::endl;
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

Array::Array(int newSize, int value) : Array() {  // Делегування конструктора
    if (!setSize(newSize)) {
        std::cout << "Попередження: Невірний розмір масиву. Використовується розмір 0." << std::endl;
    }
    for (int i = 0; i < size; i++) {
        elements[i] = value;
    }
}

Array::Array(const Array& other) : Array() { *this = other; }

Array::~Array() {
    delete[] elements;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        setSize(other.size);
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

int& Array::operator[](int index) {
    if (!rangeCheck(index)) {
        static int dummy = 0;
        return dummy;
    }
    return elements[index];
}

const int& Array::operator[](int index) const {
    if (!rangeCheck(index)) {
        static const int dummy = 0;
        return dummy;
    }
    return elements[index];
}

int Array::getSize() const {
    return size;
}

bool Array::setSize(int newSize) {
    if (newSize < 0 || newSize > MAX_SIZE) {
        return false;
    }
    size = newSize;
    return true;
}

std::string Array::toString() const {
    std::ostringstream oss;
    oss << "Масив [ ";
    for (int i = 0; i < size; i++) {
        oss << elements[i] << " ";
    }
    oss << "]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {
    os << arr.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {
    std::cout << "Введіть розмір масиву (макс. " << MAX_ARRAY_SIZE << "): ";
    int newSize;
    is >> newSize;

    if (!arr.setSize(newSize)) {
        std::cout << "Помилка: Невірний розмір масиву. Встановлено розмір 0." << std::endl;
        arr.setSize(0);
        return is;
    }

    std::cout << "Введіть " << arr.size << " елементів:" << std::endl;
    for (int i = 0; i < arr.size; i++) {
        std::cout << "Елемент " << i << ": ";
        is >> arr.elements[i];
    }
    return is;
}