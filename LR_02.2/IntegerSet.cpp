#include "IntegerSet.h"
#include <sstream>
#include <algorithm>

// Перевірка наявності елемента
bool IntegerSet::contains(int elem) const {
    for (size_t i = 0; i < size; ++i) {
        if (elements[i] == elem) return true;
    }
    return false;
}

// Зміна ємності масиву
void IntegerSet::resize(size_t newCapacity) {
    int* newElements = new int[newCapacity];
    std::memcpy(newElements, elements, size * sizeof(int));
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

// Геттери
const int* IntegerSet::getElements() const {
    return elements;
}

size_t IntegerSet::getSize() const {
    return size;
}

size_t IntegerSet::getCapacity() const {
    return capacity;
}

void IntegerSet::addElement(int elem) {
    if (!contains(elem)) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        elements[size++] = elem;
    }
}

void IntegerSet::removeElement(int elem) {
    for (size_t i = 0; i < size; ++i) {
        if (elements[i] == elem) {
            std::memmove(elements + i, elements + i + 1, (size - i - 1) * sizeof(int));
            --size;
            break;
        }
    }
}

IntegerSet::IntegerSet() : elements(nullptr), size(0), capacity(0) {}

IntegerSet::IntegerSet(const int* arr, size_t n) : elements(nullptr), size(0), capacity(n) {
    if (capacity > 0) {
        elements = new int[capacity];
        for (size_t i = 0; i < n; ++i) {
            if (!contains(arr[i])) {
                elements[size++] = arr[i];
            }
        }
    }
}

IntegerSet::IntegerSet(const IntegerSet& other) : elements(nullptr), size(other.size), capacity(other.capacity) {
    if (capacity > 0) {
        elements = new int[capacity];
        std::memcpy(elements, other.elements, size * sizeof(int));
    }
}

IntegerSet::~IntegerSet() {
    delete[] elements;
}

IntegerSet& IntegerSet::operator=(const IntegerSet& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        capacity = other.capacity;
        elements = new int[capacity];
        std::memcpy(elements, other.elements, size * sizeof(int));
    }
    return *this;
}

bool operator<=(const IntegerSet& a, const IntegerSet& b) {
    for (size_t i = 0; i < a.size; ++i) {
        if (!b.contains(a.elements[i])) return false;
    }
    return true;
}

bool operator>=(const IntegerSet& a, const IntegerSet& b) {
    return b <= a;
}

bool operator==(const IntegerSet& a, const IntegerSet& b) {
    return a.size == b.size && a <= b;
}

bool operator!=(const IntegerSet& a, const IntegerSet& b) {
    return !(a == b);
}

bool operator^(int elem, const IntegerSet& set) {
    return set.contains(elem);
}

std::ostream& operator<<(std::ostream& os, const IntegerSet& set) {
    os << "{ ";
    for (size_t i = 0; i < set.size; ++i) {
        os << set.elements[i] << (i < set.size - 1 ? ", " : " ");
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, IntegerSet& set) {
    std::string line;
    getline(is, line);
    std::istringstream iss(line);

    int temp;
    while (iss >> temp) {
        set.addElement(temp);
    }
    return is;
}

IntegerSet::operator std::string() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}