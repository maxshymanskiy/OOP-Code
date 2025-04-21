#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class A {
protected:
    int x;
public:
    A(int x = 0) {
        this->x = x;
    }

    A(const A& a) {
        this->x = a.x;
    }

    virtual ~A() {}

    int getX() const { return x; }
};

class B : public A {
private:
    int y;
public:
    B(int x = 0, int y = 0) : A(x) {
        this->y = y;
    }

    B(const B& b) : A(b) {
        this->y = b.y;
    }

    void processA(A a) {
        cout << "Обробка об'єкта A з x = " << a.getX() << endl;

        // Перевірка, чи має переданий об'єкт A певне значення
        if (a.getX() > 0) {
            throw string("Виняток: Отримано об'єкт класу A з додатним значенням");
        }
    }

    int getY() const {
        return y;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    A baseObj(5);
    B derivedObj(10, 20);

    try {
        cout << "Виклик методу processA..." << endl;
        derivedObj.processA(baseObj);
        cout << "Метод processA успішно завершено" << endl;
    }
    catch (const string& ex) {
        cout << "Перехоплено виняток типу string: " << ex << endl;
    }
    catch (const A& ex) {
        cout << "Перехоплено виняток типу A з x = " << ex.getX() << endl;
    }
    catch (...) {
        cout << "Перехоплено невідомий виняток" << endl;
    }

    cout << "Програму завершено" << endl;
    return 0;
}