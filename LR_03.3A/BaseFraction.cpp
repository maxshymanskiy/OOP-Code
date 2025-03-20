#include "BaseFraction.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

BaseFraction::BaseFraction() : whole(0), fractional(0) {}

BaseFraction::BaseFraction(long wholePart, unsigned short fractionalPart) {
    setWhole(wholePart);
    setFractional(fractionalPart);
}

BaseFraction::BaseFraction(const BaseFraction& other) {
    *this = other;
}

bool BaseFraction::setWhole(long value) {
    whole = value;
    return true;
}

bool BaseFraction::setFractional(unsigned short value) {
    if (value < 0) {
        cout << "Error: Whole part cannot be negative.\n";
        return false;
    }
    fractional = value;
    return true;
}

BaseFraction& BaseFraction::operator=(const BaseFraction& other) {
    if (this != &other) {
        whole = other.whole;
        fractional = other.fractional;
    }
    return *this;
}

BaseFraction::operator std::string() const {
    stringstream ss;
    ss << whole << "."
        << setw(5) << setfill('0') << fractional;
    return ss.str();
}

ostream& operator<<(ostream& out, const BaseFraction& fraction) {
    out << string(fraction);
    return out;
}

istream& operator>>(istream& in, BaseFraction& fraction) {
    long wholePart;
    unsigned int tempFractional;

    cout << "¬вед≥ть ц≥лу частину: ";
    in >> wholePart;

    cout << "¬вед≥ть дробову частину: ";
    in >> tempFractional;

    fraction.setWhole(wholePart);
    fraction.setFractional(static_cast<unsigned short>(tempFractional));

    return in;
}

BaseFraction makeBaseFraction(long wholePart, unsigned short fractionalPart) {
    return BaseFraction(wholePart, fractionalPart);
}