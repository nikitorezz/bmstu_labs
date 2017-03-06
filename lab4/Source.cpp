#include "TCargoCar.h"
#include <iostream>

int main() {

	TCar c1("Audi", 200);
	TCargoCar c2("Ford", 140, 1000);

	c1.Print();
	c2.Print();

	system("pause");
	return 0;
}
