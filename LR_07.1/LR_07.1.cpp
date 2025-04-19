#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <Windows.h>
using namespace std;

int RandomNumber() { return (rand() % 100); }

void print(const vector<int>& a)
{
    for (int i : a)
        cout << i << " ";
    cout << endl;
}

int findMaxOdd(const vector<int>& v)
{
    vector<int> oddElements;

    for (int element : v)
    {
        if (element % 2 != 0)  // Якщо елемент непарний
            oddElements.push_back(element);
    }

    // Якщо вектор порожній (немає непарних елементів)
    if (oddElements.empty())
        return -1;

    // Знаходимо максимальний елемент
    return *max_element(oddElements.begin(), oddElements.end());
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(unsigned(time(0)));
    int n;
    cout << "n = ? ";
    cin >> n;

    vector<int> v(n);
    generate(v.begin(), v.end(), RandomNumber);

    cout << "Масив: ";
    print(v);

    int result = findMaxOdd(v);
    if (result == -1)
        cout << "У масиві немає непарних елементів" << endl;
    else
        cout << "Найбільший непарний елемент = " << result << endl;

    return 0;
}