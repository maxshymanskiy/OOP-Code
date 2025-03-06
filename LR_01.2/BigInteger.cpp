#include "BigInteger.h"

void BigInteger::setNumber(const string& num) {
    if (num.empty()) {
        cout << "Помилка: порожній рядок" << endl;
        return;
    }

    for (char c : num) {
        if (!isdigit(c)) {
            cout << "Помилка: рядок містить недопустимі символи" << endl;
            return;
        }
    }

    string cleanNum = num;
    while (cleanNum.length() > 1 && cleanNum[0] == '0') {
        cleanNum.erase(0, 1);
    }

    number = cleanNum;
}

bool BigInteger::Init(const string& num) {
    string prevNumber = number;
    setNumber(num);
    if (number == prevNumber && number != num) {
        return false;
    }
    return true;
}

void BigInteger::Read() {
    string input;
    do {
        cout << "Введіть число: ";
        cin >> input;
    } while (!Init(input));
}

void BigInteger::Display() const {
    cout << number << endl;
}

bool BigInteger::operator==(const BigInteger& other) const {
    if (number.length() != other.number.length()) {
        return false;
    }
    return number == other.number;
}

bool BigInteger::operator<(const BigInteger& other) const {
    if (number.length() != other.number.length()) {
        return number.length() < other.number.length();
    }
    return number < other.number;
}

bool BigInteger::operator>(const BigInteger& other) const {
    if (number.length() != other.number.length()) {
        return number.length() > other.number.length();
    }
    return number > other.number;
}

bool BigInteger::operator<=(const BigInteger& other) const {
    return (*this < other) || (*this == other);
}

bool BigInteger::operator>=(const BigInteger& other) const {
    return (*this > other) || (*this == other);
}

bool BigInteger::operator!=(const BigInteger& other) const {
    return !(*this == other);
}

    
BigInteger makeBigInteger(const string& num) {
    BigInteger temp;
    if (!temp.Init(num)) {
        cout << "Помилка: неможливо створити об'єкт з заданими параметрами" << endl;
        exit(1);  
    }
    return temp;
}