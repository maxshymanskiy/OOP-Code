#include "Array.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>
#include <Windows.h>
using namespace std;
typedef Array::value_type* TArray;

Array processArray(Array::value_type* arr, int size) {
    Array result(size);

    Array::iterator it = result.begin();
    for (int i = 0; i < size; i++, it++) {
        *it = arr[i];
    }

    Array::value_type max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Заміняємо кожне друге від'ємне число половиною найбільшого числа
    int neg_counter = 0;
    for (int i = 0; i < size; i++) {
        if (result[i] < 0) {
            neg_counter++;
            if (neg_counter % 2 == 0) { // Кожне друге від'ємне число
                result[i] = max_val / 2;
            }
        }
    }

    // Обчислюємо суму та середнє арифметичне за абсолютною величиною
    Array::value_type sum = 0;
    for (int i = 0; i < size; i++) {
        sum += result[i];
    }

    Array::value_type abs_sum = 0;
    for (int i = 0; i < size; i++) {
        abs_sum += abs(result[i]);
    }
    Array::value_type abs_mean = abs_sum / size;

    // Додаємо суму та середнє арифметичне до результуючого масиву
    result.push_back(sum);
    result.push_back(abs_mean);

    return result;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int n;
    cout << "n= "; cin >> n;

    TArray a = new Array::value_type[n];

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = -50 + rand() % 101;
    }

    cout << "Початковий масив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    Array c = processArray(a, n);

    cout << "Оброблений масив:" << endl;
    cout << c;

    delete[] a;
    cin.get();
    cin.get();

    return 0;
}