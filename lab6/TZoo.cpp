#include "TZoo.h"
#include "Header.h"

void TZoo::AnimalExchange(int a, TZoo & z2, int b)
{
	std::cout << Animals[a]->GetClass() << " " << z2.Animals[b]->GetClass() << std::endl;
	if (((Animals[a]->GetClass() == 3 || Animals[a]->GetClass() == 2) && (z2.Animals[b]->GetClass() == 3 || z2.Animals[b]->GetClass() == 2)) || ((Animals[a]->GetClass() == 6 || Animals[a]->GetClass() == 4) && (z2.Animals[b]->GetClass() == 6 || z2.Animals[b]->GetClass() == 4)) || ((Animals[a]->GetClass() == 5 || Animals[a]->GetClass() == 1) && (z2.Animals[b]->GetClass() == 5 || z2.Animals[b]->GetClass() == 1))){
		
		TAnimal * temp = Animals[a];
		Animals[a] = z2.Animals[b];
		z2.Animals[b] = temp;
		qty[Animals[a]->GetClass()]++;
		qty[z2.Animals[b]->GetClass()]--;
		Animals[a]->SetAnQty(qty);
		z2.qty[Animals[a]->GetClass()]--;
		z2.qty[z2.Animals[b]->GetClass()]++;
		z2.Animals[b]->SetAnQty(z2.qty);
	}
	else {
		std::cout << "exchange error" << std::endl;
	}
}

TZoo::TZoo(size_t capacity, std::string n)
	: Capacity(capacity)
	, NumAnimals(0)
	, Time(0)
	, name(n)
{
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals.push_back(*newAnimal);

	int temp = Animals[NumAnimals]->GetClass();

	qty[temp]++;
	Animals[NumAnimals]->SetAnQty(qty);
	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;


	return true;
}

void TZoo::Work()
{
	std::cout << GetName() << " " << (int)Time / 24 << "d" << (int)Time % 24 << "h "<< std::endl;
	for (size_t i = 0; i < Animals.size(); ++i)
	{
		//std::cout << "{animals " << NumAnimals << "}";
		if (Animals[i] != nullptr) {
			std::string t_str;
			TAnimal* temp;
			// Демонстрация работы динамического полиморфизма
			switch (Animals[i]->Live(Time)) {
			case 1:
				t_str = "eleph";
				t_str.append(std::to_string((rand() % 100)));
				temp = new TElephas(t_str);
				AddNewAnimal(&temp);
				break;
			case 2:
				t_str = "giraf";
				t_str.append(std::to_string((rand() % 100)));
				temp = new TGiraffa(t_str);
				AddNewAnimal(&temp);
				break;
			case 3:
				t_str = "hippo";
				t_str.append(std::to_string((rand() % 100)));
				temp = new THippopotamus(t_str);
				AddNewAnimal(&temp);
				break;
			case 4:
				t_str = "leo";
				t_str.append(std::to_string((rand() % 100)));
				temp = new TLeo(t_str);
				AddNewAnimal(&temp);
				break;
			case 5:
				t_str = "loxodont";
				t_str.append(std::to_string((rand() % 100)));
				temp = new TLoxodonta(t_str);
				AddNewAnimal(&temp);
				break;
			case 6:
				t_str = "tiger";
				t_str.append(std::to_string((rand() % 100)));
				temp = new TTigris(t_str);
				AddNewAnimal(&temp);
				break;
			case -1:
				qty[Animals[i]->GetClass()]--;
				Animals.erase(Animals.begin() + i);
				NumAnimals--;
				break;
			default:
				break;
			}
		}
	}
	Time += STEP;
//	if (Time > 24.f)
		//Time -= 24.f;
}


TZoo::~TZoo()
{
	Animals.clear();
}

std::string TZoo::GetName()
{
	return name;
}

int TZoo::GetQty(int i)
{
	return qty[i];
}

void TZoo::DecQty(int i)
{
	qty[i]--;
}
