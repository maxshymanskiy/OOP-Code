#include "Pair.h"

Pair::Pair() : first(0), second(0) {}

Pair::Pair(long firstValue, long secondValue) : first(firstValue), second(secondValue) {}

Pair::Pair(const Pair& other) {
    *this = other;
}

bool Pair::setFirst(long value) {
    first = value;
    return true;
}

bool Pair::setSecond(long value) {
    second = value;
    return true;
}

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

bool operator==(const Pair& p1, const Pair& p2) {
    return (p1.first == p2.first) && (p1.second == p2.second);
}

bool operator!=(const Pair& p1, const Pair& p2) {
    return !(p1 == p2);
}

bool operator<(const Pair& p1, const Pair& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}

bool operator>(const Pair& p1, const Pair& p2) {
    return !(p1 < p2) && !(p1 == p2);
}

bool operator<=(const Pair& p1, const Pair& p2) {
    return (p1 < p2) || (p1 == p2);
}

bool operator>=(const Pair& p1, const Pair& p2) {
    return (p1 > p2) || (p1 == p2);
}

std::ostream& operator<<(std::ostream& out, const Pair& pair) {
    out << "(" << pair.first << ", " << pair.second << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Pair& pair) {
    std::cout << "Enter first value: ";
    in >> pair.first;
    std::cout << "Enter second value: ";
    in >> pair.second;
    return in;
}