#pragma once
#include "B1.h"
#include "B2.h"

class D1 : public B1, protected B2 {
    int d1;
public:
    D1(int x, int y, int z);
    ~D1();
    void show() const;
};