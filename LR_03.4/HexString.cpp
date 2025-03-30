#include "HexString.h"
#include <cctype>
#include <iomanip> 
#include <sstream> 

void HexString::validateHex(const std::string& val) {
    if (val.empty()) return;  
    for (char c : val) {
        if (!std::isxdigit(c)) {
            throw std::invalid_argument("Помилка: '" + std::string(1, c) + "' не є шістнадцятковою цифрою");
        }
    }
}

HexString::HexString(const std::string& id, const std::string& value)
    : SymString(id, value) {  
    validateHex(value);       
}
void HexString::setValue(const std::string& newValue) {
    validateHex(newValue);
    value = newValue;
}

std::string HexString::showBin() const {
    std::string bin;
    for (char c : value) {
        int num = (std::toupper(c) >= 'A') ? (std::toupper(c) - 'A' + 10) : (c - '0');
        for (int i = 3; i >= 0; --i) {
            bin += (num & (1 << i)) ? '1' : '0';
        }
        bin += ' ';
    }
    return bin;
}

HexString operator+(const HexString& s1, const HexString& s2) {
    unsigned long num1 = std::stoul(s1.value, nullptr, 16);
    unsigned long num2 = std::stoul(s2.value, nullptr, 16);
    unsigned long sum = num1 + num2;
    std::stringstream ss;
    ss << std::hex << std::uppercase << sum;
    return HexString(s1.id + "+" + s2.id, ss.str());
}