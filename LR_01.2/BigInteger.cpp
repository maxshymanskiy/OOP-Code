#include "BigInteger.h"

void BigInteger::setNumber(const std::string& num) {
    std::string cleanNum = num;
    while (cleanNum.length() > 1 && cleanNum[0] == '0') {
        cleanNum.erase(0, 1);
    }

    for (char c : cleanNum) {
        if (!isdigit(c)) {
            number = "0";
            return;
        }
    }
    number = cleanNum;
}

void BigInteger::Read() {
    string input;
    cout << "Ведіть велике число: ";
    cin >> input;
    setNumber(input);
}

void BigInteger::Display() const {
    cout << number << std::endl;
}

bool BigInteger::operator==(const BigInteger& other) const {
    return number == other.number;
}

bool BigInteger::operator<(const BigInteger& other) const {
    if (number.length() != other.number.length())
        return number.length() < other.number.length();

    return number < other.number;
}

bool BigInteger::operator>(const BigInteger& other) const {
    return !(*this < other) && !(*this == other);
}