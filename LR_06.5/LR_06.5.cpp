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
            throw invalid_argument("Початкова ємність має бути додатньою");
        }

        try {
            elements = new T[initial_capacity];
            capacity = initial_capacity;
            top_index = -1; 
        }
        catch (const bad_alloc& e) {
            throw runtime_error("Помилка виділення пам'яті: " + string(e.what()));
        }
    }

    // Конструктор копіювання
    Stack(const Stack<T>& other) {
        try {
            capacity = other.capacity;
            top_index = other.top_index;
            elements = new T[capacity];

            // Копіювання елементів
            for (int i = 0; i <= top_index; i++) {
                elements[i] = other.elements[i];
            }
        }
        catch (const bad_alloc& e) {
            throw runtime_error("Помилка виділення пам'яті під час копіювання: " + string(e.what()));
        }
        catch (...) {
            // Очищення, якщо виникла інша помилка під час копіювання
            delete[] elements;
            throw;
        }
    }

    // Конструктор переміщення
    Stack(Stack<T>&& other) noexcept {
        elements = other.elements;
        capacity = other.capacity;
        top_index = other.top_index;

        // Скидання початкового об'єкта
        other.elements = nullptr;
        other.capacity = 0;
        other.top_index = -1;
    }

    // Деструктор
    ~Stack() {
        delete[] elements;
    }

    // Оператор копіювального присвоєння
    Stack<T>& operator=(const Stack<T>& other) {
        if (this != &other) {
            // Створення тимчасової копії
            Stack<T> temp(other);

            // Обмін з тимчасовою копією
            std::swap(elements, temp.elements);
            std::swap(capacity, temp.capacity);
            std::swap(top_index, temp.top_index);
            // Тимчасова копія буде знищена при виході з цієї області видимості
        }
        return *this;
    }

    // Оператор присвоєння переміщенням
    Stack<T>& operator=(Stack<T>&& other) noexcept {
        if (this != &other) {
            // Звільнення поточних ресурсів
            delete[] elements;

            // Переміщення ресурсів з іншого об'єкта
            elements = other.elements;
            capacity = other.capacity;
            top_index = other.top_index;

            // Скидання початкового об'єкта
            other.elements = nullptr;
            other.capacity = 0;
            other.top_index = -1;
        }
        return *this;
    }

    // Додати елемент до стеку
    void push(const T& value) {
        if (top_index == capacity - 1) {
            // Стек заповнений, змінюємо розмір
            try {
                resize(capacity * 2);
            }
            catch (const exception& e) {
                throw runtime_error("Не вдалося змінити розмір стеку: " + string(e.what()));
            }
        }

        elements[++top_index] = value;
    }

    // Видалити елемент зі стеку
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Неможливо видалити елемент з порожнього стеку");
        }

        return elements[top_index--];
    }

    // Переглянути верхній елемент без видалення
    T& peek() const {
        if (isEmpty()) {
            throw out_of_range("Неможливо переглянути елемент порожнього стеку");
        }

        return elements[top_index];
    }

    // Перевірити, чи стек порожній
    bool isEmpty() const {
        return top_index == -1;
    }

    // Отримати поточний розмір стеку
    int size() const {
        return top_index + 1;
    }

    // Отримати поточну ємність стеку
    int getCapacity() const {
        return capacity;
    }

    // Очистити стек
    void clear() {
        top_index = -1;
    }

private:
    // Змінити розмір внутрішнього масиву
    void resize(int new_capacity) {
        if (new_capacity <= capacity) {
            throw invalid_argument("Нова ємність має бути більшою за поточну");
        }

        try {
            T* new_elements = new T[new_capacity];

            // Копіювання існуючих елементів
            for (int i = 0; i <= top_index; i++) {
                new_elements[i] = elements[i];
            }

            // Очищення старого масиву та оновлення вказівників
            delete[] elements;
            elements = new_elements;
            capacity = new_capacity;
        }
        catch (const bad_alloc& e) {
            throw runtime_error("Помилка виділення пам'яті під час зміни розміру: " + string(e.what()));
        }
    }
};

