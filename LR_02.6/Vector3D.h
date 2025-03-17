#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Vector3D {
public:
    class Triad {
    private:
        int x, y, z;

    public:
        Triad(); // Конструктор за замовчуванням
        Triad(int x, int y, int z); // Конструктор ініціалізації
        Triad(const Triad& other); // Конструктор копіювання

        friend Triad operator+(const Triad& t1, const Triad& t2);
        friend Triad operator*(const Triad& t, int scalar);
        friend bool operator==(const Triad& t1, const Triad& t2);
        friend Triad& operator++(Triad& t);
        friend Triad operator++(Triad& t, int);
        friend Triad& operator--(Triad& t);
        friend Triad operator--(Triad& t, int);
        friend std::istream& operator>>(std::istream& in, Triad& t);
        friend std::ostream& operator<<(std::ostream& out, const Triad& t);

		int getX() const { return x; }
		int getY() const { return y; }
		int getZ() const { return z; }
    };

private:
    Triad triad;

public:
    Vector3D(); // Конструктор за замовчуванням
    Vector3D(const Triad& t); // Конструктор ініціалізації
    Vector3D(const Vector3D& other); // Конструктор копіювання

    Triad getTriad() const { return triad; }
    void setTriad(const Triad& t) { triad = t; }

    friend Vector3D operator+(const Vector3D& v1, const Vector3D& v2);
    friend int operator*(const Vector3D& v1, const Vector3D& v2);
    friend Vector3D& operator++(Vector3D& v);
    friend Vector3D operator++(Vector3D& v, int);
    friend Vector3D& operator--(Vector3D& v);
    friend Vector3D operator--(Vector3D& v, int);
    friend std::istream& operator>>(std::istream& in, Vector3D& v);
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& v);

	
};