#include "TCargoCar.h"



TCargoCar::TCargoCar()
	: TCar()
	, capacity(0){
}

TCargoCar::TCargoCar(std::string name, double speed, double cap)
	: TCar(name,speed)
	, capacity(cap){
}

void TCargoCar::Print()
{
	TCar::Print();
	std::cout << ", capacity = " << capacity;
}

