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
        cout << "������� ��'���� A � x = " << a.getX() << endl;

        // ��������, �� �� ��������� ��'��� A ����� ��������
        if (a.getX() > 0) {
            throw string("�������: �������� ��'��� ����� A � �������� ���������");
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
        cout << "������ ������ processA..." << endl;
        derivedObj.processA(baseObj);
        cout << "����� processA ������ ���������" << endl;
    }
    catch (const string& ex) {
        cout << "����������� ������� ���� string: " << ex << endl;
    }
    catch (const A& ex) {
        cout << "����������� ������� ���� A � x = " << ex.getX() << endl;
    }
    catch (...) {
        cout << "����������� �������� �������" << endl;
    }

    cout << "�������� ���������" << endl;
    return 0;
}