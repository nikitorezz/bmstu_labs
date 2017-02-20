#include "TVector.h"



TVector::TVector()
{
	num = 0;
	arr = new double[0];
}


TVector::~TVector()
{
	delete[] arr;
}

TVector::TVector(double * in_arr, int in_num)
{
	if (num != 0) {
		delete[] arr;
	}
	num = in_num;
	arr = new double[num];
	memcpy(arr, in_arr, num*sizeof(double));
}

TVector & TVector::operator=(const TVector & vec)
{
	delete[] arr;
	num = vec.num;
	arr = new double[num];
	memcpy(arr, vec.arr, num * sizeof(double));
	return *this;
}

double TVector::operator[](size_t pos) const
{
	return arr[pos];
}

double & TVector::operator[](size_t pos)
{
	return arr[pos];
}

int TVector::GetLen()
{
	return num;
}

double TVector::GetArr(int pos)
{
	return arr[pos];
}

double operator*(TVector & a, TVector & b)
{
	if(a.GetLen() != b.GetLen()){
		std::cout << "different length of vectors" << std::endl;
		return 0;
	}
	double res = 0;
	for (int i = 0; i < a.GetLen(); i++) {
		res += a.GetArr(i)*b.GetArr(i);
	}
	return res;
}

std::ostream & operator<<(std::ostream & out, const TVector & vec)
{
	if (vec.num == 0) {
		out << "empty vector" << std::endl;
	}
	for (int i = 0; i < vec.num; i++) {
		out << vec.arr[i] << " ";
	}
	out << std::endl;
	return out;
}
