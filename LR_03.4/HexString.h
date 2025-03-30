#pragma once
#include "SymString.h"

class HexString : public SymString {
    void validateHex(const std::string& val);

public:
    HexString(const std::string& id, const std::string& value);
    void setValue(const std::string& newValue);
    std::string showBin() const override;
    friend HexString operator+(const HexString& s1, const HexString& s2);
};