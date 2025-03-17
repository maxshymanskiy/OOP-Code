#include "Combination.h"
#include <iostream>
#include <sstream>

using namespace std;

Combination::Combination() {
    first = 0;
    second = 0;
}

Combination::Combination(int k, int n) {
    if (k > 0 && n > 0 && k < n) {
        first = k;
        second = n;
    }
    else {
        first = 0;
        second = 0;
        cout << "Error: Invalid values for Combination constructor (k must be < n and positive)" << endl;
    }
}

Combination::Combination(const Combination& c) {
    first = c.first;
    second = c.second;
}

void Combination::SetFirst(int value) {
    if (value > 0 && value < second) {
        first = value;
    }
    else {
        cout << "Error: Invalid value for k. Must be positive and less than n (" << second << ")." << endl;
    }
}

void Combination::SetSecond(int value) {
    if (value > 0 && first < value) {
        second = value;
    }
    else {
        cout << "Error: Invalid value for n. Must be positive and greater than k (" << first << ")." << endl;
    }
}

unsigned long long Combination::combination() const {
    unsigned long long result = 1;
    int k = first;
    int n = second;

    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k;  // Optimization to reduce number of operations

    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }

    return result;
}


Combination::operator std::string() const {
    stringstream ss;
    ss << "k = " << first << ", n = " << second << ", C(n,k) = " << combination();
    return ss.str();
}

Combination& Combination::operator=(const Combination& c) {
    if (this != &c) {
        first = c.first;
        second = c.second;
    }
    return *this;
}

// Дружні оператори

Combination& operator++(Combination& c) {
    c.first++;
    return c;
}

Combination operator++(Combination& c, int) {
    Combination temp(c);
    c.second++;
    return temp;
}

Combination& operator--(Combination& c) {
    c.first--;
    return c;
}

Combination operator--(Combination& c, int) {
    Combination temp(c);
    c.second--;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Combination& c) {
    out << string(c); 
    return out;
}

istream& operator>>(istream& in, Combination& c) {
    int k, n;
    cout << " k = "; in >> k;
    cout << " n = "; in >> n;

    if (k > 0 && n > 0 && k < n) {
        c.SetSecond(n);
        c.SetFirst(k);
    }
    else {
        cout << "Error: Invalid values. Please ensure k < n and both are positive." << endl;
        c.SetFirst(0);
        c.SetSecond(0);
    }

    return in;
}

Combination makeCombination(int k, int n) {
    Combination obj;
    if (k > 0 && n > 0 && k < n) {
        obj.SetSecond(n);
        obj.SetFirst(k);
    }
    else {
        cout << "Error: Invalid arguments for Combination (k must be < n and positive)" << endl;
    }
    return obj;
}