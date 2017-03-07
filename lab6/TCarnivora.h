#pragma once
#include "TAnimal.h"
class TCarnivora
	: public TAnimal {
public:
	TCarnivora(const std::string &name) : TAnimal(name) {};
};