// Головна функція для демонстрації шаблонного класу Stack
int main() {
	SetConsoleOutputCP(1251); // Встановлюємо кодування виводу на Windows
	SetConsoleCP(1251); // Встановлюємо кодування вводу на Windows
    cout << "===== Тестування Stack з типом int =====" << endl;
    try {
        Stack<int> intStack(5);

        cout << "Додаємо цілі числа до стеку: ";
        for (int i = 1; i <= 10; i++) {
            intStack.push(i);
            cout << i << " ";
        }
        cout << endl;

        cout << "Розмір стеку: " << intStack.size() << endl;
        cout << "Ємність стеку: " << intStack.getCapacity() << endl;
        cout << "Верхній елемент: " << intStack.peek() << endl;

        cout << "Видалення елементів: ";
        while (!intStack.isEmpty()) {
            cout << intStack.pop() << " ";
        }
        cout << endl;

        // Спробуємо видалити елемент з порожнього стеку (має згенерувати виняток)
        cout << "Спроба видалити елемент з порожнього стеку..." << endl;
        intStack.pop();
    }
    catch (const exception& e) {
        cout << "Виняток: " << e.what() << endl;
    }

    cout << "\n===== Тестування Stack з типом double =====" << endl;
    try {
        Stack<double> doubleStack;

        cout << "Додаємо числа з плаваючою точкою до стеку: ";
        for (int i = 1; i <= 5; i++) {
            double value = i + 0.5;
            doubleStack.push(value);
            cout << value << " ";
        }
        cout << endl;

        // Копіювання
        cout << "Створюємо копію стеку..." << endl;
        Stack<double> doubleStackCopy = doubleStack;

        cout << "Розмір оригінального стеку: " << doubleStack.size() << endl;
        cout << "Розмір копії стеку: " << doubleStackCopy.size() << endl;

        // Демонструємо, що це окремі стеки
        cout << "Видаляємо елемент з оригінального стеку: " << doubleStack.pop() << endl;
        cout << "Розмір оригінального стеку після видалення: " << doubleStack.size() << endl;
        cout << "Розмір копії стеку (не змінився): " << doubleStackCopy.size() << endl;

        // Переміщення
        cout << "Переміщуємо копію стеку..." << endl;
        Stack<double> doubleStackMoved = move(doubleStackCopy);
        cout << "Розмір переміщеного стеку: " << doubleStackMoved.size() << endl;

        // Спробуємо використати переміщений стек (має бути порожнім)
        cout << "Оригінальна копія стеку тепер порожня? " << doubleStackCopy.isEmpty() << endl;

        // Спробуємо ініціалізувати з недійсною ємністю
        cout << "Спроба створити стек з від'ємною ємністю..." << endl;
        Stack<double> invalidStack(-1);

    }
    catch (const exception& e) {
        cout << "Виняток: " << e.what() << endl;
    }

    cout << "\n===== Тестування Stack з типом string =====" << endl;
    try {
        Stack<string> stringStack;

        string words[] = { "Привіт", "Світ", "C++", "Шаблони", "Стек" };

        cout << "Додаємо рядки до стеку: ";
        for (const auto& word : words) {
            stringStack.push(word);
            cout << word << " ";
        }
        cout << endl;

        cout << "Розмір стеку: " << stringStack.size() << endl;
        cout << "Верхній елемент: " << stringStack.peek() << endl;

        // Тест оператора присвоєння
        Stack<string> anotherStringStack;
        anotherStringStack.push("Тест");

        cout << "Розмір іншого стеку перед присвоєнням: " << anotherStringStack.size() << endl;

        anotherStringStack = stringStack;
        cout << "Розмір іншого стеку після присвоєння: " << anotherStringStack.size() << endl;
        cout << "Верхній елемент іншого стеку: " << anotherStringStack.peek() << endl;

        // Очищення стеку
        cout << "Очищення оригінального стеку..." << endl;
        stringStack.clear();
        cout << "Оригінальний стек порожній? " << stringStack.isEmpty() << endl;
        cout << "Інший стек (має залишитися незмінним) розмір: " << anotherStringStack.size() << endl;

        // Спробуємо переглянути елемент порожнього стеку
        cout << "Спроба переглянути елемент порожнього стеку..." << endl;
        cout << stringStack.peek() << endl;

    }
    catch (const exception& e) {
        cout << "Виняток: " << e.what() << endl;
    }

    return 0;
}