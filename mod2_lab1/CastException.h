#include "CastException.h"
#include <algorithm>

bool BoolFromString(const std::string & data)
{
	//std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	std::for_each(data.begin(), data.end(), ::tolower);
	std::string str;
	bool check = true;
	for (int i = 0; i < data.size(); i++)
	{
		if (isalpha(data[i])) {
			check = false;
		}
		str.push_back(tolower(data[i]));
	}

	if (str == "true" || check) {
		return true;
	}
	else if (str == "false" || str == "0") {
		return false;
	} 
	else {
		throw WrongSymbol();
	}
}

int IntFromString(const std::string & data)
{
	int res;
	try {
		res = std::stoi(data);// ty ne proidew
	}
	catch (const std::out_of_range & e){
		throw Owerflow();
	}
	catch (const std::invalid_argument & e) {
		throw WrongSymbol();
	}
	return res;
}

float FloatFromString(const std::string & data)
{
	float res;
	try {
		res = std::stof(data);
	}
	catch (const std::out_of_range & e) {
		throw Owerflow();
	}
	catch (const std::invalid_argument & e) {
		throw WrongSymbol();
	}
	return res;
}


int main()
{
	std::string str1 = "qwerty";
	try {
		int i = IntFromString(str1);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = BoolFromString(str1);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FloatFromString(str1);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str2 = "123";
	try {
		int i = IntFromString(str2);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = BoolFromString(str2);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FloatFromString(str2);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str3 = "-123";
	try {
		int i = IntFromString(str3);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = BoolFromString(str3);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FloatFromString(str3);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}




	std::string str4 = "11111111111111111111111111111111111111111111111111111";
	try {
		float f = FloatFromString(str4);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}
	try {
		int i = IntFromString(str4);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}




	std::string str5 = "true";
	try {
		bool b = BoolFromString(str5);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str6 = "abc123";
	try {
		int i = IntFromString(str6);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = BoolFromString(str6);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FloatFromString(str6);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	system("pause");
	return 0;
}
