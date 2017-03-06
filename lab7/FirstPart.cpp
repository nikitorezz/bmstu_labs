#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

std::vector<std::string> Create(std::string & inner) {
	std::vector<std::string> res;
	std::string outer;
	for (int i = 0; i < inner.size(); i++) {
		if (isalpha(inner[i])) {
			outer.push_back(inner[i]);
		}
		else if (!outer.empty()) {
			res.push_back(outer);
			outer = "";
		}
	}
	return res;
}

void GetContext(std::vector<std::string> vec, int num, std::string word) {
	std::vector<int> index;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == word) {
			index.push_back(i);
		}
	}
	for (int i = 0; i < index.size(); i++) {
		for (int j = 0, k = num; j < num * 2; j++, k--) {
			if(k==0){
				std::cout << " * ";
			} else if (index[i] - num > 0) {
				std::cout << vec[index[i] - num] << " ";
			}
		}
		std::cout << std::endl;
	}
}

int main() {
	std::string file;
	std::cout << "Type in file path: ";
	getline(std::cin, file);
	std::fstream pF(file);

	std::string search_str;
	std::cout << std::endl << "Type in string: ";
	getline(std::cin, search_str);
	std::transform(search_str.begin(), search_str.end(), search_str.begin(), ::tolower);

	int num;
	std::cout << std::endl << "Type in number of words: ";
	std::cin >> num;
	while (num < 0) {
		std::cout << std::endl << "Type in positive number of words: ";
		std::cin >> num;
	}

	std::string str;
	while (getline(pF, str)) {
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::vector<std::string> vec = Create(str);
		GetContext(vec, num, search_str);

	}
}
