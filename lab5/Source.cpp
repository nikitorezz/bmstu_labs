#include <iostream>
#include "TMoney.h"

int main() {
	TPair p1(2,30);
	p1.Print();
	p1.SetFirst(4);
	p1.SetSecond(55);
	TPair p2 = p1 + p1;
	p2.Print();

	TMoney m1(3, 30);
	m1.Print();
	TMoney m2(1, 70);
	m2.Print();
	m2 = m2 + m1;
	m2.Print();
	TMoney m3 = m1 - m2;
	m3.Print();
	m2 = m2 + m2;
	std::cout << (m2 / m1);

	system("pause");
	return 0;
}
