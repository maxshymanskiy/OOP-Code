#pragma once

class Object {
protected:
    static int count; // ��������� �������� ��'����

public:
    Object(); // ����������� �� �������������
    Object(const Object&); // ����������� ���������
    ~Object(); // ����������

    static int getCount(); // ����� ��� ��������� ���������
};