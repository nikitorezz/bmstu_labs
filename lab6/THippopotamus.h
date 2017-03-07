#pragma once
#include "TArtiodactyla.h"
class THippopotamus : 
	public TArtiodactyla{

	int n;

public:
	THippopotamus(const std::string & name)
		:TArtiodactyla(name) {
	}
	virtual int Live(float time) override {
		std::cout << GetName() << " ";
		if (((int)time % 24 > 11) && ((int)time % 24 < 20)) {
			std::cout << "is walking" << std::endl;
		}
		else if (((int)time % 12 >= 9) && ((int)time % 12 <= 10)) {
			std::cout << "is eating" << std::endl;
		}
		else {
			std::cout << "is sleeping" << std::endl;
		}
		GettingOlder(time);

		if (IsBreedingTime()) {
			if ((rand() % 10) == 0 && an_qty[3] > 1) {
				return 2;
			}
		}
		if (GetAge() > 3) {
			return -1;
		}
		return 0;
	}


	virtual int GetClass() {
		return 3;
	}

	virtual bool IsBreedingTime() override {
		return GetAge() > 1;
	}

};
