#include <iostream>
#include "Vector3D.h"

int main() {
    Triad t1(1, 2, 3);
    Vector3D v1(t1);
	std::cout << "Vector3D v1: " << v1 << std::endl;
    Vector3D v2;
    std::cout << "Enter Vector3D v2:\n";
    std::cin >> v2;

    Vector3D v3 = v1 + v2;
    std::cout << "v1 + v2 = " << v3 << std::endl;

    int scalar = v1 * v2;
    std::cout << "v1 * v2 = " << scalar << std::endl;

    std::cout << "v1 before increment: " << v1 << std::endl;
    ++v1;
    std::cout << "++v1: " << v1 << std::endl;
    v1++;
    std::cout << "v1++: " << v1 << std::endl;

    Vector3D v4 = v1;
    std::cout << "v4 = v1: " << v4 << std::endl;

    std::string s = static_cast<std::string>(v4);
    std::cout << "v4 as string: " << s << std::endl;

    // Розміри класів
    std::cout << "Size of Triad: " << sizeof(Triad) << std::endl;
    std::cout << "Size of Vector3D: " << sizeof(Vector3D) << std::endl;

#pragma pack(push, 1)
    std::cout << "Size with #pragma pack(1):" << std::endl;
    std::cout << "Triad: " << sizeof(Triad) << std::endl;
    std::cout << "Vector3D: " << sizeof(Vector3D) << std::endl;
#pragma pack(pop)

    return 0;
}