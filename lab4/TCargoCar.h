#pragma once
#include "TCar.h"
class TCargoCar :
	public TCar
{

	double capacity;

public:
	TCargoCar();

	TCargoCar(std::string name, double speed, double cap);

	void Print() override;
};

