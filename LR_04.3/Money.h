#pragma once
#include "Array.h"
#include <string>

class Money : public Array {
public:
    Money(int size = 2, unsigned char initVal = 0);
    void setDigits(const std::string& digits);
    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Money& m);
    friend std::istream& operator>>(std::istream& is, Money& m);

    virtual Money* add(const Array& other) const override;
};