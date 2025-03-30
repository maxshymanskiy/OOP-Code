#include "D4.h"

D4::D4(int x, int y, int z, int w, int v) : D2(y, z, w, v), d4(x) {}
D4::~D4() {}
void D4::show() const {
    D2::show();
    std::cout << "D4: d4 = " << d4 << std::endl;
}