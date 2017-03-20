#pragma once
#include<iostream>
#include<stdexcept>
#include <limits>


class TInteger{

	int value;

public:
	TInteger();

	TInteger(int val);

	explicit operator int();

	bool Check(int val);

	TInteger& operator=(const TInteger & rhs);

	bool operator==(const TInteger & rhs);

	bool operator>(const TInteger & rhs);

	bool operator>=(const TInteger & rhs);

	TInteger& operator+=(const TInteger & rhs);

	TInteger& operator-=(const TInteger & rhs);

	TInteger& operator/=(const TInteger & rhs);

	TInteger& operator*=(const TInteger & rhs);

	TInteger& operator%=(const TInteger & rhs);

	friend std::ostream & operator<<(std::ostream &, const TInteger &);
};

TInteger operator+(const TInteger & a, const TInteger & b);

TInteger operator-(const TInteger & a, const TInteger & b);

TInteger operator*(const TInteger & a, const TInteger & b);

TInteger operator/(const TInteger & a, const TInteger & b);

TInteger operator%(const TInteger & a, const TInteger & b);

bool operator != (const TInteger & a, const TInteger & b);

bool operator < (const TInteger & a, const TInteger & b);

bool operator <= (const TInteger & a, const TInteger & b);
