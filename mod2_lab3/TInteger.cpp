#include "TInteger.h"

TInteger::TInteger()
	:value(0){
}

TInteger::TInteger(int val)
	: value(val){
}

TInteger::operator int()
{
	return value;
}

bool TInteger::Check(int val)
{
	if (val);
	return false;
}

TInteger & TInteger::operator=(const TInteger & rhs)
{
	value = rhs.value;
	return *this;
}

bool TInteger::operator==(const TInteger & rhs)
{
	return value == rhs.value;
}

bool TInteger::operator>(const TInteger & rhs)
{
	return value > rhs.value;
}

bool TInteger::operator>=(const TInteger & rhs)
{
	return value >= rhs.value;
}

TInteger & TInteger::operator+=(const TInteger & rhs)
{
	if ((INT_MAX - rhs.value >= value) && (INT_MIN - rhs.value <= value)) {
		value += rhs.value;
	}
	else {
		throw std::overflow_error("overflow error");
	}
	return *this;
}

TInteger & TInteger::operator-=(const TInteger & rhs)
{
	*this += (-rhs.value);
	return *this;
}

TInteger & TInteger::operator/=(const TInteger & rhs)
{
	value /= rhs.value;
	return *this;
}

TInteger & TInteger::operator*=(const TInteger & rhs)
{
	if ((INT_MAX / rhs.value >= value) && (INT_MIN / rhs.value <= value)) {
		value *= rhs.value;
	}
	else {
		throw std::overflow_error("overflow error");
	}
	return *this;
}

TInteger & TInteger::operator%=(const TInteger & rhs)
{
	value %= rhs.value;
	return *this;
}

std::ostream & operator<<(std::ostream & out, const TInteger & rhs)
{
	out << rhs.value;
	return out;
}

TInteger operator+(const TInteger & a, const TInteger & b)
{
	return TInteger(a)+=b;
}

TInteger operator-(const TInteger & a, const TInteger & b)
{
	return TInteger(a)-=b;
}

TInteger operator*(const TInteger & a, const TInteger & b)
{
	return TInteger(a)*=b;
}

TInteger operator/(const TInteger & a, const TInteger & b)
{
	return TInteger(a)/=b;
}

TInteger operator%(const TInteger & a, const TInteger & b)
{
	return TInteger(a)%b;
}

bool operator!=(const TInteger & a, const TInteger & b)
{
	return !(TInteger(a) == TInteger(b));
}

bool operator<(const TInteger & a, const TInteger & b)
{
	return !(TInteger(a) >= TInteger(b));
}

bool operator<=(const TInteger & a, const TInteger & b)
{
	return !(TInteger(a) > TInteger(b));
}
