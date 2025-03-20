#include "PrivateFraction.h"
#include <cmath>
#include <stdexcept>

using namespace std;

PrivateFraction& PrivateFraction::operator=(const PrivateFraction& other) {
    if (this != &other) {
        BaseFraction::operator=(other);
    }
    return *this;
}

bool operator==(const PrivateFraction& f1, const PrivateFraction& f2) {
    return (f1.getWhole() == f2.getWhole()) && (f1.getFractional() == f2.getFractional());
}

bool operator!=(const PrivateFraction& f1, const PrivateFraction& f2) {
    return !(f1 == f2);
}

bool operator<(const PrivateFraction& f1, const PrivateFraction& f2) {
    if (f1.getWhole() != f2.getWhole()) return f1.getWhole() < f2.getWhole();
    return f1.getFractional() < f2.getFractional();
}

bool operator>(const PrivateFraction& f1, const PrivateFraction& f2) {
    return !(f1 < f2) && !(f1 == f2);
}

bool operator<=(const PrivateFraction& f1, const PrivateFraction& f2) {
    return (f1 < f2) || (f1 == f2);
}

bool operator>=(const PrivateFraction& f1, const PrivateFraction& f2) {
    return (f1 > f2) || (f1 == f2);
}

PrivateFraction& PrivateFraction::operator++() {
    setWhole(getWhole() + 1);
    return *this;
}

PrivateFraction PrivateFraction::operator++(int) {
    PrivateFraction temp = *this;
    setWhole(getWhole() + 1);
    return temp;
}

PrivateFraction& PrivateFraction::operator--() {
    if (getWhole() > 0)
        setWhole(getWhole() - 1);
    return *this;
}

PrivateFraction PrivateFraction::operator--(int) {
    PrivateFraction temp = *this;
    if (getWhole() > 0)
        setWhole(getWhole() - 1);
    return temp;
}

PrivateFraction PrivateFraction::toFraction(double x) {
    PrivateFraction result;
    result.setWhole(static_cast<long>(x));
    result.setFractional(static_cast<unsigned short>((x - result.getWhole()) * 100000));
    return result;
}

PrivateFraction operator+(const PrivateFraction& f1, const PrivateFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 + val2;

    PrivateFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PrivateFraction operator-(const PrivateFraction& f1, const PrivateFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 - val2;

    PrivateFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PrivateFraction operator*(const PrivateFraction& f1, const PrivateFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 * val2;

    PrivateFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PrivateFraction operator/(const PrivateFraction& f1, const PrivateFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    if (val2 == 0) {
        throw std::invalid_argument("Ділення на нуль");
    }
    double result = val1 / val2;

    PrivateFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

ostream& operator<<(ostream& out, const PrivateFraction& fraction) {
    out << static_cast<string>(fraction);
    return out;
}

istream& operator>>(istream& in, PrivateFraction& fraction) {
    long wholePart;
    unsigned int tempFractional;

    cout << "Введіть цілу частину: ";
    in >> wholePart;

    cout << "Введіть дробову частину: ";
    in >> tempFractional;

    fraction.setWhole(wholePart);
    fraction.setFractional(static_cast<unsigned short>(tempFractional));

    return in;
}

PrivateFraction makePrivateFraction(long wholePart, unsigned short fractionalPart) {
    return PrivateFraction(wholePart, fractionalPart);
}