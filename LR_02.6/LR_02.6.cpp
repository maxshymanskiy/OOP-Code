#include <iostream>
#include "Vector3D.h"

int main() {
    Vector3D v1, v2;

    std::cout << "Enter the first vector:\n";
    std::cin >> v1;

    std::cout << "Enter the second vector:\n";
    std::cin >> v2;

    std::cout << "\nFirst vector: " << v1 << "\n";
    std::cout << "Second vector: " << v2 << "\n";

    Vector3D sum = v1 + v2;
    std::cout << "\nSum of vectors: " << sum << "\n";

    int scalarProduct = v1 * v2;
    std::cout << "Scalar product: " << scalarProduct << "\n";

    std::cout << "\nTesting increment/decrement:\n";
    std::cout << "Original v1: " << v1 << "\n";
    std::cout << "Prefix ++v1: " << ++v1 << "\n";
    std::cout << "Postfix v1++: " << v1++ << "\n";
    std::cout << "After postfix: " << v1 << "\n";

    std::cout << "Original v2: " << v2 << "\n";
    std::cout << "Prefix --v2: " << --v2 << "\n";
    std::cout << "Postfix v2--: " << v2-- << "\n";
    std::cout << "After postfix: " << v2 << "\n";

    return 0;
}