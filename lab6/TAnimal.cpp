#include "TAnimal.h"

TAnimal::TAnimal()
	: Name()
	, Age(0)
{ }

TAnimal::TAnimal(const std::string & name)
	: Name(name)
	, Age(0)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}

void TAnimal::GettingOlder(double t)
{
	Age = (int)t / 24;
}


void TAnimal::SetAnQty(int arr[7])
{
	for (int i = 1; i < 7; i++) {
		an_qty[i] = arr[i];
	}
}
