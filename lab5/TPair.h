#pragma once
#include <iostream>

class TPair
{

protected:
	int first;
	int second;

public:
	TPair();

	TPair(int, int);

	void SetFirst(int);

	void SetSecond(int);

	virtual TPair operator+(const TPair&);

	void Print();
};

