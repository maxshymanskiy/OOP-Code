#pragma once
#include <string>
#include <iostream>

using namespace std;

class BigInteger {
private:
    string number;  

public:
    // Constructors
    BigInteger() : number("0") {}
    BigInteger(const string& num) { setNumber(num); }

    void setNumber(const string& num);
    string getNumber() const { return number; }

    void Read();
    void Display() const;

    bool operator==(const BigInteger& other) const;
    bool operator<(const BigInteger& other) const;
    bool operator>(const BigInteger& other) const;
};