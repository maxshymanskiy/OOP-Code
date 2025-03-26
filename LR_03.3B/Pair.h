#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Pair {
protected:
    long first;
    long second;
public:
    Pair();
    Pair(long firstValue, long secondValue);
    Pair(const Pair& other);

    long getFirst() const { return first; }
    long getSecond() const { return second; }

    bool setFirst(long value);
    bool setSecond(long value);

    Pair& operator=(const Pair& other);
    operator std::string() const;

    friend bool operator==(const Pair& p1, const Pair& p2);
    friend bool operator!=(const Pair& p1, const Pair& p2);
    friend bool operator<(const Pair& p1, const Pair& p2);
    friend bool operator>(const Pair& p1, const Pair& p2);
    friend bool operator<=(const Pair& p1, const Pair& p2);
    friend bool operator>=(const Pair& p1, const Pair& p2);

    friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
    friend std::istream& operator>>(std::istream& in, Pair& pair);
};