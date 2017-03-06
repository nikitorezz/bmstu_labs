#include "TMoney.h"



TMoney::TMoney()
	: TPair(){
}

TMoney::TMoney(int f, int s)
	: TPair(f,s){
}

TMoney TMoney::operator+(const TMoney & s)
{
	TMoney n_pair((first + s.first) + (second + s.second) / 100, (second + s.second) % 100);
	return n_pair;
}

TMoney TMoney::operator-(const TMoney & s)
{
	int kop1 = first * 100 + second;
	int kop2 = s.first * 100 + s.second;
	int res = kop1 - kop2;
	TMoney n_pair(res / 100, res - res / 100 * 100);
	return n_pair;
}

double TMoney::operator/(const TMoney &s)
{
	int kop1 = first * 100 + second;
	int kop2 = s.first * 100 + s.second;
	double res = kop1*1.0 / kop2;
	return res;
}

