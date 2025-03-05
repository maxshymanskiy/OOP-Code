#include "Fraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

void Fraction::setFractional(unsigned short value) {
    if (value > numeric_limits<unsigned short>::max()) {
        cout << "Error: Fractional part exceeds maximum value (" << numeric_limits<unsigned short>::max() << ").\n";
        return;
    }
    fractional = value;
}

bool Fraction::Init(long wholePart, unsigned short fractionalPart) {
    if (fractionalPart > numeric_limits<unsigned short>::max()) {
        cout << "Error: Fractional part exceeds maximum value (" << numeric_limits<unsigned short>::max() << ").\n";
        return false;
    }
    whole = wholePart;
    fractional = fractionalPart;
    return true;
}

void Fraction::Read() {
    cout << "Whole part: ";
    while (!(cin >> whole)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Try again: ";
    }

    bool valid = false;
    do {
        cout << "Fractional part (0-" << numeric_limits<unsigned short>::max() << "): ";
        string input;
        cin >> input;

        if (input[0] == '-') {
            cout << "Error: Fractional part cannot be negative. The program will now exit.\n";
            exit(1); // Завершення програми з кодом помилки 1
        }

        bool isAllDigits = true;
        for (char ch : input) {
            if (!isdigit(ch)) {
                isAllDigits = false;
                break;
            }
        }

        if (!isAllDigits) {
            cout << "Error: Fractional part must be a number. Please try again.\n";
            continue;
        }

        unsigned long temp = stoul(input); // Використовуємо unsigned long для перевірки переповнення

        if (temp > numeric_limits<unsigned short>::max()) {
            cout << "Error: Fractional part exceeds maximum value (" << numeric_limits<unsigned short>::max() << ").\n";
            continue;
        }
        fractional = static_cast<unsigned short>(temp);
        valid = true;

    } while (!valid);
}

void Fraction::Display() const {
    cout << toString() << endl;
}

std::string Fraction::toString() const {
    stringstream ss;
    ss << whole << "."
       << setw(5) << setfill('0') << fractional; // 5 digits for USHRT_MAX
    return ss.str();
}

Fraction Fraction::Subtract(const Fraction& other) const {
    Fraction result;
    result.whole = whole - other.whole;
    int fracDiff = fractional - other.fractional;

    if (fracDiff < 0) {
        result.whole -= 1;
        fracDiff += (numeric_limits<unsigned short>::max() + 1); // 65536
    }
    result.fractional = static_cast<unsigned short>(fracDiff);

    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return (whole == other.whole) && (fractional == other.fractional);
}

bool Fraction::operator<(const Fraction& other) const {
    if (whole != other.whole) return whole < other.whole;
    return fractional < other.fractional;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this < other) && !(*this == other);
}

Fraction makeFraction(long wholePart, unsigned short fractionalPart) {
    Fraction obj;
    if (!obj.Init(wholePart, fractionalPart)) {
        cout << "Error: Invalid arguments for Fraction (fractional part must be between 0 and "
             << numeric_limits<unsigned short>::max() << ").\n";
    }
    return obj;
}