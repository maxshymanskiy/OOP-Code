#include "Combination.h"
#include <iostream>

using namespace std;

void Combination::SetFirst(int value)
{
    first = value;
}
void Combination::SetSecond(int value)
{
    second = value;
}

bool Combination::Init(int k, int n) {
	if (k > 0 && n > 0 && k < n) {
		first = k;
		second = n;
		return true;
	}
	return false;
}

void Combination::Read() {
    int k, n;
    do {
        cout << "Input value:" << endl;
        cout << " k = "; cin >> k;
        cout << " n = "; cin >> n;
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


// Функція створення об'єкта з перевіркою
Combination makeCombination(int k, int n)
{
    Combination obj;
    if (!obj.Init(k, n)) {
        cout << "Error: Invalid arguments for Combination (k must be < n and positive)" << endl;
    }
    return obj;
}
