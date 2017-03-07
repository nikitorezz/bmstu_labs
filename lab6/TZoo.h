#pragma once
#include "TAnimal.h"
#include <vector>

const float STEP = 1;

class TZoo
{
	//typedef TAnimal * TPtrAnimal;


	/// Звери
	//TPtrAnimal * Animals;

	std::vector<TAnimal *> Animals;

	/// Максимальная вместимость зоопарка
	size_t Capacity;

	/// Количество зверей в зоопарке
	size_t NumAnimals;

	/// Время суток
	float Time;

	std::string name;

protected:

	int qty[7];

public:
	void AnimalExchange(int,TZoo&,int);
	TZoo(size_t capacity, std::string n);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	~TZoo();
	std::string GetName();
	int GetQty(int);
	void DecQty(int);
};
