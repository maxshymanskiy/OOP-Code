#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

class Matrix {
private:
    int size;  
    int** data; 

    void checkIndex(int i, int j) const; 

public:
    Matrix();                        
    explicit Matrix(int n);            
    Matrix(const Matrix& other);       
    ~Matrix();                         

    int getSize() const;
    void setSize(int newSize);
    int getElement(int i, int j) const;
    void setElement(int i, int j, int value);

    Matrix& operator=(const Matrix& other);  // Оператор присвоєння
    int* operator[](int index);              // Оператор індексування
    const int* operator[](int index) const;  // Оператор індексування (константний)
    explicit operator std::string() const;   // Приведення до рядка

    int norm() const;  

    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend bool operator==(const Matrix& a, const Matrix& b);
    friend bool operator!=(const Matrix& a, const Matrix& b);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& in, Matrix& matrix);
};
