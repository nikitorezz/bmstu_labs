#include <iostream>;
#include <string>

int main() {
	std::string inner;

	while (true)
	{
		std::cout << "Type in string: ";
		getline(std::cin, inner);

		if (inner == "") {
			break;
		}

		if (inner == std::string(inner.rbegin(), inner.rend())) {
			std::cout << " is palindrome" << std::endl;
		}
		else {
			std::cout << " isn't palindrome" << std::endl;
		}
	}
	std::cout << "ended" << std::endl;
	return 0;
}
