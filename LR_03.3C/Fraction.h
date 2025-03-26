#pragma once
#include "Object.h"
#include <string>
#include <iostream>

class Fraction : public Object {
private:
    long whole;
    unsigned short fractional;
public:
    Fraction(); // Default constructor
    Fraction(long wholePart, unsigned short fractionalPart); // Initialization constructor
    Fraction(const Fraction& other); // Copy constructor
    ~Fraction(); // Destructor

    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }
    bool setWhole(long value);
    bool setFractional(unsigned short value);
    operator double() const { return whole + fractional / 100000.0; }
    operator std::string() const;

    Fraction& operator=(const Fraction& other);

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);

    Fraction& operator++(); 
    Fraction operator++(int); 
    Fraction& operator--(); 
    Fraction operator--(int); 

    static Fraction toFraction(double x);

    friend Fraction operator-(const Fraction& f1, const Fraction& f2);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

Fraction makeFraction(long wholePart, unsigned short fractionalPart);