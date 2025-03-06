#pragma once
#include <string>

class Fraction {
private:
    long whole;             
    unsigned short fractional;

public:
    long getWhole() const { return whole; }
    unsigned short getFractional() const { return fractional; }

    void setWhole(long value);
    void setFractional(unsigned short value);

    bool Init(long wholePart, unsigned short fractionalPart); 
    void Read();                                              
    void Display() const;                                    
    std::string toString() const;

    friend Fraction Subtract(const Fraction& f1, const Fraction& f2);

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const; 
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const; 
    bool operator>=(const Fraction& other) const;           
};

Fraction makeFraction(long wholePart, unsigned short fractionalPart);
