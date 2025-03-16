#include "Combination.h"
#include <iostream>

using namespace std;

bool Combination::SetFirst(int value) {
    if (value < 0) {
        cout << "Error: First value must be non-negative.\n";
        return false;
    }
    first = value;
    return true;
}

bool Combination::SetSecond(int value) {
    if (value < 0 || value <= first) {
        cout << "Error: Second value must be greater than first and non-negative.\n";
        return false;
    }
    second = value;
    return true;
}

bool Combination::Init(int k, int n) {
    return SetFirst(k) && SetSecond(n);
}

void Combination::Read() {
    int k, n;
    do {
        cout << "Input values:\n";
        cout << " k = ";
        cin >> k;
        cout << " n = ";
        cin >> n;
    } while (!Init(k, n));
}

void Combination::Display() const {
	cout << "k = " << first << ", n = " << second << endl;
}

unsigned long long Combination::combination() const {
	unsigned long long result = 1;
	int k = first;
	int n = second;

    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    if (k > n - k) k = n - k;

    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }

    return result;
}

Combination makeCombination(int k, int n)
{
    Combination obj;
    if (!obj.Init(k, n)) {
        cout << "Error: Invalid arguments for Combination (k must be < n and positive)" << endl;
    }
    return obj;
}
