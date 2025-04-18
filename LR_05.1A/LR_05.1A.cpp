#include "Combination.h"
#include <iostream>
#include <sstream>
#include <exception>
#include <Windows.h>

using namespace std;

void unexpectedHandler() {
    std::cerr << "Unexpected exception occurred. Converting to bad_exception." << std::endl;
    throw std::bad_exception();
}

void riskyFunction() noexcept {
    throw std::runtime_error("Risky function error");
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    std::set_unexpected(unexpectedHandler);

    cout << "=== Лабораторна робота №2.1 - Опрацювання винятків ===" << endl << endl;

    try {
        Combination c1(-5, 10);  // Неправильне значення k
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Caught invalid_argument: " << e.what() << std::endl;
    }

    try {
        Combination c1(3, -8);  // Неправильне значення n
    }
    catch (const InvalidSecondException& e) {
        std::cerr << "Caught InvalidSecondException: " << e.what() << std::endl;
    }

    try {
        Combination c1 = makeCombination(5, 3);  // k > n
    }
    catch (const CombinationCustomException& e) {
        std::cerr << "Caught CombinationCustomException: " << e.what() << std::endl;
    }

    // Передача винятків різними способами
    // За значенням
    try {
        throw CombinationCustomException("Error by value");
    }
    catch (CombinationCustomException e) {
        std::cerr << "Caught by value: " << e.what() << std::endl;
    }

    // За посиланням
    try {
        throw CombinationCustomException("Error by reference");
    }
    catch (const CombinationCustomException& e) {
        std::cerr << "Caught by reference: " << e.what() << std::endl;
    }

    // За вказівником
    try {
        throw new CombinationNonInheritedException("Error by pointer");
    }
    catch (CombinationNonInheritedException* e) {
        std::cerr << "Caught by pointer: " << e->getMessage() << std::endl;
        delete e;  // Важливо звільнити пам'ять
    }

    // Власний виняток без успадкування від std::exception
    try {
        Combination c1 = makeSpecialCombination(0, 0);  // Обидва нульові
    }
    catch (const CombinationNonInheritedException& e) {
        std::cerr << "Caught CombinationNonInheritedException: " << e.getMessage() << std::endl;
    }

    // Демонстрація різниці між винятками
    try {
        throw CombinationCustomException("This inherits from std::exception");
    }
    catch (const std::exception& e) {
        std::cerr << "Caught as std::exception: " << e.what() << std::endl;
    }

    try {
        throw CombinationNonInheritedException("This does NOT inherit from std::exception");
    }
    catch (const std::exception& e) {
        std::cerr << "This won't be caught here" << std::endl;
    }
    catch (const CombinationNonInheritedException& e) {
        std::cerr << "Caught CombinationNonInheritedException separately: " << e.getMessage() << std::endl;
    }

    // Обробка bad_exception
    try {
        unexpectedHandler();
    }
    catch (const std::bad_exception& e) {
        std::cerr << "Caught bad_exception: " << e.what() << std::endl;
    }

    cout << "\n=== Стандартні операції та розміри класів ===" << endl;

    try {
        Combination c1;                   
        Combination c2(5, 9);             
        Combination c3 = c2;                

        cout << "c1 (default): " << c1 << endl;
        cout << "c2 (5, 9): " << c2 << endl;
        cout << "c3 (copy of c2): " << c3 << endl;

        cout << "\nВведіть k та n (k < n, обидва додатні):" << endl;
        try {
            cin >> c1;
            cout << "c1 after input: " << c1 << endl;
            cout << "C(n,k) = " << c1.combination() << endl;
        }
        catch (const exception& e) {
            cerr << "Input error: " << e.what() << endl;
        }
        catch (CombinationNonInheritedException* e) {
            cerr << "Input error: " << e->getMessage() << endl;
            delete e;  
        }

        try {
            cout << "\nIncrement/Decrement operations:" << endl;
            cout << "++c2: " << ++c2 << endl;
            cout << "c2++: " << c2++ << " (now: " << c2 << ")" << endl;
            cout << "--c2: " << --c2 << endl;
            cout << "c2--: " << c2-- << " (now: " << c2 << ")" << endl;
        }
        catch (const exception& e) {
            cerr << "Operation error: " << e.what() << endl;
        }

        cout << "\nClass sizes:" << endl;
        cout << "Size of Combination: " << sizeof(Combination) << " bytes" << endl;
        cout << "Size of PackedCombination: " << sizeof(PackedCombination) << " bytes" << endl;
    }
    catch (const exception& e) {
        cerr << "Uncaught error: " << e.what() << endl;
    }
    catch (CombinationNonInheritedException* e) {
        cerr << "Uncaught error: " << e->getMessage() << endl;
        delete e;  
    }
    catch (...) {
        cerr << "Uncaught error of unknown type!" << endl;
    }

    return 0;
}