#include "Combination.h"

using namespace std;

int main() 
{
	Combination obj;
	obj.Read();
	obj.Display();
	cout << "C(n, k) = " << obj.combination() << endl;

	int k, n;
	cout << "Input value:" << endl;
	cout << "\nEnter k: "; cin >> k;
	cout << "Enter n: "; cin >> n;
	obj = makeCombination(k, n);
	obj.Display();
	cout << "C(n, k) = " << obj.combination() << endl;

	cin.get();
	return 0;
}