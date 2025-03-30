#include "D1.h"

D1::D1(int x, int y, int z) : B1(y), B2(z), d1(x) {}
D1::~D1() {}
void D1::show() const {
    B1::show();
    B2::show();
    std::cout << "D1: d1 = " << d1 << std::endl;
}