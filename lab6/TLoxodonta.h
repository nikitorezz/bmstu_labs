#pragma once
#include "TProboscidea.h"
class TLoxodonta : 
	public TProboscidea{

public:
	TLoxodonta(const std::string & name) 
		:TProboscidea(name){
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
			if ((rand() % 15) == 0 && an_qty[5] > 1) {
				return 2;
			}
		}
		if (GetAge() > 10) {
			return -1;
		}
	}


	virtual int GetClass() {
		return 5;
	}

	virtual bool IsBreedingTime() override {
		return GetAge() > 2;
	}

};
