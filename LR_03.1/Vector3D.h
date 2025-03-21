#pragma once
#include "Triad.h"

class Vector3D : public Triad {
public:
    Vector3D(int x = 0, int y = 0, int z = 0);
    Vector3D(const Triad& triad);

    Vector3D operator+(const Vector3D& other) const;
    int operator*(const Vector3D& other) const; // Скалярний добуток

	operator std::string() const;

	friend std::istream& operator>>(std::istream& in, Vector3D& vec);
	friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);
};

// Функція для демонстрації принципу підстановки
//Triad createAndModifyTriad(const Triad& triad);