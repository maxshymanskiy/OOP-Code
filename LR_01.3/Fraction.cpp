#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>

using namespace std;

void Fraction::setWhole(long value) {
    if (value < 0) {
        cout << "Error: Whole part cannot be negative. Terminating program.\n";
        exit(EXIT_FAILURE); // ���������� �������� � ����� �������
    }
    else {
        whole = value;
    }
}

void Fraction::setFractional(unsigned short value) {
    if (value > USHRT_MAX) {
        cout << "Error: Value exceeds maximum for unsigned short (65535). Terminating program.\n";
        exit(EXIT_FAILURE);
    }
    fractional = value;
}


bool Fraction::Init(long wholePart, unsigned short fractionalPart) {
    setWhole(wholePart);
    setFractional(fractionalPart);
    return true;
}

void Fraction::Read() {
    long wholePart;
    unsigned int tempFractional; 

    cout << "Enter whole part: ";
    while (!(cin >> wholePart) || wholePart < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Whole part must be >= 0. Try again: ";
    }
    setWhole(wholePart);

    cout << "Enter fractional part (0-" << USHRT_MAX << "): ";
    while (!(cin >> tempFractional) || tempFractional > USHRT_MAX) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter a number between 0 and " << USHRT_MAX << ": ";
    }
    setFractional(static_cast<unsigned short>(tempFractional));
}


void Fraction::Display() const {
    cout << toString() << endl;
}

std::string Fraction::toString() const {
    stringstream ss;
    ss << whole << "."
        << setw(5) << setfill('0') << fractional; // 5 digits for USHRT_MAX
    return ss.str();
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

    resultFraction.whole = static_cast<long>(result);

    double fractionalPart = std::abs(result - resultFraction.whole);
    resultFraction.fractional = static_cast<unsigned short>(fractionalPart * 100000 + 0.5);

    return resultFraction;
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

Fraction makeFraction(long wholePart, unsigned short fractionalPart) {
    Fraction obj;
    if (!obj.Init(wholePart, fractionalPart)) {
        cout << "Error: Invalid arguments for Fraction (fractional part must be between 0 and "
            << numeric_limits<unsigned short>::max() << ").\n";
    }
    return obj;
}