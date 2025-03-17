#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

class Combination {
private:
    int first;  // k
    int second; // n (k < n)

public:
    Combination();                      // Default constructor
    Combination(int k, int n);          // Initialization constructor
    Combination(const Combination& c);  // Copy constructor

    ~Combination() {}

    int GetFirst() const { return first; }
    int GetSecond() const { return second; }
    void SetFirst(int value);
    void SetSecond(int value);

    unsigned long long combination() const;

    operator std::string() const;

    Combination& operator=(const Combination& c);

    friend Combination& operator++(Combination& c);       // Префіксний інкремент
    friend Combination operator++(Combination& c, int);   // Постфіксний інкремент
    friend Combination& operator--(Combination& c);       // Префіксний декремент
    friend Combination operator--(Combination& c, int);   // Постфіксний декремент

    friend std::ostream& operator<<(std::ostream& out, const Combination& c);
    friend std::istream& operator>>(std::istream& in, Combination& c);
};

Combination makeCombination(int k, int n);