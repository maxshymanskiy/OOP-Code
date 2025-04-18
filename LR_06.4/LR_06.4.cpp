#include <exception>
#include <iostream>
#include <windows.h>
#include <winnt.h>
using namespace std;

template <class T>
class ParameterizedArray {
private:
	T* data;
	int size;

public:
	ParameterizedArray(int newSize);
	ParameterizedArray(const ParameterizedArray& other);
	~ParameterizedArray();

	T& operator[](int index);
	const T& operator[](int index) const;

	ParameterizedArray& operator=(const ParameterizedArray& other);

	bool operator==(const ParameterizedArray& other) const;
	bool operator!=(const ParameterizedArray& other) const;
	bool operator<(const ParameterizedArray& other) const;
	bool operator<=(const ParameterizedArray& other) const;
	bool operator>(const ParameterizedArray& other) const;
	bool operator>=(const ParameterizedArray& other) const;

	int getSize() const { return size; }

	friend ostream& operator<<(ostream& os, const ParameterizedArray<T>& arr) {
		for (int i = 0; i < arr.size; i++) {
			os << arr.data[i];
			if (i < arr.size - 1) os << " ";
		}
		return os;
	}

	friend istream& operator>>(istream& is, ParameterizedArray<T>& arr) {
		cout << "Введіть " << arr.size << " елементів масиву:" << endl;
		for (int i = 0; i < arr.size; i++) {
			cout << "елемент[" << i << "] = ";
			is >> arr.data[i];
		}
		return is;
	}
};

// ======================================================================== //
//  Ініціалізації
template <class T>
ParameterizedArray<T>::ParameterizedArray(int newSize) {
	if (newSize <= 0) {
		throw exception("Розмір масиву повинен бути більше нуля");
	}

	data = new T[size = newSize];

	for (int i = 0; i < size; i++) {
		data[i] = T();
	}
}
//  Копіювання
template <class T>
ParameterizedArray<T>::ParameterizedArray(const ParameterizedArray& other) {
	data = new T[size = other.size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}
//  Деструктора
template <class T>
ParameterizedArray<T>::~ParameterizedArray() {
	delete[] data;
}

// ======================================================================== //
template <class T>
T& ParameterizedArray<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		throw exception("Індекс виходить за межі масиву");
	}
	return data[index];
}

template <class T>
const T& ParameterizedArray<T>::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw exception("Індекс виходить за межі масиву");
	}
	return data[index];
}

template <class T>
ParameterizedArray<T>& ParameterizedArray<T>::operator=(const ParameterizedArray<T>& other) {
	if (this != &other) {
		delete[] data;
		data = new T[size = other.size];
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <class T>
bool ParameterizedArray<T>::operator==(const ParameterizedArray<T>& other) const {
	if (size != other.size) return false;

	for (int i = 0; i < size; i++) {
		if (data[i] != other.data[i]) return false;
	}
	return true;
}

template <class T>
bool ParameterizedArray<T>::operator!=(const ParameterizedArray<T>& other) const {
	return !(*this == other);
}

template <class T>
bool ParameterizedArray<T>::operator<(const ParameterizedArray<T>& other) const {
	int minSize = (size < other.size) ? size : other.size;

	for (int i = 0; i < minSize; i++) {
		if (data[i] < other.data[i]) return true;
		if (data[i] > other.data[i]) return false;
	}

	return size < other.size;
}

template <class T>
bool ParameterizedArray<T>::operator<=(const ParameterizedArray<T>& other) const {
	return (*this < other) || (*this == other);
}

template <class T>
bool ParameterizedArray<T>::operator>(const ParameterizedArray<T>& other) const {
	return other < *this;
}

template <class T>
bool ParameterizedArray<T>::operator>=(const ParameterizedArray<T>& other) const {
	return (*this > other) || (*this == other);
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	try {
		ParameterizedArray<int> arr1(5);
		cout << "Масив 1:" << endl;
		cin >> arr1;

		ParameterizedArray<int> arr2(arr1);
		cout << "Масив 2 (копія масиву 1):" << endl;
		cout << arr2 << endl;

		ParameterizedArray<int> arr3(3);
		cout << "Масив 3:" << endl;
		cin >> arr3;

		ParameterizedArray<int> arr4(5);
		arr4 = arr1;                          // використання оператора присвоєння
		cout << "Масив 4 (присвоєно значення масиву 1):" << endl;
		cout << arr4 << endl;

		// Перевірка індексування
		cout << "Елемент масиву 1 за індексом 2: " << arr1[2] << endl;
		arr1[2] = 100;
		cout << "Після зміни елементу масиву 1 за індексом 2: " << arr1 << endl;

		// Перевірка операцій порівняння
		cout << "Масив 1 == Масив 2: " << (arr1 == arr2 ? "Так" : "Ні") << endl;
		cout << "Масив 1 != Масив 3: " << (arr1 != arr3 ? "Так" : "Ні") << endl;
		cout << "Масив 1 < Масив 3: " << (arr1 < arr3 ? "Так" : "Ні") << endl;
		cout << "Масив 1 > Масив 3: " << (arr1 > arr3 ? "Так" : "Ні") << endl;

	}
	catch (exception& e) {
		cerr << "Помилка: " << e.what() << endl;
	}

	return 0;
}