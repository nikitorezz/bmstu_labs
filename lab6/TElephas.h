#pragma once
#include "TProboscidea.h"
class TElephas : //dodelat
	public TProboscidea{

public:
	TElephas(const std::string & name)
		:TProboscidea(name) {
	}

	virtual int Live(float time) override {
		std::cout << GetName() << " ";
		if (((int)time % 24 > 7) && ((int)time % 24 < 18)) {
			std::cout << "is walking" << std::endl;
		}
		else if (((int)time % 12 >= 6) && ((int)time % 12 <= 7)) {
			std::cout << "is eating" << std::endl;
		}
		else {
			std::cout << "is sleeping" << std::endl;
		}
		GettingOlder(time);

		if (IsBreedingTime()) {
			if ((rand() % 2) && (rand() % 2) && (rand() % 2) && an_qty[1] > 1) {
				return 2;
			}
		}
		if (GetAge() > 5) {
			return -1;
		}
		return 0;
	}

	virtual int GetClass() {
		return 1;
	}

	virtual bool IsBreedingTime() override {
		return GetAge() > 2;
	}

};
