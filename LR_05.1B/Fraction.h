#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

// 1. Винятки-нащадки від стандартних винятків
class FractionOverflowException : public std::overflow_error {
public:
    FractionOverflowException(const std::string& message)
        : std::overflow_error(message) {}
};

// 2. Власний виняток з успадкуванням від std::exception
class FractionCustomException : public std::exception {
private:
    std::string message;
public:
    FractionCustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// 3. Власний виняток без успадкування
class FractionException {
private:
    std::string message;
public:
    FractionException(const std::string& msg) : message(msg) {}
    const std::string& getMessage() const {
        return message;
    }
};

class Fraction {
private:
    long whole;
    unsigned short fractional;
public:
    Fraction() noexcept;
    Fraction(long wholePart, unsigned short fractionalPart) throw(std::invalid_argument);
    Fraction(const Fraction& other) noexcept;

    long getWhole() const noexcept { return whole; }
    unsigned short getFractional() const noexcept { return fractional; }

    bool setWhole(long value) throw(FractionOverflowException);
    bool setFractional(unsigned short value) throw(FractionCustomException&, FractionException*);

    operator double() const noexcept { return whole + fractional / 100000.0; }
    operator std::string() const noexcept;

    Fraction& operator=(const Fraction& other) noexcept;

    Fraction& operator++() throw(FractionOverflowException); 
    Fraction operator++(int) throw(FractionOverflowException); 
    Fraction& operator--() noexcept; 
    Fraction operator--(int) noexcept; 

    friend bool operator==(const Fraction& f1, const Fraction& f2) noexcept;
    friend bool operator!=(const Fraction& f1, const Fraction& f2) noexcept;
    friend bool operator<(const Fraction& f1, const Fraction& f2) noexcept;
    friend bool operator>(const Fraction& f1, const Fraction& f2) noexcept;
    friend bool operator<=(const Fraction& f1, const Fraction& f2) noexcept;
    friend bool operator>=(const Fraction& f1, const Fraction& f2) noexcept;

    friend Fraction operator-(const Fraction& f1, const Fraction& f2) throw(FractionOverflowException, FractionCustomException&, FractionException*);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) noexcept;
    friend std::istream& operator>>(std::istream& in, Fraction& fraction) throw(std::invalid_argument);
};

Fraction makeFraction(long wholePart, unsigned short fractionalPart) throw(std::invalid_argument, FractionCustomException);