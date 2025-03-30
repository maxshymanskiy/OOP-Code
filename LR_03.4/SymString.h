#pragma once
#include <string>
#include <stdexcept>

class SymString {
protected:
    std::string id;
    std::string value;

    void validateValue(const std::string& val);

public:
    SymString(const std::string& id, const std::string& value);
    std::string getId() const;
    std::string getValue() const;
    void setValue(const std::string& newValue);
    virtual std::string showBin() const;
    friend SymString operator+(const SymString& s1, const SymString& s2);
};