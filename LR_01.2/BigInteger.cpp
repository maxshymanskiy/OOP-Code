#include "BigInteger.h"

void BigInteger::setNumber(const string& num) {
    number = num;
}

bool BigInteger::Init(const string& num) {
    if (num.empty()) {
        cout << "Помилка: порожній рядок" << endl;
        return false;
    }

    for (char c : num) {
        if (!isdigit(c)) {
            cout << "Помилка: рядок містить недопустимі символи" << endl;
            return false;
        }
    }

    string cleanNum = num;
    while (cleanNum.length() > 1 && cleanNum[0] == '0') {
        cleanNum.erase(0, 1);
    }

    number = cleanNum;
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

BigInteger makeBigInteger(const string& num) {
    BigInteger temp;
    if (!temp.Init(num)) {
        cout << "Помилка: неможливо створити об'єкт з заданими параметрами" << endl;
        exit(1);  
    }
    return temp;
}