#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

Fraction::Fraction() noexcept : whole(0), fractional(0) {}

Fraction::Fraction(long wholePart, unsigned short fractionalPart) throw(std::invalid_argument) {
    if (fractionalPart > 99999) {
        throw std::invalid_argument("Fractional part must be less than 100000");
    }
    whole = wholePart;
    fractional = fractionalPart;
}

Fraction::Fraction(const Fraction& other) noexcept {
    *this = other;
}

bool Fraction::setWhole(long value) throw(FractionOverflowException) {
    if (value > std::numeric_limits<long>::max() / 2) {
        throw FractionOverflowException("Whole part value too large");
    }

    whole = value;
    return true;
}

bool Fraction::setFractional(unsigned short value) throw(FractionCustomException&, FractionException*) {
    if (value > 99999) {
        static FractionCustomException e("Fractional part must be less than 100000");
        throw e;
    }

    if (value < 0) {
        FractionException* ex = new FractionException("Fractional part cannot be negative");
        throw ex;
    }

    fractional = value;
    return true;
}

Fraction& Fraction::operator=(const Fraction& other) noexcept {
    if (this != &other) {
        whole = other.whole;
        fractional = other.fractional;
    }
    return *this;
}

Fraction::operator std::string() const noexcept {
    stringstream ss;
    ss << whole << "."
        << setw(5) << setfill('0') << fractional; // 5 місць для USHRT_MAX
    return ss.str();
}

Fraction& Fraction::operator++() throw(FractionOverflowException) {
    if (whole == std::numeric_limits<long>::max()) {
        throw FractionOverflowException("Increment would cause overflow");
    }
    whole++;
    return *this;
}

Fraction Fraction::operator++(int) throw(FractionOverflowException) {
    Fraction temp = *this;
    ++(*this); // Використовуємо префіксний інкремент, який вже має перевірку переповнення
    return temp;
}

Fraction& Fraction::operator--() noexcept {
    whole--;
    return *this;
}

Fraction Fraction::operator--(int) noexcept {
    Fraction temp = *this;
    --(*this);
    return temp;
}

bool operator==(const Fraction& f1, const Fraction& f2) noexcept {
    return (f1.whole == f2.whole) && (f1.fractional == f2.fractional);
}

bool operator!=(const Fraction& f1, const Fraction& f2) noexcept {
    return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2) noexcept {
    if (f1.whole != f2.whole) return f1.whole < f2.whole;
    return f1.fractional < f2.fractional;
}

bool operator>(const Fraction& f1, const Fraction& f2) noexcept {
    return !(f1 < f2) && !(f1 == f2);
}

bool operator<=(const Fraction& f1, const Fraction& f2) noexcept {
    return (f1 < f2) || (f1 == f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2) noexcept {
    return (f1 > f2) || (f1 == f2);
}

Fraction operator-(const Fraction& f1, const Fraction& f2) throw(FractionOverflowException, FractionCustomException&, FractionException*) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 - val2;

    if (result > std::numeric_limits<long>::max()) {
        throw FractionOverflowException("Subtraction result too large");
    }

    if (result < std::numeric_limits<long>::min()) {
        static FractionCustomException e("Subtraction result too small");
        throw e;
    }

    double fractional_part = std::abs(result - static_cast<long>(result));
    if (fractional_part > 0.99999) {
        FractionException* ex = new FractionException("Subtraction precision error");
        throw ex;
    }

    Fraction resultFraction;
    long whole_part = static_cast<long>(result);
    fractional_part = std::abs(result - whole_part);

    resultFraction.whole = whole_part;
    resultFraction.fractional = static_cast<unsigned short>(fractional_part * 100000 + 0.5);

    return resultFraction;
}

ostream& operator<<(ostream& out, const Fraction& fraction) noexcept {
    out << string(fraction);
    return out;
}

istream& operator>>(istream& in, Fraction& fraction) throw(std::invalid_argument) {
    long wholePart;
    unsigned int tempFractional;

    cout << "Enter whole part: ";
    in >> wholePart;

    cout << "Enter fractional part: ";
    in >> tempFractional;

    if (tempFractional > 99999) {
        throw std::invalid_argument("Fractional part must be less than 100000");
    }

    fraction.whole = wholePart;
    fraction.fractional = static_cast<unsigned short>(tempFractional);

    return in;
}

Fraction makeFraction(long wholePart, unsigned short fractionalPart) throw(std::invalid_argument, FractionCustomException) {
    if (fractionalPart > 99999) {
        throw std::invalid_argument("Fractional part must be less than 100000");
    }

    if (wholePart > std::numeric_limits<long>::max() / 2) {
        throw FractionCustomException("Whole part value too large");
    }

    return Fraction(wholePart, fractionalPart);
}