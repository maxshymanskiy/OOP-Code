#pragma once
#include <string>
#include <iostream>

class BaseFraction {
private:
    long whole;
    unsigned short fractional;
public:
    BaseFraction(); // Constructor without parameters
    BaseFraction(long wholePart, unsigned short fractionalPart); // Parameterized constructor
    BaseFraction(const BaseFraction& other); // Copy constructor

    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }
    bool setWhole(long value);
    bool setFractional(unsigned short value);
    operator double() const { return whole + fractional / 100000.0; }
    operator std::string() const;
    BaseFraction& operator=(const BaseFraction& other);

    // Friend I/O functions
    friend std::ostream& operator<<(std::ostream& out, const BaseFraction& fraction);
    friend std::istream& operator>>(std::istream& in, BaseFraction& fraction);
};

// Helper function
BaseFraction makeBaseFraction(long wholePart, unsigned short fractionalPart);