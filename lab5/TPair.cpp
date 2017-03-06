#include "TPair.h"



TPair::TPair()
	: first(0)
	, second(0){
}

TPair::TPair(int f, int s)
	: first(f)
	, second(s){
}

void TPair::SetFirst(int f)
{
	first = f;
}

void TPair::SetSecond(int s)
{
	second = s;
}

TPair TPair::operator+(const TPair & s)
{
	TPair n_pair(first + s.first, second + s.second);
	return n_pair;
}

void TPair::Print()
{
	std::cout << "first = " << first << " , second = " << second << std::endl;
}
