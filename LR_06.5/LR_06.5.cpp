#include <iostream>
#include <string>
#include <stdexcept>
#include <utility> 
#include <Windows.h>

using namespace std;

template <typename T>
class Stack {
private:
    T* elements;         
    int capacity;       
    int top_index;      

public:
    Stack(int initial_capacity = 10) {
        if (initial_capacity <= 0) {
            throw invalid_argument("��������� ������ �� ���� ���������");
        }

        try {
            elements = new T[initial_capacity];
            capacity = initial_capacity;
            top_index = -1; 
        }
        catch (const bad_alloc& e) {
            throw runtime_error("������� �������� ���'��: " + string(e.what()));
        }
    }

    // ����������� ���������
    Stack(const Stack<T>& other) {
        try {
            capacity = other.capacity;
            top_index = other.top_index;
            elements = new T[capacity];

            // ��������� ��������
            for (int i = 0; i <= top_index; i++) {
                elements[i] = other.elements[i];
            }
        }
        catch (const bad_alloc& e) {
            throw runtime_error("������� �������� ���'�� �� ��� ���������: " + string(e.what()));
        }
        catch (...) {
            // ��������, ���� ������� ���� ������� �� ��� ���������
            delete[] elements;
            throw;
        }
    }

    // ����������� ����������
    Stack(Stack<T>&& other) noexcept {
        elements = other.elements;
        capacity = other.capacity;
        top_index = other.top_index;

        // �������� ����������� ��'����
        other.elements = nullptr;
        other.capacity = 0;
        other.top_index = -1;
    }

    // ����������
    ~Stack() {
        delete[] elements;
    }

    // �������� ������������ ���������
    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            // ��������� ��������� ��ﳿ
            Stack<T> temp(other);

            // ���� � ���������� ��ﳺ�
            std::swap(elements, temp.elements);
            std::swap(capacity, temp.capacity);
            std::swap(top_index, temp.top_index);
            // ��������� ���� ���� ������� ��� ����� � ���� ������ ��������
        }
        return *this;
    }

    // �������� ��������� �����������
    Stack<T>& operator=(Stack<T>&& other) noexcept {
        if (this != &other) {
            // ��������� �������� �������
            delete[] elements;

            // ���������� ������� � ������ ��'����
            elements = other.elements;
            capacity = other.capacity;
            top_index = other.top_index;

            // �������� ����������� ��'����
            other.elements = nullptr;
            other.capacity = 0;
            other.top_index = -1;
        }
        return *this;
    }

    // ������ ������� �� �����
    void push(const T& value) {
        if (top_index == capacity - 1) {
            // ���� ����������, ������� �����
            try {
                resize(capacity * 2);
            }
            catch (const exception& e) {
                throw runtime_error("�� ������� ������ ����� �����: " + string(e.what()));
            }
        }

        elements[++top_index] = value;
    }

    // �������� ������� � �����
    T pop() {
        if (isEmpty()) {
            throw out_of_range("��������� �������� ������� � ���������� �����");
        }

        return elements[top_index--];
    }

    // ����������� ������ ������� ��� ���������
    T& peek() const {
        if (isEmpty()) {
            throw out_of_range("��������� ����������� ������� ���������� �����");
        }

        return elements[top_index];
    }

    // ���������, �� ���� �������
    bool isEmpty() const {
        return top_index == -1;
    }

    // �������� �������� ����� �����
    int size() const {
        return top_index + 1;
    }

    // �������� ������� ������ �����
    int getCapacity() const {
        return capacity;
    }

    // �������� ����
    void clear() {
        top_index = -1;
    }

private:
    // ������ ����� ����������� ������
    void resize(int new_capacity) {
        if (new_capacity <= capacity) {
            throw invalid_argument("���� ������ �� ���� ������ �� �������");
        }

        try {
            T* new_elements = new T[new_capacity];

            // ��������� �������� ��������
            for (int i = 0; i <= top_index; i++) {
                new_elements[i] = elements[i];
            }

            // �������� ������� ������ �� ��������� ���������
            delete[] elements;
            elements = new_elements;
            capacity = new_capacity;
        }
        catch (const bad_alloc& e) {
            throw runtime_error("������� �������� ���'�� �� ��� ���� ������: " + string(e.what()));
        }
    }
};

