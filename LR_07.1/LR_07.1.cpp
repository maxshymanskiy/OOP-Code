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
        if (element % 2 != 0)  // ���� ������� ��������
            oddElements.push_back(element);
    }

    // ���� ������ ������� (���� �������� ��������)
    if (oddElements.empty())
        return -1;

    // ��������� ������������ �������
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

    cout << "�����: ";
    print(v);

    int result = findMaxOdd(v);
    if (result == -1)
        cout << "� ����� ���� �������� ��������" << endl;
    else
        cout << "��������� �������� ������� = " << result << endl;

    return 0;
}