#include "Combination.h"

using namespace std;

int main() 
{
    Combination obj;
    obj.Read();
    obj.Display();
    cout << "C(n, k) = " << obj.combination() << endl;

	cin.get();
	return 0;
}	