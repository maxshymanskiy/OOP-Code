#include "IntegerSet.h"
#include <iostream>
using namespace std;

int main() {
    //Set A : { 1, 2, 3, 4, 5 }
    //Set B : { 2, 3, 4 }
    IntegerSet a, b;
    cout << "Enter elements for set A (space-separated): ";
    cin >> a;
    cout << "Enter elements for set B (space-separated): ";
    cin >> b;

    cout << "Set A: " << a << endl;
    cout << "Set B: " << b << endl;

    cout << "A is subset of B: " << (a <= b) << endl;
    cout << "A is superset of B: " << (a >= b) << endl;
    cout << "A equals B: " << (a == b) << endl;

    int elem = 5;
    cout << elem << " is in A: " << (elem ^ a) << endl;

    string strA = static_cast<string>(a);
    cout << "String representation of A: " << strA << endl;

    return 0;
}