// ������� ������� ��� ������������ ���������� ����� Stack
int main() {
	SetConsoleOutputCP(1251); // ������������ ��������� ������ �� Windows
	SetConsoleCP(1251); // ������������ ��������� ����� �� Windows
    cout << "===== ���������� Stack � ����� int =====" << endl;
    try {
        Stack<int> intStack(5);

        cout << "������ ��� ����� �� �����: ";
        for (int i = 1; i <= 10; i++) {
            intStack.push(i);
            cout << i << " ";
        }
        cout << endl;

        cout << "����� �����: " << intStack.size() << endl;
        cout << "������ �����: " << intStack.getCapacity() << endl;
        cout << "������ �������: " << intStack.peek() << endl;

        cout << "��������� ��������: ";
        while (!intStack.isEmpty()) {
            cout << intStack.pop() << " ";
        }
        cout << endl;

        // �������� �������� ������� � ���������� ����� (�� ����������� �������)
        cout << "������ �������� ������� � ���������� �����..." << endl;
        intStack.pop();
    }
    catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }

    cout << "\n===== ���������� Stack � ����� double =====" << endl;
    try {
        Stack<double> doubleStack;

        cout << "������ ����� � ��������� ������ �� �����: ";
        for (int i = 1; i <= 5; i++) {
            double value = i + 0.5;
            doubleStack.push(value);
            cout << value << " ";
        }
        cout << endl;

        // ���������
        cout << "��������� ���� �����..." << endl;
        Stack<double> doubleStackCopy = doubleStack;

        cout << "����� ������������ �����: " << doubleStack.size() << endl;
        cout << "����� ��ﳿ �����: " << doubleStackCopy.size() << endl;

        // �����������, �� �� ����� �����
        cout << "��������� ������� � ������������ �����: " << doubleStack.pop() << endl;
        cout << "����� ������������ ����� ���� ���������: " << doubleStack.size() << endl;
        cout << "����� ��ﳿ ����� (�� �������): " << doubleStackCopy.size() << endl;

        // ����������
        cout << "��������� ���� �����..." << endl;
        Stack<double> doubleStackMoved = move(doubleStackCopy);
        cout << "����� ����������� �����: " << doubleStackMoved.size() << endl;

        // �������� ����������� ���������� ���� (�� ���� �������)
        cout << "���������� ���� ����� ����� �������? " << doubleStackCopy.isEmpty() << endl;

        // �������� ������������ � �������� ������
        cout << "������ �������� ���� � ��'����� ������..." << endl;
        Stack<double> invalidStack(-1);

    }
    catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }

    cout << "\n===== ���������� Stack � ����� string =====" << endl;
    try {
        Stack<string> stringStack;

        string words[] = { "�����", "���", "C++", "�������", "����" };

        cout << "������ ����� �� �����: ";
        for (const auto& word : words) {
            stringStack.push(word);
            cout << word << " ";
        }
        cout << endl;

        cout << "����� �����: " << stringStack.size() << endl;
        cout << "������ �������: " << stringStack.peek() << endl;

        // ���� ��������� ���������
        Stack<string> anotherStringStack;
        anotherStringStack.push("����");

        cout << "����� ������ ����� ����� ����������: " << anotherStringStack.size() << endl;

        anotherStringStack = stringStack;
        cout << "����� ������ ����� ���� ���������: " << anotherStringStack.size() << endl;
        cout << "������ ������� ������ �����: " << anotherStringStack.peek() << endl;

        // �������� �����
        cout << "�������� ������������ �����..." << endl;
        stringStack.clear();
        cout << "����������� ���� �������? " << stringStack.isEmpty() << endl;
        cout << "����� ���� (�� ���������� ��������) �����: " << anotherStringStack.size() << endl;

        // �������� ����������� ������� ���������� �����
        cout << "������ ����������� ������� ���������� �����..." << endl;
        cout << stringStack.peek() << endl;

    }
    catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }

    return 0;
}