#pragma once
#include "BaseFraction.h"

class PublicFraction : public BaseFraction {
public:
    PublicFraction() : BaseFraction() {}
    PublicFraction(long wholePart, unsigned short fractionalPart) : BaseFraction(wholePart, fractionalPart) {}
    PublicFraction(const PublicFraction& other) : BaseFraction(other) {}
    PublicFraction(const BaseFraction& base) : BaseFraction(base) {}

    friend bool operator==(const PublicFraction& f1, const PublicFraction& f2);
    friend bool operator!=(const PublicFraction& f1, const PublicFraction& f2);
    friend bool operator<(const PublicFraction& f1, const PublicFraction& f2);
    friend bool operator>(const PublicFraction& f1, const PublicFraction& f2);
    friend bool operator<=(const PublicFraction& f1, const PublicFraction& f2);
    friend bool operator>=(const PublicFraction& f1, const PublicFraction& f2);

    PublicFraction& operator++(); // Prefix increment
    PublicFraction operator++(int); // Postfix increment
    PublicFraction& operator--(); // Prefix decrement
    PublicFraction operator--(int); // Postfix decrement

    friend PublicFraction operator+(const PublicFraction& f1, const PublicFraction& f2);
    friend PublicFraction operator-(const PublicFraction& f1, const PublicFraction& f2);
    friend PublicFraction operator*(const PublicFraction& f1, const PublicFraction& f2);
    friend PublicFraction operator/(const PublicFraction& f1, const PublicFraction& f2);

    static PublicFraction toFraction(double x);
};

PublicFraction makePublicFraction(long wholePart, unsigned short fractionalPart);   