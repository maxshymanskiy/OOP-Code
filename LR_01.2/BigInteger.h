#pragma once
#include <string>
#include <iostream>

using namespace std;

class BigInteger {
private:
    string number;

public:
    BigInteger() : number("0") {}

    void setNumber(const string& num);
    string getNumber() const { return number; }

    bool Init(const string& num);
    void Read();
    void Display() const;

    bool operator==(const BigInteger& other) const;
    bool operator<(const BigInteger& other) const;
    bool operator>(const BigInteger& other) const;
};

BigInteger makeBigInteger(const string& num);