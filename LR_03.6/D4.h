#pragma once
#include "D2.h"

class D4 : public D2 {
    int d4;
public:
    D4(int x, int y, int z, int w, int v);
    ~D4();
    void show() const;
};