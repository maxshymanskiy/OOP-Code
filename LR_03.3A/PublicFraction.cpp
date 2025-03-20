#include "PublicFraction.h"
#include <cmath>
#include <stdexcept>

using namespace std;

bool operator==(const PublicFraction& f1, const PublicFraction& f2) {
    return (f1.getWhole() == f2.getWhole()) && (f1.getFractional() == f2.getFractional());
}

bool operator!=(const PublicFraction& f1, const PublicFraction& f2) {
    return !(f1 == f2);
}

bool operator<(const PublicFraction& f1, const PublicFraction& f2) {
    if (f1.getWhole() != f2.getWhole()) return f1.getWhole() < f2.getWhole();
    return f1.getFractional() < f2.getFractional();
}

bool operator>(const PublicFraction& f1, const PublicFraction& f2) {
    return !(f1 < f2) && !(f1 == f2);
}

bool operator<=(const PublicFraction& f1, const PublicFraction& f2) {
    return (f1 < f2) || (f1 == f2);
}

bool operator>=(const PublicFraction& f1, const PublicFraction& f2) {
    return (f1 > f2) || (f1 == f2);
}

PublicFraction& PublicFraction::operator++() {
    setWhole(getWhole() + 1);
    return *this;
}

PublicFraction PublicFraction::operator++(int) {
    PublicFraction temp = *this;
    setWhole(getWhole() + 1);
    return temp;
}

PublicFraction& PublicFraction::operator--() {
    if (getWhole() > 0)
        setWhole(getWhole() - 1);
    return *this;
}

PublicFraction PublicFraction::operator--(int) {
    PublicFraction temp = *this;
    if (getWhole() > 0)
        setWhole(getWhole() - 1);
    return temp;
}

PublicFraction PublicFraction::toFraction(double x) {
    PublicFraction result;
    result.setWhole(static_cast<long>(x));
    result.setFractional(static_cast<unsigned short>((x - result.getWhole()) * 100000));
    return result;
}

PublicFraction operator+(const PublicFraction& f1, const PublicFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 + val2;

    PublicFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PublicFraction operator-(const PublicFraction& f1, const PublicFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 - val2;

    PublicFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PublicFraction operator*(const PublicFraction& f1, const PublicFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    double result = val1 * val2;

    PublicFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PublicFraction operator/(const PublicFraction& f1, const PublicFraction& f2) {
    double val1 = static_cast<double>(f1);
    double val2 = static_cast<double>(f2);
    if (val2 == 0) {
        throw std::invalid_argument("Division by zero");
    }
    double result = val1 / val2;

    PublicFraction resultFraction;
    long whole_part = static_cast<long>(result);
    double fractional_part = std::abs(result - whole_part);

    resultFraction.setWhole(whole_part);
    resultFraction.setFractional(static_cast<unsigned short>(fractional_part * 100000 + 0.5));

    return resultFraction;
}

PublicFraction makePublicFraction(long wholePart, unsigned short fractionalPart) {
    return PublicFraction(wholePart, fractionalPart);
}