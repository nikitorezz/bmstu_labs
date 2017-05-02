#include <iostream>
#include <string>

template<typename t>

void swap(t &a, t &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	int a = 13, b = 1;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	float c = 2.78, d = 3.14;
	swap(c, d);
	std::cout << c << " " << d << std::endl;

	std::string s1 = "qwer";
	std::string s2 = "ty";
	swap(s1, s2);
	std::cout << s1 << " " << s2 << std::endl;

	system("pause");
	return 0;
}
