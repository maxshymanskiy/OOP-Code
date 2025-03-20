#pragma once
#include <iostream>

class Pair {
protected:
    long first;
    long second;
public:
    Pair(); // Default constructor
    Pair(long firstValue, long secondValue); // Parametrized constructor 
    Pair(const Pair& other); // Copy constructor

    long getFirst() const { return first; }
    long getSecond() const { return second; }

    bool setFirst(long value);
    bool setSecond(long value);

    Pair& operator=(const Pair& other);

    friend bool operator==(const Pair& p1, const Pair& p2);
    friend bool operator!=(const Pair& p1, const Pair& p2);
    friend bool operator<(const Pair& p1, const Pair& p2);
    friend bool operator>(const Pair& p1, const Pair& p2);
    friend bool operator<=(const Pair& p1, const Pair& p2);
    friend bool operator>=(const Pair& p1, const Pair& p2);

    friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
    friend std::istream& operator>>(std::istream& in, Pair& pair);
};