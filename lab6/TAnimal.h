#pragma once
#include<iostream>
#include <string>

class TAnimal
{
	std::string Name;
	size_t Age;
protected:
	 int an_qty[7];
public:
	TAnimal();
	TAnimal(const std::string & name);
	/// Используем деструктор по умолчанию
	/// т.к. специальных действия для очистки объектов не требуется
	virtual ~TAnimal() = default;
	/// Абстрактный метод
	/// <param name="time"> Время суток </param>
	virtual int Live(float time) = 0;

	std::string GetName() const;
	size_t GetAge() const;

	virtual bool IsBreedingTime() = 0;

	void GettingOlder(double t);

	virtual int GetClass() = 0;

	void SetAnQty(int[7]);
};
