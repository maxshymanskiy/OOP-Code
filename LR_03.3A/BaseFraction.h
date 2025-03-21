#pragma once
#include <string>
#include <iostream>

class BaseFraction {
private:
    long whole;
    unsigned short fractional;
public:
    BaseFraction(); 
    BaseFraction(long wholePart, unsigned short fractionalPart); 
    BaseFraction(const BaseFraction& other); 

    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }
    bool setWhole(long value);
    bool setFractional(unsigned short value);
    operator double() const { return whole + fractional / 100000.0; }
    operator std::string() const;
    BaseFraction& operator=(const BaseFraction& other);

    friend std::ostream& operator<<(std::ostream& out, const BaseFraction& fraction);
    friend std::istream& operator>>(std::istream& in, BaseFraction& fraction);
};

BaseFraction makeBaseFraction(long wholePart, unsigned short fractionalPart);