#pragma once
#include <iostream>
#include <sstream>

class Triad {
protected:
    int x, y, z;

public:
    Triad(int x = 0, int y = 0, int z = 0);
    Triad(const Triad& other);

    int getX() const;
    int getY() const;
    int getZ() const;

    void setX(int x);
    void setY(int y);
    void setZ(int z);

    Triad operator+(int num) const;
    Triad operator*(int num) const;
    bool operator==(const Triad& other) const;

    Triad& operator++();
    Triad operator++(int);
    Triad& operator--();
    Triad operator--(int);

    operator std::string() const;

    friend std::istream& operator>>(std::istream& in, Triad& triad);
    friend std::ostream& operator<<(std::ostream& out, const Triad& triad);
};