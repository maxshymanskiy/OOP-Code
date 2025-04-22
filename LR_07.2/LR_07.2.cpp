#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <Windows.h>

using namespace std;

int RandomNumber() {
    return rand() % 100 - 50;
}

void printList(const list<int>& lst) {
    cout << "Список: ";
    for (int item : lst) {
        cout << item << " ";
    }
    cout << endl;
}

list<int> createList(int size) {
    list<int> lst(size);
    generate(lst.begin(), lst.end(), RandomNumber);
    return lst;
}

list<int> reverseList(const list<int>& originalList) {
    list<int> reversedList;

     reversedList = originalList;
     reversedList.reverse();

  /*  for (auto it = originalList.begin(); it != originalList.end(); ++it) {
        reversedList.push_front(*it);
    }*/

    return reversedList;
}

int main() {
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251); 
    srand((unsigned int)time(NULL));

    int n;
    cout << "Введіть розмір списку n = ";
    cin >> n;

    list<int> originalList = createList(n);

    cout << "Вихідний ";
    printList(originalList);

    list<int> reversedList = reverseList(originalList);

    cout << "Зворотний ";
    printList(reversedList);

    return 0;
}