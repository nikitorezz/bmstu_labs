#pragma once
#include <iostream>
#include <exception>
#include <string>

class CastException
	: public std::exception {
};

class Owerflow
	: public CastException {

	void what() {
		std::cout << "Ovwerflow exception" << std::endl;;
	}
};

class WrongSymbol
	: public CastException {

	void what() {
		std::cout << "WrongSymbol exception" << std::endl;
	}
};
