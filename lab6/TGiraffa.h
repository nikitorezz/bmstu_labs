#pragma once
#include "TArtiodactyla.h"
class TGiraffa
	: public TArtiodactyla {

public:

	TGiraffa(const std::string &name)
		: TArtiodactyla(name) {
	};

	virtual int Live(float time) override {
		std::cout << GetName() << " ";
		if (((int)time % 24 > 7)&& ((int)time % 24 < 18)) {
			std::cout << "is walking" << std::endl;
		}
		else if (((int)time % 12 >= 6 )&& ((int)time % 12 <= 7)) {
			std::cout << "is eating" << std::endl;
		}
		else {
			std::cout << "is sleeping" << std::endl;
		}
		GettingOlder(time);

		if (IsBreedingTime()) {
			if ((rand() % 2) && (rand() % 2) && (rand() % 2) && (rand() % 2) && (an_qty[2] > 1)) {
				std::cout << "errrrrrrrrr";
				return 2;
			}
		}
		if (GetAge() > 10) {
			return -1;
		}
		return 0;
	}


	virtual int GetClass() {
		return 2;
	}

	virtual bool IsBreedingTime() override{
		return GetAge() > 2;
	}

};



