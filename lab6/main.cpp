#include <thread>
#include <iostream>
#include "TZoo.h"
#include "Header.h"


int main()
{
	TZoo myZoo1(10,"London Zoo");
	TZoo myZoo2(10,"NewYork Zoo");

	TAnimal * leo1 = new TLeo("leo1");
	TAnimal * leo2 = new TLeo("leo2");
	TAnimal * tiger = new TTigris("tiger");
	TAnimal * hippo = new THippopotamus("hippo");

	if (!myZoo1.AddNewAnimal(&leo1)) {
		delete leo1;
	}
	if (!myZoo2.AddNewAnimal(&leo2)) {
		delete leo2;
	}
	if (!myZoo1.AddNewAnimal(&tiger)) {
		delete tiger;
	}
	if (!myZoo2.AddNewAnimal(&hippo)) {
		delete hippo;
	}

	for (size_t i = 0; i < 100; ++i)
	{
		myZoo1.Work();
		std::cout << std::endl;
		myZoo2.Work();

		std::cout << std::endl << "-------------------------------------------------" << std::endl;
		if (i == 10) {
			myZoo1.AnimalExchange( 1, myZoo2, 0);
		}
		std::cout << std::endl;

		// поток ждет 1 секунду
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}
