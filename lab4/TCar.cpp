#include "TCar.h"



TCar::TCar()
	: model("")
	, max_speed(0){
}

TCar::TCar(std::string name, double speed)
	: model(name)
	, max_speed(speed){
}

void TCar::Print()
{
	std::cout << std::endl << "model: " << model << ", max speed = " << max_speed;
}
