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
		cout << "������ " << arr.size << " �������� ������:" << endl;
		for (int i = 0; i < arr.size; i++) {
			cout << "�������[" << i << "] = ";
			is >> arr.data[i];
		}
		return is;
	}
};

// ======================================================================== //
//  �����������
template <class T>
ParameterizedArray<T>::ParameterizedArray(int newSize) {
	if (newSize <= 0) {
		throw exception("����� ������ ������� ���� ����� ����");
	}

	data = new T[size = newSize];

	for (int i = 0; i < size; i++) {
		data[i] = T();
	}
}
//  ���������
template <class T>
ParameterizedArray<T>::ParameterizedArray(const ParameterizedArray& other) {
	data = new T[size = other.size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}
//  �����������
template <class T>
ParameterizedArray<T>::~ParameterizedArray() {
	delete[] data;
}

// ======================================================================== //
template <class T>
T& ParameterizedArray<T>::operator[](int index) {
	if (index < 0 || index >= size) {
		throw exception("������ �������� �� ��� ������");
	}
	return data[index];
}

template <class T>
const T& ParameterizedArray<T>::operator[](int index) const {
	if (index < 0 || index >= size) {
		throw exception("������ �������� �� ��� ������");
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
		cout << "����� 1:" << endl;
		cin >> arr1;

		ParameterizedArray<int> arr2(arr1);
		cout << "����� 2 (���� ������ 1):" << endl;
		cout << arr2 << endl;

		ParameterizedArray<int> arr3(3);
		cout << "����� 3:" << endl;
		cin >> arr3;

		ParameterizedArray<int> arr4(5);
		arr4 = arr1;                          // ������������ ��������� ���������
		cout << "����� 4 (�������� �������� ������ 1):" << endl;
		cout << arr4 << endl;

		// �������� ������������
		cout << "������� ������ 1 �� �������� 2: " << arr1[2] << endl;
		arr1[2] = 100;
		cout << "ϳ��� ���� �������� ������ 1 �� �������� 2: " << arr1 << endl;

		// �������� �������� ���������
		cout << "����� 1 == ����� 2: " << (arr1 == arr2 ? "���" : "ͳ") << endl;
		cout << "����� 1 != ����� 3: " << (arr1 != arr3 ? "���" : "ͳ") << endl;
		cout << "����� 1 < ����� 3: " << (arr1 < arr3 ? "���" : "ͳ") << endl;
		cout << "����� 1 > ����� 3: " << (arr1 > arr3 ? "���" : "ͳ") << endl;

	}
	catch (exception& e) {
		cerr << "�������: " << e.what() << endl;
	}

	return 0;
}