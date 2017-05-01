#include "CastException.h"
#include <algorithm>

template<typename T>
T FromString(const std::string &data);

template<>
bool FromString(const std::string &data) {
	std::for_each(data.begin(), data.end(), ::tolower);
	std::string str;
	bool check = true;
	for (int i = 0; i < data.size(); i++)
	{
		if (isalpha(data[i])) {
			check = false;
		}
		str.push_back(data[i]);
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

template<>
float FromString(const std::string & data) {
	if (data.size() > 12) {
		throw Owerflow();
	}
	std::for_each(data.begin(), data.end(), ::tolower);
	float res = 0;
	bool minus = false;
	int dot = 0;
	if (data[0] == '-') {
		minus = true;
	}
	for (int i = 0; i < data.size(); i++) {
		if (isalpha(data[i])) {
			throw WrongSymbol();
		}
		else if (data[i] == '.') {
			if (dot > 0) {
				throw WrongSymbol();
			}
			dot = i;
		} 
	}

	int i = 0;
	if (minus) {
		++i;
	}

	if (dot - i >= 10) {
		if (dot - i > 10) {
			throw Owerflow();
		}
		else {
			int j = i;
			bool prov = false;
			for (j; j < data.size(); j++) {
				int max[] = {2,1,4,7,4,8,3,6,4,7};
				if (minus) {
					max[9] = 8;
				}			
				if (data[j] - 48 < max[j - i]) {
					break;
				}
				else {
					if (prov) {
						if (data[j] - 48 > max[j - i]) {
							throw Owerflow();
						}
					}
					if (data[j] - 48 == max[j - i]) {
						prov = true;
					}
				}
			}
		}
	}


	for (i; i < data.size(); i++) {
		if (dot == 0) {
			res *= 10;
			res += data[i] - 48;
		}
		else {
			if (i < dot) {
				res *= 10;
				res += data[i] - 48;
			}
			else if(i > dot){
				res += (data[i] - 48)*pow(0.1, i - dot);
			}
		}
	}
	if (minus) {
		return -res;
	}
	return res;
}

template<>
int FromString(const std::string & data) {
	if (data.size() > 11) {
		throw Owerflow();
	}

	bool minus = false;

	if (data[0] == '-') {
		minus = true;
	}

	int i = 0;
	if (minus) {
		++i;
	}

	float tmp = 0;
	for (i; i < data.size(); i++) {
		if (isalpha(data[i])) {
			throw WrongSymbol();
		}
		tmp *= 10;
		tmp += data[i] - 48;
	}
	if (tmp != ((float)((int)tmp))) {
		throw Owerflow();
	}
	return (int)tmp;
}


int main()
{
	std::string str1 = "qwerty";
	try {
		int i = FromString<int>(str1);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = FromString<bool>(str1);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FromString<float>(str1);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str2 = "123";
	try {
		int i = FromString<int>(str2);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = FromString<bool>(str2);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FromString<float>(str2);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str3 = "-123";
	try {
		int i = FromString<int>(str3);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = FromString<bool>(str3);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FromString<float>(str3);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}




	std::string str4 = "11111111111111111111111111111111111111111111111111111";
	try {
		float f = FromString<float>(str4);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}
	try {
		int i = FromString<int>(str4);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}




	std::string str5 = "true";
	try {
		bool b = FromString<bool> (str5);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}



	std::string str6 = "abc123";
	try {
		int i = FromString<int>(str6);
		std::cout << i << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		bool b = FromString<bool>(str6);
		std::cout << b << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	try {
		float f = FromString<float>(str6);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}

	std::string str7 = "-1234.5";
	try {
		float f = FromString<float>(str7);
		std::cout << f << std::endl;
	}
	catch (CastException & e) {
		e.what();
	}
	system("pause");
	return 0;
}
