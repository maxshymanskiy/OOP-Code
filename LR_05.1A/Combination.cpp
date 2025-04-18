#include "Combination.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

Combination::Combination() {
    first = 0;
    second = 0;
}

Combination::Combination(int k, int n) {
    if (k <= 0) {
        throw std::invalid_argument("�������� k �� ���� �������� ������");
    }

    if (n <= 0) {
        throw InvalidSecondException("�������� n �� ���� �������� ������");
    }

    if (k >= n) {
        throw CombinationCustomException("�������� k �� ���� ������ �� n");
    }

    first = k;
    second = n;
}

Combination::Combination(const Combination& c) {
    first = c.first;
    second = c.second;
}

void Combination::SetFirst(int value) {
    if (value <= 0) {
        // �������� �� ���������� (����� ������)
        CombinationNonInheritedException* ex = new CombinationNonInheritedException("�������� k �� ���� �������� ������");
        throw ex;
    }

    if (second > 0 && value >= second) {
        // �������� �� ��������� (������ ������)
        throw InvalidFirstException("�������� k �� ���� ������ �� n");
    }

    first = value;
}

void Combination::SetSecond(int value) {
    if (value <= 0) {
        // ����������� �������
        throw std::invalid_argument("�������� n �� ���� �������� ������");
    }

    if (first > 0 && value <= first) {
        // �������� �� ���������� (������ ������)
        static InvalidSecondException err("�������� n �� ���� ������ �� k");
        throw err;
    }

    second = value;
}

unsigned long long Combination::combination() const {
    if (first < 0 || first > second) {
        throw CombinationCustomException("��������� ��������� C(n,k): k �� � ����� [0,n]");
    }

    if (first == 0 || first == second) {
        return 1;
    }

    int k = first;
    int n = second;

    if (k > n - k) {
        k = n - k;
    }

    unsigned long long result = 1;

    for (int i = 1; i <= k; i++) {
        // �������� �� ������������
        if (result > std::numeric_limits<unsigned long long>::max() / (n - i + 1)) {
            throw CombinationCustomException("������������ ��� ��������� C(n,k)");
        }

        result = result * (n - i + 1) / i;
    }

    return result;
}

Combination::operator std::string() const {
    stringstream ss;
    ss << "k = " << first << ", n = " << second;

    try {
        ss << ", C(n,k) = " << combination();
    }
    catch (const exception& e) {
        ss << " (������� ����������: " << e.what() << ")";
    }
    catch (...) {
        ss << " (������� ������� ����������)";
    }

    return ss.str();
}

Combination& Combination::operator=(const Combination& c) {
    if (this != &c) {
        first = c.first;
        second = c.second;
    }
    return *this;
}

Combination& operator++(Combination& c) {
    int newValue = c.first + 1;
    if (newValue >= c.second) {
        throw CombinationCustomException("ϳ��� ���������� k ����� ������ ��� ����� n");
    }
    c.first = newValue;
    return c;
}

Combination operator++(Combination& c, int) {
    Combination temp(c);
    c.second++;
    return temp;
}

Combination& operator--(Combination& c) {
    int newValue = c.first - 1;
    if (newValue <= 0) {
        throw InvalidFirstException("ϳ��� ���������� k ����� ������ ��� ����� 0");
    }
    c.first = newValue;
    return c;
}

Combination operator--(Combination& c, int) {
    Combination temp(c);
    if (c.second - 1 <= c.first) {
        throw InvalidSecondException("ϳ��� ���������� n ����� ������ ��� ����� k");
    }
    c.second--;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Combination& c) {
    out << string(c);
    return out;
}


std::istream& operator>>(std::istream& in, Combination& c) {
    int k, n;
    cout << " k = "; in >> k;
    cout << " n = "; in >> n;

    if (in.fail()) {
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        throw std::invalid_argument("������� ��������: ������������ ������ �����");
    }

    try {
        if (n > 0) {
            c.SetSecond(n);
        }

        if (k > 0) {
            c.SetFirst(k);
        }
    }
    catch (std::exception& e) {
        throw; // ���������� ������� ���
    }
    catch (CombinationNonInheritedException* e) {
        throw; // ���������� ������� ���
    }

    return in;
}

// ��������� ������� ��� ��������� ��'����
Combination makeCombination(int k, int n) {
    if (k <= 0) {
        throw std::invalid_argument("�������� k �� ���� �������� ������");
    }

    if (n <= 0) {
        throw CombinationCustomException("�������� n �� ���� �������� ������");
    }

    if (k >= n) {
        throw CombinationCustomException("�������� k �� ���� ������ �� n");
    }

    Combination obj;
    obj.SetSecond(n); 
    obj.SetFirst(k);   

    return obj;
}

Combination makeSpecialCombination(int k, int n) {
    if (k == 0 && n == 0) {
        throw CombinationNonInheritedException("������ ��������� �� ������ ���� ���������");
    }

    return Combination(k, n);
}