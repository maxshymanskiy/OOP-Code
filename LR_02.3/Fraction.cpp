#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

Fraction::Fraction() : whole(0), fractional(0) {}

Fraction::Fraction(long wholePart, unsigned short fractionalPart) {
    setWhole(wholePart);
    setFractional(fractionalPart);
}

Fraction::Fraction(const Fraction& other) {
    *this = other;
}

bool Fraction::setWhole(long value) {
    if (value < 0) {
        cout << "Error: Whole part cannot be negative.\n";
        return false;
    }
    whole = value;
    return true;
}

bool Fraction::setFractional(unsigned short value) {
    fractional = value;
    return true;
}

Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        whole = other.whole;
        fractional = other.fractional;
    }
    return *this;
}

Fraction::operator string() const {
    stringstream ss;
    ss << whole << "."
        << setw(5) << setfill('0') << fractional; // 5 цифр для USHRT_MAX
    return ss.str();
}

Fraction& Fraction::operator++() {
    // Префіксний інкремент (++f)
    whole++;
    return *this;
}

Fraction Fraction::operator++(int) {
    // Постфіксний інкремент (f++)
    Fraction temp = *this;
    whole++;
    return temp;
}

Fraction& Fraction::operator--() {
    // Префіксний декремент (--f)
    if (whole > 0)
        whole--;
    return *this;
}

Fraction Fraction::operator--(int) {
    // Постфіксний декремент (f--)
    Fraction temp = *this;
    if (whole > 0)
        whole--;
    return temp;
}

bool Fraction::operator==(const Fraction& other) const {
    return (whole == other.whole) && (fractional == other.fractional);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (whole != other.whole) return whole < other.whole;
    return fractional < other.fractional;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this < other) && !(*this == other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return (*this < other) || (*this == other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return (*this > other) || (*this == other);
}

Fraction Fraction::toFraction(double x) {
    Fraction result;
    result.whole = static_cast<long>(x);
    result.fractional = static_cast<unsigned short>((x - result.whole) * 100000);
    return result;
}

Fraction Subtract(const Fraction& f1, const Fraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 - val2;

    Fraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.whole = whole_part;
    resultFraction.fractional = static_cast<unsigned short>(fractional_part * 100000 + 0.5);

    return resultFraction;
}

ostream& operator<<(ostream& out, const Fraction& fraction) {
    out << string(fraction);
    return out;
}

istream& operator>>(istream& in, Fraction& fraction) {
    long wholePart;
    unsigned int tempFractional;

    cout << "Enter whole part: ";
    in >> wholePart;

    cout << "Enter fractional part: ";
    in >> tempFractional;

    fraction.setWhole(wholePart);
    fraction.setFractional(static_cast<unsigned short>(tempFractional));

    return in;
}

Fraction makeFraction(long wholePart, unsigned short fractionalPart) {
    return Fraction(wholePart, fractionalPart);
}