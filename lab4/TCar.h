#pragma once
#include <iostream>
#include <string>

class TCar
{
protected:

	std::string model;
	double max_speed;

public:

	TCar();

	TCar(std::string, double);

	virtual void Print();

};

