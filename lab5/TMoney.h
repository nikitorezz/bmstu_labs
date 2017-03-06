#pragma once
#include "TPair.h"
class TMoney :
	public TPair
{
public:
	TMoney();

	TMoney(int, int);

	TMoney operator+(const TMoney&);

	TMoney operator-(const TMoney&);

	double operator/(const TMoney&);

};
