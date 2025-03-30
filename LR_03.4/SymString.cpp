#include "SymString.h"

void SymString::validateValue(const std::string& val) {
    if (val.empty()) {
        throw std::invalid_argument("Помилка: рядок не може бути порожнім");
    }
}

SymString::SymString(const std::string& id, const std::string& value)
    : id(id), value(value) {
    validateValue(value);
}

std::string SymString::getId() const { return id; }
std::string SymString::getValue() const { return value; }

void SymString::setValue(const std::string& newValue) {
    validateValue(newValue);
    value = newValue;
}

std::string SymString::showBin() const {
    std::string bin;
    for (char c : value) {
        for (int i = 7; i >= 0; --i) {
            bin += (c & (1 << i)) ? '1' : '0';
        }
        bin += ' ';
    }
    return bin;
}

SymString operator+(const SymString& s1, const SymString& s2) {
    return SymString(s1.id + "+" + s2.id, s1.value + s2.value);
}