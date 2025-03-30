#pragma once
#include "D2.h"

class D3 : private D2 {
    int d3;
public:
    D3(int x, int y, int z, int w, int v);
    ~D3();
    void show() const;
};