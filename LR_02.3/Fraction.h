#pragma once
#include <string>
#include <iostream>

class Fraction {
private:
    long whole;
    unsigned short fractional;

public:
    Fraction(); // конструктор без аргументів
    Fraction(long wholePart, unsigned short fractionalPart); // конструктор ініціалізації
    Fraction(const Fraction& other); // конструктор копіювання

    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }
    bool setWhole(long value);
    bool setFractional(unsigned short value);

    operator double() const { return whole + fractional / 100000.0; }
    operator std::string() const; // перетворення у літерний рядок

    Fraction& operator=(const Fraction& other);

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    Fraction& operator++(); // префіксний інкремент
    Fraction operator++(int); // постфіксний інкремент
    Fraction& operator--(); // префіксний декремент
    Fraction operator--(int); // постфіксний декремент

    static Fraction toFraction(double x);

    friend Fraction Subtract(const Fraction& f1, const Fraction& f2);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

Fraction makeFraction(long wholePart, unsigned short fractionalPart);