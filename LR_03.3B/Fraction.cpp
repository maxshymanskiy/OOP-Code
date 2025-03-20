#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

Fraction::Fraction() : Pair(0, 0) {}

Fraction::Fraction(long wholePart, unsigned short fractionalPart) : Pair(wholePart, fractionalPart) {}

Fraction::Fraction(const Fraction& other) : Pair(other) {}

bool Fraction::setWhole(long value) {
    first = value;
    return true;
}

bool Fraction::setFractional(unsigned short value) {
    if (value < 0) {
        cout << "Error: Fractional part cannot be negative.\n";
        return false;
    }
    second = value;
    return true;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        Pair::operator=(other);
    }
    return *this;
}

Fraction::operator std::string() const {
    stringstream ss;
    ss << first << "."
        << setw(5) << setfill('0') << second; // 5 digits for USHRT_MAX
    return ss.str();
}

Fraction& Fraction::operator++() {
    first++;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    first++;
    return temp;
}

Fraction& Fraction::operator--() {
    if (first > 0)
        first--;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    if (first > 0)
        first--;
    return temp;
}

Fraction Fraction::toFraction(double x) {
    Fraction result;
    result.first = static_cast<long>(x);
    result.second = static_cast<unsigned short>((x - result.first) * 100000);
    return result;
}


Fraction operator-(const Fraction& f1, const Fraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 - val2;

    Fraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}



Fraction makeFraction(long wholePart, unsigned short fractionalPart) {
    return Fraction(wholePart, fractionalPart);
}