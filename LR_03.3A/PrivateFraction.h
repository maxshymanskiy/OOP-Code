#pragma once
#include "BaseFraction.h"

class PrivateFraction : private BaseFraction {
public:
    PrivateFraction() : BaseFraction() {}
    PrivateFraction(long wholePart, unsigned short fractionalPart) : BaseFraction(wholePart, fractionalPart) {}
    PrivateFraction(const PrivateFraction& other) : BaseFraction(other) {}

    long getWhole() const { return BaseFraction::getWhole(); }
    unsigned short getFractional() const { return BaseFraction::getFractional(); }
    bool setWhole(long value) { return BaseFraction::setWhole(value); }
    bool setFractional(unsigned short value) { return BaseFraction::setFractional(value); }

    operator double() const { return static_cast<double>(static_cast<const BaseFraction&>(*this)); }
    operator std::string() const { return static_cast<std::string>(static_cast<const BaseFraction&>(*this)); }
    PrivateFraction& operator=(const PrivateFraction& other);

    friend bool operator==(const PrivateFraction& f1, const PrivateFraction& f2);
    friend bool operator!=(const PrivateFraction& f1, const PrivateFraction& f2);
    friend bool operator<(const PrivateFraction& f1, const PrivateFraction& f2);
    friend bool operator>(const PrivateFraction& f1, const PrivateFraction& f2);
    friend bool operator<=(const PrivateFraction& f1, const PrivateFraction& f2);
    friend bool operator>=(const PrivateFraction& f1, const PrivateFraction& f2);

    PrivateFraction& operator++(); // Prefix increment
    PrivateFraction operator++(int); // Postfix increment
    PrivateFraction& operator--(); // Prefix decrement
    PrivateFraction operator--(int); // Postfix decrement

    friend PrivateFraction operator+(const PrivateFraction& f1, const PrivateFraction& f2);
    friend PrivateFraction operator-(const PrivateFraction& f1, const PrivateFraction& f2);
    friend PrivateFraction operator*(const PrivateFraction& f1, const PrivateFraction& f2);
    friend PrivateFraction operator/(const PrivateFraction& f1, const PrivateFraction& f2);

    friend std::ostream& operator<<(std::ostream& out, const PrivateFraction& fraction);
    friend std::istream& operator>>(std::istream& in, PrivateFraction& fraction);

    static PrivateFraction toFraction(double x);
};

PrivateFraction makePrivateFraction(long wholePart, unsigned short fractionalPart);