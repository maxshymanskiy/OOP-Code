#pragma once

#include <cstdlib>
#include <iostream>

class Combination
{
private:
	int first;  // k
	int second; // n (k < n)

public:
	int GetFirst() const { return first; }
	unsigned int GetSecond() const { return second; }
	bool SetFirst(int value);
	bool SetSecond( int value);

	bool Init(int k, int n);
	void Read();
	void Display() const;
	unsigned long long combination() const;
};

Combination makeCombination(int k, int n);