#include "Combination.h"
#include <iostream>

using namespace std;

#pragma pack(push, 1)
struct PackedCombination {
    int first;   // k
    int second;  // n (k < n)
};
#pragma pack(pop)

int main() {
    Combination c1;                     // Default constructor
    Combination c2(5, 9);               // Parameterized constructor
    Combination c3 = c2;                // Copy constructor

    cout << "Enter k and n (k < n, both positive): ";
    cin >> c1;
    cout << "c1: " << c1 << endl;

    // Calculate combinations
    cout << "C(n,k) = " << c1.combination() << endl;

    // Increment/Decrement
    cout << "++c1: " << ++c1 << endl;
    cout << "c1++: " << c1++ << " (now: " << c1 << ")" << endl;
    cout << "--c1: " << --c1 << endl;
    cout << "c1--: " << c1-- << " (now: " << c1 << ")" << endl;

    // Sizes of classes
    cout << "Size of Combination (without #pragma pack): " << sizeof(Combination) << endl;
    cout << "Size of PackedCombination: " << sizeof(PackedCombination) << endl;

    return 0;
}