#pragma once
#include <string>
#include <iostream>

class Fraction {
private:
    long whole;
    unsigned short fractional;

public:
    Fraction(); // ����������� ��� ���������
    Fraction(long wholePart, unsigned short fractionalPart); // ����������� �����������
    Fraction(const Fraction& other); // ����������� ���������

    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }
    bool setWhole(long value);
    bool setFractional(unsigned short value);

    operator double() const { return whole + fractional / 100000.0; }
    operator std::string() const; // ������������ � ������� �����

    Fraction& operator=(const Fraction& other);

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    Fraction& operator++(); // ���������� ���������
    Fraction operator++(int); // ����������� ���������
    Fraction& operator--(); // ���������� ���������
    Fraction operator--(int); // ����������� ���������

    static Fraction toFraction(double x);

    friend Fraction Subtract(const Fraction& f1, const Fraction& f2);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

Fraction makeFraction(long wholePart, unsigned short fractionalPart);