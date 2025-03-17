#pragma once
#include <iostream>
#include <sstream>

class Triad {
private:
    int x, y, z;

public:
    Triad();
    Triad(int x, int y, int z);
    Triad(const Triad& other);

    int getX() const;
    int getY() const;
    int getZ() const;

    void setX(int x);
    void setY(int y);
    void setZ(int z);

    Triad& operator=(const Triad& other);

    friend std::istream& operator>>(std::istream& in, Triad& triad);
    friend std::ostream& operator<<(std::ostream& out, const Triad& triad);

    operator std::string() const;

    friend Triad operator+(const Triad& t, int number);
    friend Triad operator+(int number, const Triad& t);
    friend Triad& operator+=(Triad& t, int number);
    friend Triad operator*(const Triad& t, int number);
    friend Triad operator*(int number, const Triad& t);
    friend Triad& operator*=(Triad& t, int number);
    friend bool operator==(const Triad& t1, const Triad& t2);
    friend Triad operator+(const Triad& t1, const Triad& t2);

    friend Triad& operator++(Triad& t);
    friend Triad operator++(Triad& t, int);
    friend Triad& operator--(Triad& t);
    friend Triad operator--(Triad& t, int);
};