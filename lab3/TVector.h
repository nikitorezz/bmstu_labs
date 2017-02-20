#pragma once
#include <iostream>;
#include <string>;


class TVector
{
	double* arr;
	int num;

public:
	TVector();

	~TVector();

	TVector(double* arr, int num);

	TVector& operator=(const TVector& vec);

	double operator[](size_t size) const;

	double& operator[](size_t size);

	friend std::ostream & operator<<(std::ostream &, const TVector &);

	int GetLen();

	double GetArr(int pos);
};

double operator*(TVector& a, TVector& b);

std::ostream & operator<<(std::ostream &out, const TVector &vec);
