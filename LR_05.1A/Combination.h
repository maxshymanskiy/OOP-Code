#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

// 1. Винятки-нащадки від стандартних винятків
class InvalidFirstException : public std::invalid_argument {
public:
    InvalidFirstException(const std::string& message) : std::invalid_argument(message) {}
};

class InvalidSecondException : public std::invalid_argument {
public:
    InvalidSecondException(const std::string& message) : std::invalid_argument(message) {}
};

// 2. Винятки-нащадки з власною реалізацією
class CombinationCustomException : public std::exception {
private:
    std::string message;
public:
    CombinationCustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// 3. Власні винятки без успадкування
class CombinationNonInheritedException {
private:
    std::string message;
public:
    CombinationNonInheritedException(const std::string& msg) : message(msg) {}
    const std::string& getMessage() const {
        return message;
    }
};

struct PackedCombination {
    int first;   // k
    int second;  // n (k < n)
};

class Combination {
private:
    int first;   // k
    int second;  // n (k < n)

public:
    Combination();
    Combination(int k, int n);
    Combination(const Combination& c);

    void SetFirst(int value);
    void SetSecond(int value);
    int GetFirst() const { return first; }
    int GetSecond() const { return second; }

    unsigned long long combination() const;

    operator std::string() const;
    Combination& operator=(const Combination& c);

    friend Combination& operator++(Combination& c);
    friend Combination operator++(Combination& c, int);
    friend Combination& operator--(Combination& c);
    friend Combination operator--(Combination& c, int);
    friend std::ostream& operator<<(std::ostream& out, const Combination& c);
    friend std::istream& operator>>(std::istream& in, Combination& c);
};

Combination makeCombination(int k, int n);
Combination makeSpecialCombination(int k, int n);