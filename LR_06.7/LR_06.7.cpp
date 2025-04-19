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

// Базовий клас для предикатів
template <typename T>
class Predicate {
public:
    virtual bool operator()(const T& value) const = 0;
    virtual ~Predicate() {}
};

template <typename T>
class NegativeValuePredicate : public Predicate<T> {
public:
    bool operator()(const T& value) const override {
        return value < 0;
    }
};

template <typename T>
class GreaterThanPredicate : public Predicate<T> {
private:
    T threshold;
public:
    GreaterThanPredicate(T threshold) : threshold(threshold) {}

    bool operator()(const T& value) const override {
        return value > threshold;
    }
};

template <typename T>
class EvenNumberPredicate : public Predicate<T> {
public:
    bool operator()(const T& value) const override {
        return static_cast<int>(round(value)) % 2 == 0;
    }
};

template <typename InputIterator, typename OutputIterator>
OutputIterator reverse_copy(InputIterator first, InputIterator last, OutputIterator result) {
    while (first != last) {
        --last;
        *result = *last;
        ++result;
        if (first == last) break;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator reverse_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred) {
    InputIterator current = last;
    while (current != first) {
        --current;
        if (pred(*current)) {
            *result = *current;
            ++result;
        }
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть розмір масиву: ";
    cin >> n;

    TArray a = new Array::value_type[n];

    for (int i = 0; i < n; i++) {
        a[i] = -50 + rand() % 101; // Випадкові числа від -50 до 50
    }

    cout << "Початковий масив:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    Array c = processArray(a, n);

    cout << "Оброблений масив (оригінальний алгоритм):" << endl;
    cout << c;

    cout << "\n=== Демонстрація нових алгоритмів reverse_copy та reverse_copy_if ===\n";

    // Створюємо масив Array з вхідного масиву для демонстрації нових алгоритмів
    Array inputArray(n);
    for (int i = 0; i < n; i++) {
        inputArray[i] = a[i];
    }

    Array reversedArray(n);
    reverse_copy(inputArray.begin(), inputArray.end(), reversedArray.begin());

    cout << "Масив після reverse_copy:" << endl;
    cout << reversedArray;

    Array negativeArray(n);
    negativeArray.assign(0); // Заповнюємо нулями

    NegativeValuePredicate<Array::value_type> negPred;
    reverse_copy_if(inputArray.begin(), inputArray.end(), negativeArray.begin(), negPred);

    cout << "Масив після reverse_copy_if (тільки від'ємні числа):" << endl;
    cout << negativeArray;

    Array greaterThanTenArray(n);
    greaterThanTenArray.assign(0); // Заповнюємо нулями

    GreaterThanPredicate<Array::value_type> gtPred(10);
    reverse_copy_if(inputArray.begin(), inputArray.end(), greaterThanTenArray.begin(), gtPred);

    cout << "Масив після reverse_copy_if (числа > 10):" << endl;
    cout << greaterThanTenArray;

    Array evenArray(n);
    evenArray.assign(0); // Заповнюємо нулями

    EvenNumberPredicate<Array::value_type> evenPred;
    reverse_copy_if(inputArray.begin(), inputArray.end(), evenArray.begin(), evenPred);

    cout << "Масив після reverse_copy_if (парні числа):" << endl;
    cout << evenArray;

    Array lessThanAvgArray(n);
    lessThanAvgArray.assign(0); // Заповнюємо нулямиї

    Array::value_type sum = 0;
    for (int i = 0; i < n; i++) {
        sum += inputArray[i];
    }
    Array::value_type avg = sum / n;
    cout << "Середнє значення масиву: " << avg << endl;

    auto lessThanAvg = [avg](const Array::value_type& val) {
        return val < avg;
        };

    reverse_copy_if(inputArray.begin(), inputArray.end(), lessThanAvgArray.begin(), lessThanAvg);

    cout << "Масив після reverse_copy_if (числа, менші за середнє):" << endl;
    cout << lessThanAvgArray;

    delete[] a;

    cout << "\nНатисніть Enter для завершення програми...";
    cin.get();
    cin.get();

    return 0;
}