#include "Array.h"
#include <iostream>
#include <cstdlib>

Array::Array(int size, unsigned char initVal) : size(size) {
    if (size <= 0 || size > MAX_SIZE) {
        std::cerr << "�������: ������� ����� ������" << std::endl;
        exit(1);
    }
    array = new unsigned char[size]();
    for (int i = 0; i < size; ++i) array[i] = initVal;
}

Array::~Array() { delete[] array; }

int Array::getSize() const { return size; }

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        std::cerr << "�������: ������ " << index << " ���� ������ ������" << std::endl;
        exit(1);
    }
}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return array[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return array[index];
}

Array* Array::add(const Array& other) const {
    if (size != other.size) {
        std::cerr << "�������: ������ ������ �� ����������" << std::endl;
        exit(1);
    }
    Array* result = new Array(size);
    for (int i = 0; i < size; ++i) {
        (*result)[i] = array[i] + other.array[i];
    }
    return result;
}